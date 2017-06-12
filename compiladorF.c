
/* -------------------------------------------------------------------
*            Aquivo: compilador.c
* -------------------------------------------------------------------
*              Autor: Bruno Muller Junior
*               Data: 08/2007
*      Atualizado em: [15/03/2012, 08h:22m]
*
* -------------------------------------------------------------------
*
* Funções auxiliares ao compilador
*
* ------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compilador.h"


/* -------------------------------------------------------------------
*  variáveis globais
* ------------------------------------------------------------------- */

FILE* fp=NULL;

void geraCodigo(char* rot, char* comando) {

	if (fp == NULL) {
		fp = fopen("MEPA", "w");
	}

	if (rot == NULL) {
		fprintf(fp, "     %s\n", comando); fflush(fp);
	} else {
		fprintf(fp, "%s: %s \n", rot, comando); fflush(fp);
	}
}

int imprimeErro(char* erro) {
	fprintf (stderr, "Erro na linha %d - %s\n", nl, erro);
	exit(-1);
}

//inicia as variáveis de controle
controle_t *iniciaVariaveisControle() {
	controle_t *controle = (controle_t *) malloc(sizeof(controle_t));

	controle->nivel_lexico = 0;
	controle->deslocamento = 0;
	controle->prox_rotulo = 0;
	controle->saida = (char *) malloc(50);

	controle->tabela_simbolos = criaTabelaSimbolos();
	controle->pilha_proc_func = criaTabelaSimbolos();
	controle->rotulos = criaPilhaRotulos();
	controle->dentro_funcao = 0;
	controle->verificando_param_chamada_funcao = 0;
	controle->eh_booleana = 0;
	controle->tipo_ultima_operacao = indefinido;

	return controle;
}

//cria uma nova tabela de símbolos
tabela_simbolos_t *criaTabelaSimbolos() {

	tabela_simbolos_t *ts = (tabela_simbolos_t *) malloc(sizeof(tabela_simbolos_t));

	ts->tamanho = 20;
	ts->topo = 0;

	ts->simbolos = (simbolo_t **) malloc(ts->tamanho * sizeof(simbolo_t *));

	return ts;
}

//cria um novo símbolo com os dados passados por parâmetro
simbolo_t *criaSimbolo(char *identificador, int deslocamento, int nivel_lexico, categoria_t categoria, tipo_t tipo, char *rotulo, int numero_parametros, int referencia) {
	simbolo_t *simb = (simbolo_t *) malloc(sizeof(simbolo_t));

	simb->identificador = (char *) malloc(50);
	strcpy(simb->identificador, identificador);
	simb->deslocamento = deslocamento;
	simb->nivel_lexico = nivel_lexico;
	simb->categoria = categoria;
	simb->tipo = tipo;
	simb->referencia = referencia;

	if (rotulo != NULL) {
		simb->rotulo = (char *) malloc(strlen(rotulo + 1));
		strcpy(simb->rotulo, rotulo);
		simb->numero_parametros = numero_parametros;
	}

	return simb;
}

//insere símbolo na tabela
void insereTabelaSimbolos(tabela_simbolos_t *ts, simbolo_t *simbolo) {

	if (ts->tamanho == ts->topo) {
		ts->tamanho += 20;
		ts->simbolos = realloc(ts->simbolos, ts->tamanho);
	}

	ts->simbolos[ts->topo++] = simbolo;
}

//remove e retorna o último símbolo inserido
simbolo_t *removeTabelaSimbolos(tabela_simbolos_t *ts) {
	return ts->simbolos[--ts->topo];
}

//busca símbolo e o retorna, caso não encontre retorna NULL
simbolo_t *buscaTabelaSimbolos(tabela_simbolos_t *ts, char *identificador, int nivel_lexico) {
	int i = ts->topo - 1;

	while (i >= 0 && ts->simbolos[i]->nivel_lexico >= nivel_lexico) {
		if (!strcmp(ts->simbolos[i]->identificador, identificador)) {
			return ts->simbolos[i];
		}
		i--;
	}

	return NULL;
}

//gera um rótulo com número passado por parâmetro
char *geraRotulo(int numero) {
	char *rotulo = (char *) malloc(5);

	if (numero < 10) {
		sprintf(rotulo, "R0%d", numero);
	} else {
		sprintf(rotulo, "R%d", numero);
	}

	return rotulo;
}

//inicia uma pilha para armazenar os rótulos
pilha_rotulos_t *criaPilhaRotulos() {
	pilha_rotulos_t *p = (pilha_rotulos_t *) malloc(sizeof(pilha_rotulos_t));

	p->tamanho = 10;
	p->topo = 0;
	p->rotulos = (char **) malloc(p->tamanho * sizeof(char *));

	return p;
}

//empilha um rótulo
void empilhaRotulo(pilha_rotulos_t *pilha, char *rotulo) {

	if (pilha->tamanho == pilha->topo) {
		pilha->tamanho += 10;
		pilha->rotulos = realloc(pilha->rotulos, pilha->tamanho);
	}

	pilha->rotulos[pilha->topo++] = rotulo;
}

//desempilha e retorna o último rótulo empilhado
char *desempilhaRotulo(pilha_rotulos_t *pilha) {
	return pilha->rotulos[--pilha->topo];
}

//remove todas as variáveis do nível léxico passado por parâmetro
int removeVariaveis(tabela_simbolos_t *ts, int nivel_lexico) {

	int i;
	int count = 0;

	if (ts == NULL) {
		return 0;
	}

	if (ts->topo == 0) {
		return 0;
	}

	i = ts->topo - 1;

	while (i >= 0 && ts->simbolos[i]->nivel_lexico > nivel_lexico) {
		ts->topo--;
		i--;
	}

	while (i >= 0 && ts->simbolos[i]->nivel_lexico == nivel_lexico && (ts->simbolos[i]->categoria == variavel_simples || ts->simbolos[i]->categoria == parametro_formal || ts->simbolos[i]->categoria == label)) {
		
		//conta somente as variáveis simples para dar DMEM
		if (ts->simbolos[i]->categoria == variavel_simples) {
			count++;
		}

		ts->topo--;
		i--;
	}

	return count;
}

//completa informações (deslocamento e tipo) dos parâmetros
void corrigeParametros(tabela_simbolos_t *ts, tipo_t tipo, int numero_parametros) {
	int i = ts->topo - 1;
	int deslocamento = -4;
	int count = 0;
	int i_func = ts->topo - 1 - numero_parametros; //i_func recebe índice da função/procedimento

	ts->simbolos[i_func]->numero_parametros = numero_parametros;

	ts->simbolos[i_func]->parametros = (info_parametros_t *) malloc(numero_parametros * sizeof(info_parametros_t));

	while (count < numero_parametros) {
		//seta deslocamento e tipo para cada parâmetro da função/procedimento
		ts->simbolos[i]->deslocamento = deslocamento--;
		ts->simbolos[i]->tipo = tipo;
		i--;
		count++;
	}

	i++;
	count = 0;
	while (count < numero_parametros) {
		/*
		 * Cada função/procedimento tem um vetor "parametros" que guarda as informações,
		 * em ordem, dos seus parâmetros. Aqui embaixo estamos percorrendo todos os parâ-
		 * metros dessa função e preenchendo esse vetor. Isso é utilizado na chamada da
		 * função/procedimento, pois é necessário saber a quantidade de parâmetros, quais
		 * são passados por referência/valor e seus tipos.
		 */
		ts->simbolos[i_func]->parametros[count].tipo = tipo;
		ts->simbolos[i_func]->parametros[count].referencia = ts->simbolos[i]->referencia;

		i++;
		count++;
	}
}

//retorna o número de parâmetros da função ou procedimento que está no topo da tabela de símbolos
int numeroParametrosFuncProcTopo(tabela_simbolos_t *ts) {
	return ts->simbolos[ts->topo - 1]->numero_parametros;
}

//seta deslocamento e tipo de retorno da função
void corrigeFuncao(tabela_simbolos_t *ts, tipo_t tipo, int numero_parametros) {
	int i = ts->topo - 1 - numero_parametros;

	ts->simbolos[i]->tipo = tipo;
	ts->simbolos[i]->deslocamento = -4 - numero_parametros;
}