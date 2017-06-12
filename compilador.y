
// Testar se funciona corretamente o empilhamento de parâmetros
// passados por valor ou por referência.


%{
	#include <stdio.h>
	#include <ctype.h>
	#include <stdlib.h>
	#include <string.h>
	#include "compilador.h"

	int num_vars;
	extern char *yytext;
	controle_t *controle;
	tabela_simbolos_t *pilha_proc_func;

%}

%token 	PROGRAM ABRE_PARENTESES FECHA_PARENTESES 
%token 	VIRGULA PONTO_E_VIRGULA DOIS_PONTOS PONTO
%token 	T_BEGIN T_END VAR IDENT ATRIBUICAO

//tokens adicionados
%token 	INTEGER NUMERO MAIS MENOS OR MULT DIV AND ELSE IF IGUAL THEN
		DIFF MAIOR MAIOR_IGUAL MENOR MENOR_IGUAL WHILE DO PROCEDURE FUNCTION
		READ WRITE GOTO LABEL BOOLEAN TRUE FALSE

%%

programa:
	{
		geraCodigo (NULL, "INPP");
	}
	PROGRAM IDENT
	ABRE_PARENTESES lista_idents FECHA_PARENTESES PONTO_E_VIRGULA
	bloco
	PONTO
	{
		int i = removeVariaveis(controle->tabela_simbolos, controle->nivel_lexico);

		if (i > 0) {
			sprintf(controle->saida, "DMEM %d", i);
			geraCodigo(NULL, controle->saida);
		}
		geraCodigo (NULL, "PARA");
	}
;

bloco:	
	parte_declara_rotulos
	parte_declara_vars
	parte_subrotinas
	comando_composto 
;

parte_declara_rotulos:
	LABEL
	lista_rotulos
	PONTO_E_VIRGULA
	|
;

lista_rotulos:
	lista_rotulos
	VIRGULA
	NUMERO
	{
		controle->rotulo_aux = geraRotulo(controle->prox_rotulo++);
		simbolo_t *simb = criaSimbolo(yytext, 0, controle->nivel_lexico, label, indefinido, controle->rotulo_aux, 0, 0);
		insereTabelaSimbolos(controle->tabela_simbolos, simb);
	}
	|
	NUMERO
	{
		controle->rotulo_aux = geraRotulo(controle->prox_rotulo++);
		simbolo_t *simb = criaSimbolo(yytext, 0, controle->nivel_lexico, label, indefinido, controle->rotulo_aux, 0, 0);
		insereTabelaSimbolos(controle->tabela_simbolos, simb);
	}
;

parte_subrotinas:
	{
		controle->nivel_lexico++;
		controle->deslocamento = 0;
		controle->rotulo_aux = geraRotulo(controle->prox_rotulo++);
		empilhaRotulo(controle->rotulos, controle->rotulo_aux);
		sprintf(controle->saida, "DSVS %s", controle->rotulo_aux);
		geraCodigo(NULL, controle->saida);
	}
	procedimento_funcao
	{
		removeVariaveis(controle->tabela_simbolos, controle->nivel_lexico);
		controle->nivel_lexico--;
		geraCodigo(desempilhaRotulo(controle->rotulos), "NADA");
	}
	parte_subrotinas
	|
;

procedimento_funcao:
	{ controle->dentro_funcao++; }
	PROCEDURE procedimento
	{ controle->dentro_funcao--; }
	|
	{ controle->dentro_funcao++; }
	FUNCTION funcao
	{ controle->dentro_funcao--; }
;

funcao:
	IDENT
	{
		simbolo_t *simb = buscaTabelaSimbolos(controle->tabela_simbolos, yytext, controle->nivel_lexico);
		if (simb != NULL) {
			sprintf(controle->saida, "Funcao '%s' ja existe no nivel lexico %d\n", yytext, controle->nivel_lexico);
			imprimeErro(controle->saida);
		}

		controle->rotulo_aux = geraRotulo(controle->prox_rotulo++);
		simb = criaSimbolo(yytext, 0, controle->nivel_lexico, funcao, indefinido, controle->rotulo_aux, 0, 0);
		insereTabelaSimbolos(controle->tabela_simbolos, simb);

		geraCodigo(controle->rotulo_aux, "NADA");
		sprintf(controle->saida, "ENPR %d", controle->nivel_lexico);
		geraCodigo(NULL, controle->saida);
	}
	parametros_formais_1
	DOIS_PONTOS
	tipo
	PONTO_E_VIRGULA
	{
		corrigeFuncao(controle->tabela_simbolos, controle->tipo, controle->numero_parametros);
	}
	bloco
	{
		int i = removeVariaveis(controle->tabela_simbolos, controle->nivel_lexico);

		if (i > 0) {
			sprintf(controle->saida, "DMEM %d", i);
			geraCodigo(NULL, controle->saida);
		}

		sprintf(controle->saida, "RTPR %d, %d", controle->nivel_lexico, numeroParametrosFuncProcTopo(controle->tabela_simbolos));
		geraCodigo(NULL, controle->saida);
	}
	PONTO_E_VIRGULA
;

procedimento:
	IDENT
	{
		simbolo_t *simb = buscaTabelaSimbolos(controle->tabela_simbolos, yytext, controle->nivel_lexico);
		if (simb != NULL) {
			sprintf(controle->saida, "Procedimento '%s' ja existe no nivel lexico %d\n", yytext, controle->nivel_lexico);
			imprimeErro(controle->saida);
		}

		controle->rotulo_aux = geraRotulo(controle->prox_rotulo++);
		simb = criaSimbolo(yytext, 0, controle->nivel_lexico, procedimento, indefinido, controle->rotulo_aux, 0, 0);
		insereTabelaSimbolos(controle->tabela_simbolos, simb);

		geraCodigo(controle->rotulo_aux, "NADA");
		sprintf(controle->saida, "ENPR %d", controle->nivel_lexico);
		geraCodigo(NULL, controle->saida);
	}
	parametros_formais_1
	PONTO_E_VIRGULA
	bloco
	{
		int i = removeVariaveis(controle->tabela_simbolos, controle->nivel_lexico);

		if (i > 0) {
			sprintf(controle->saida, "DMEM %d", i);
			geraCodigo(NULL, controle->saida);
		}

		sprintf(controle->saida, "RTPR %d, %d", controle->nivel_lexico, numeroParametrosFuncProcTopo(controle->tabela_simbolos));
		geraCodigo(NULL, controle->saida);
	}
	PONTO_E_VIRGULA
;

parametros_formais_1:
	ABRE_PARENTESES
	{
		controle->numero_parametros = 0;
	}
	parametros_formais_2
	{
		corrigeParametros(controle->tabela_simbolos, controle->tipo, controle->numero_parametros);
	}
	FECHA_PARENTESES
	|
;

parametros_formais_2:
	PONTO_E_VIRGULA parametros_formais_3
	| parametros_formais_3
	|
;

parametros_formais_3:
	VAR { controle->referencia = 1; }
	parametros_formais_4 parametros_formais_2
	| { controle->referencia = 0; }
	parametros_formais_4 parametros_formais_2
;

parametros_formais_4:
	lista_parametros DOIS_PONTOS tipo
;

lista_parametros:
	lista_parametros VIRGULA IDENT
	{
		simbolo_t *simb = buscaTabelaSimbolos(controle->tabela_simbolos, yytext, controle->nivel_lexico);
		if (simb != NULL) {
			sprintf(controle->saida, "Parametro '%s' ja existe no nivel lexico %d\n", yytext, controle->nivel_lexico);
			imprimeErro(controle->saida);
		}

		//deslocamento vai com 0 porque nesse ponto ainda não sabemos quantos parâmetros a função tem
		simb = criaSimbolo(yytext, 0, controle->nivel_lexico, parametro_formal, indefinido, NULL, 0, controle->referencia);
		insereTabelaSimbolos(controle->tabela_simbolos, simb);
		controle->numero_parametros++;
	}
	| IDENT
	{
		simbolo_t *simb = buscaTabelaSimbolos(controle->tabela_simbolos, yytext, controle->nivel_lexico);
		if (simb != NULL) {
			sprintf(controle->saida, "Parametro '%s' ja existe no nivel lexico %d\n", yytext, controle->nivel_lexico);
			imprimeErro(controle->saida);
		}

		//deslocamento vai com 0 porque nesse ponto ainda não sabemos quantos parâmetros a função tem
		simb = criaSimbolo(yytext, 0, controle->nivel_lexico, parametro_formal, indefinido, NULL, 0, controle->referencia);
		insereTabelaSimbolos(controle->tabela_simbolos, simb);
		controle->numero_parametros++;
	}
;

parte_declara_vars:
	var
;


var:
	{ }
	VAR declara_vars
	|
;

declara_vars:
	declara_vars declara_var
	| declara_var
;

declara_var:
	{ } 
	lista_id_var DOIS_PONTOS 
	tipo 
	{ /* AMEM */
		int contador = 0;
		int i = controle->tabela_simbolos->topo - 1;

		if (controle->tipo == indefinido) {
			sprintf(controle->saida, "Tipo de variavel invalido\n");
			imprimeErro(controle->saida);
		}

		printf("chegou aqui\n");

		//atualiza todos os símbolos que estão com seu tipo == indefinido
		while (i >= 0 && controle->tabela_simbolos->simbolos[i]->tipo == indefinido && controle->tabela_simbolos->simbolos[i]->categoria == variavel_simples) {
			controle->tabela_simbolos->simbolos[i]->tipo = controle->tipo;
			i--;
			contador++;
		}

		sprintf(controle->saida, "AMEM %d", contador);
		geraCodigo(NULL, controle->saida);
	}
	PONTO_E_VIRGULA
;

tipo:
	INTEGER
	{
		controle->tipo = inteiro;
	}
	|
	BOOLEAN
	{
		controle->tipo = boolean;
	}
;

lista_id_var:
	lista_id_var VIRGULA IDENT 
	{
		/* insere última vars na tabela de símbolos */
		simbolo_t *simb = buscaTabelaSimbolos(controle->tabela_simbolos, yytext, controle->nivel_lexico);
		if (simb != NULL) {
			sprintf(controle->saida, "Variavel '%s' ja existe no nivel lexico %d\n", yytext, controle->nivel_lexico);
			imprimeErro(controle->saida);
		}

		simb = criaSimbolo(yytext, controle->deslocamento++, controle->nivel_lexico, variavel_simples, indefinido, NULL, 0, 0);
		insereTabelaSimbolos(controle->tabela_simbolos, simb);
	}
	|
	IDENT
	{
		/* insere vars na tabela de símbolos */
		simbolo_t *simb = buscaTabelaSimbolos(controle->tabela_simbolos, yytext, controle->nivel_lexico);
		if (simb != NULL) {
			sprintf(controle->saida, "Variavel '%s' ja existe no nivel lexico %d\n", yytext, controle->nivel_lexico);
			imprimeErro(controle->saida);
		}

		simb = criaSimbolo(yytext, controle->deslocamento++, controle->nivel_lexico, variavel_simples, indefinido, NULL, 0, 0);
		insereTabelaSimbolos(controle->tabela_simbolos, simb);
	}
;

lista_idents:
	lista_idents VIRGULA IDENT
	| IDENT
;


comando_composto:
	T_BEGIN
	comandos
	T_END

comandos:
	comando PONTO_E_VIRGULA comandos
	| comando
	|

comando:
	comando_sem_rotulo
	|
	NUMERO
	{
		simbolo_t *simb = buscaTabelaSimbolos(controle->tabela_simbolos, yytext, 0);
		if (simb == NULL) {
			sprintf(controle->saida, "Rotulo '%s' nao foi declarado.\n", yytext);
			imprimeErro(controle->saida);
		}

		geraCodigo(simb->rotulo, "NADA");

		int i = 0;
		int nl = 0;

		while (i < controle->tabela_simbolos->topo) {
			simb = controle->tabela_simbolos->simbolos[i];
			if (simb->categoria == variavel_simples && simb->nivel_lexico == controle->nivel_lexico) {
				nl++;
			}
			i++;
		}

		
		sprintf(controle->saida, "ENRT %d, %d", controle->nivel_lexico, nl);
		geraCodigo(NULL, controle->saida);
	}
	DOIS_PONTOS
	comando_sem_rotulo
;

comando_sem_rotulo:
	atribuicao_procedimento
	| comando_condicional
	| comando_repetitivo
	| comando_composto
	| desvio
	| comando_leitura
	| comando_escrita
;







desvio:
	GOTO NUMERO
	{
		simbolo_t *simb = buscaTabelaSimbolos(controle->tabela_simbolos, yytext, 0);
		if (simb == NULL) {
			sprintf(controle->saida, "Label '%s' nao foi declarado.\n", yytext);
			imprimeErro(controle->saida);
		}

		sprintf(controle->saida, "DSVR %s, %d, %d", simb->rotulo, simb->nivel_lexico, controle->nivel_lexico);
		geraCodigo(NULL, controle->saida);
	}
;

comando_leitura:
	READ
	ABRE_PARENTESES
	parametros_leitura
	FECHA_PARENTESES
;

parametros_leitura:
	parametros_leitura VIRGULA identificador_leitura
	| identificador_leitura
;

identificador_leitura:
	IDENT
	{
		simbolo_t *simb = buscaTabelaSimbolos(controle->tabela_simbolos, yytext, 0);
		if (simb == NULL) {
			sprintf(controle->saida, "identificador '%s' nao declarado.", yytext);
			imprimeErro(controle->saida);
		}

		if (simb->categoria == variavel_simples || simb->categoria == funcao ||
				(simb->categoria == parametro_formal && !simb->referencia)) {
			sprintf(controle->saida, "ARMZ %d, %d", simb->nivel_lexico, simb->deslocamento);
		} else if (simb->categoria == parametro_formal && simb->referencia) {
			sprintf(controle->saida, "ARMI %d, %d", simb->nivel_lexico, simb->deslocamento);
		}

		geraCodigo(NULL, "LEIT");
		geraCodigo(NULL, controle->saida);
	}
;

comando_escrita:
	WRITE
	ABRE_PARENTESES
	parametros_escrita
	FECHA_PARENTESES
;

parametros_escrita:
	parametros_escrita VIRGULA expressao
	{
		geraCodigo(NULL, "IMPR");
	}
	| expressao
	{
		geraCodigo(NULL, "IMPR");
	}
;


comando_repetitivo:
	WHILE apos_inicio_while expressao apos_expressao_while DO T_BEGIN
	comandos
	T_END apos_end_while
	|
	WHILE apos_inicio_while expressao apos_expressao_while DO
	comando apos_end_while
;

apos_inicio_while:
	{
		controle->rotulo_aux = geraRotulo(controle->prox_rotulo++);
		empilhaRotulo(controle->rotulos, controle->rotulo_aux);
		geraCodigo(controle->rotulo_aux, "NADA");
	}
;

apos_expressao_while:
	{
		controle->rotulo_aux = geraRotulo(controle->prox_rotulo++);
		empilhaRotulo(controle->rotulos, controle->rotulo_aux);
		sprintf(controle->saida, "DSVF %s", controle->rotulo_aux);
		geraCodigo(NULL, controle->saida);
	}
;

apos_end_while:
	{
		controle->rotulo_aux = desempilhaRotulo(controle->rotulos);

		sprintf(controle->saida, "DSVS %s", desempilhaRotulo(controle->rotulos));
		geraCodigo(NULL, controle->saida);

		geraCodigo(controle->rotulo_aux, "NADA");
	}
;

comando_condicional:
	{
		controle->eh_booleana = 0;
	}
	if
	else
	{
		geraCodigo(desempilhaRotulo(controle->rotulos), "NADA");
	}
;

if:
	IF expressao apos_expressao_if THEN
	T_BEGIN comandos T_END apos_comandos_if
	|
	IF expressao apos_expressao_if THEN
	comando_sem_rotulo apos_comandos_if
;

apos_expressao_if:
	{
		if (controle->eh_booleana == 0) {
			sprintf(controle->saida, "Esperava expressao booleana.\n");
    		imprimeErro(controle->saida);
		}
		controle->rotulo_aux = geraRotulo(controle->prox_rotulo++);
		empilhaRotulo(controle->rotulos, controle->rotulo_aux);
		sprintf(controle->saida, "DSVF %s", controle->rotulo_aux);
		geraCodigo(NULL, controle->saida);
	}
;

apos_comandos_if:
	{
		controle->rotulo_aux = geraRotulo(controle->prox_rotulo++);
		sprintf(controle->saida, "DSVS %s", controle->rotulo_aux);
		geraCodigo(NULL, controle->saida);

		geraCodigo(desempilhaRotulo(controle->rotulos), "NADA");

		empilhaRotulo(controle->rotulos, controle->rotulo_aux);
	}
;

else:
	ELSE T_BEGIN comandos T_END
	| ELSE comando_sem_rotulo
	|
;




atribuicao_procedimento:
	IDENT
	{
		//primeira parte da atribuição verifica se o destino existe
		controle->destino = buscaTabelaSimbolos(controle->tabela_simbolos, yytext, 0);

		if (controle->destino == NULL) {
			sprintf(controle->saida, "Simbolo '%s' nao declarado.\n", yytext);
            imprimeErro(controle->saida);
		}

		//empilha sempre, mas só vai usar caso seja um procedimento
		simbolo_t *simb_aux = (simbolo_t *) malloc(sizeof(simbolo_t));
		memcpy(simb_aux, controle->destino, sizeof(simbolo_t));
    	insereTabelaSimbolos(controle->pilha_proc_func, simb_aux);
    	int i = controle->pilha_proc_func->topo - 1;
		controle->pilha_proc_func->simbolos[i]->count_param_chamada = 0;
	}
	//segunda parte da atribuição "faz a parte da direita" e deixa no topo da pilha
	atribuicao_procedimento_2
;

atribuicao_procedimento_2:
	{
		controle->eh_booleana = 0;
		controle->tipo_ultima_operacao = indefinido; //na real eu acho que isso não é útil
	}
	ATRIBUICAO expressao
	{
		if (controle->destino->tipo == inteiro && controle->eh_booleana) {
			sprintf(controle->saida, "Atribuicao invalida. Destino eh um inteiro e encontrou expressao booleana.\n");
			imprimeErro(controle->saida);
		}

		if (controle->destino->tipo == boolean &&  controle->tipo_ultima_operacao == inteiro) {
			sprintf(controle->saida, "Atribuicao invalida. Destino eh um booleano e encontrou expressao aritmetica.\n");
			imprimeErro(controle->saida);
		}

		//se for variável simples OU uma função OU parâmetro formal passado por valor
		if (controle->destino->categoria == variavel_simples || (controle->destino->categoria == funcao && controle->dentro_funcao > 0) ||
					(controle->destino->categoria == parametro_formal && controle->destino->referencia == 0)) {
			sprintf(controle->saida, "ARMZ %d, %d", controle->destino->nivel_lexico, controle->destino->deslocamento);
			geraCodigo(NULL, controle->saida);
		//se for parâmetro formal passado por referência
		} else if (controle->destino->categoria == parametro_formal && controle->destino->referencia == 1) {
			sprintf(controle->saida, "ARMI %d, %d", controle->destino->nivel_lexico, controle->destino->deslocamento);
			geraCodigo(NULL, controle->saida);
		//se for um procedimento gera mensagem de erro
		} else if (controle->destino->categoria == procedimento) {
			sprintf(controle->saida, "Procedimento '%s' nao pode receber atribuição.\n", yytext);
			imprimeErro(controle->saida);
		}

		//nesse caso desempilha só para limpar, não vai ser usado porque não era um procedimento
		removeTabelaSimbolos(controle->pilha_proc_func);
	}
	//se leu o suposto destino, porém não tem símbolo de atribuição, então é uma chamada de procedimento
	|
	chamada_de_procedimento
	{
		simbolo_t *simb = removeTabelaSimbolos(controle->pilha_proc_func);

		if (simb->count_param_chamada != simb->numero_parametros) {
			sprintf(controle->saida, "Numero de parametros invalido na chamada do procedimento '%s'. Esperava %d e encontrou %d.", simb->identificador, controle->numero_parametros, simb->numero_parametros);
            imprimeErro(controle->saida);
		}

		sprintf(controle->saida, "CHPR %s, %d", simb->rotulo, controle->nivel_lexico);
        geraCodigo(NULL, controle->saida);
	}
;

chamada_de_procedimento:
	ABRE_PARENTESES
	{
		controle->verificando_param_chamada_funcao++;
	}
	lista_parametros_chamada
	FECHA_PARENTESES
	{
		controle->verificando_param_chamada_funcao--;
	}
	|
;

lista_parametros_chamada:
	lista_parametros_chamada VIRGULA expressao	
	{
		int i = controle->pilha_proc_func->topo - 1;
		controle->pilha_proc_func->simbolos[i]->count_param_chamada++;
	}
	|
	expressao
	{
		int i = controle->pilha_proc_func->topo - 1;
		controle->pilha_proc_func->simbolos[i]->count_param_chamada++;
	}
;

expressao:
	expressao_simples_1 expressao_simples_2
;

expressao_simples_2:
	| IGUAL {controle->eh_booleana = 1; controle->tipo_ultima_operacao = boolean;}
	expressao_simples_1
	{
		geraCodigo(NULL, "CMIG");
	}
	| DIFF {controle->eh_booleana = 1; controle->tipo_ultima_operacao = boolean;}
	expressao_simples_1
	{
		geraCodigo(NULL, "CMDG");
	}
	| MAIOR {controle->eh_booleana = 1; controle->tipo_ultima_operacao = boolean;}
	expressao_simples_1
	{
		geraCodigo(NULL, "CMMA");
	}
	| MAIOR_IGUAL {controle->eh_booleana = 1; controle->tipo_ultima_operacao = boolean;}
	expressao_simples_1
	{
		geraCodigo(NULL, "CMAG");
	}
	| MENOR {controle->eh_booleana = 1; controle->tipo_ultima_operacao = boolean;}
	expressao_simples_1
	{
		geraCodigo(NULL, "CMME");
	}
	| MENOR_IGUAL {controle->eh_booleana = 1; controle->tipo_ultima_operacao = boolean;}
	expressao_simples_1
	{
		geraCodigo(NULL, "CMEG");
	}
;

expressao_simples_1:
	expressao MAIS termo { geraCodigo(NULL, "SOMA"); controle->tipo_ultima_operacao = inteiro; }
	| expressao MENOS termo { geraCodigo(NULL, "SUBT"); controle->tipo_ultima_operacao = inteiro; }
	| expressao OR termo { geraCodigo(NULL, "OR"); controle->tipo_ultima_operacao = inteiro; }
	| termo
;

termo:
	termo MULT fator { geraCodigo(NULL, "MULT"); controle->tipo_ultima_operacao = inteiro; }
	| termo DIV fator { geraCodigo(NULL, "DIVI"); controle->tipo_ultima_operacao = inteiro; }
	| termo AND fator { geraCodigo(NULL, "AND"); controle->tipo_ultima_operacao = inteiro; }
	| fator
;

fator:
	NUMERO
	{
		sprintf(controle->saida, "CRCT %s", yytext);
		geraCodigo(NULL, controle->saida);
	}
	| ABRE_PARENTESES expressao FECHA_PARENTESES
	| variavel_funcao
	| TRUE { geraCodigo(NULL, "CRCT 1"); controle->eh_booleana = 1; }
	| FALSE { geraCodigo(NULL, "CRCT 0"); controle->eh_booleana = 1; }
;

variavel_funcao:
	IDENT
	{
		controle->origem = buscaTabelaSimbolos(controle->tabela_simbolos, yytext, 0);

		//se não encontrou encerra o programa e imprime mensagem de variável não declarada
		if (controle->origem == NULL) {
			sprintf(controle->saida, "Variavel '%s' nao declarada.\n", yytext);
            		imprimeErro(controle->saida);
		}

		if (controle->origem->tipo == boolean) {
			controle->eh_booleana = 1;
		}

		//se está verificando os parâmetros de uma chamada de função e controle->origem não é uma função
		if (controle->verificando_param_chamada_funcao > 0 && controle->origem->categoria != funcao) {
			int i_func = controle->pilha_proc_func->topo - 1;
			int i_param = controle->pilha_proc_func->simbolos[i_func]->count_param_chamada;

			//se o parâmetro deve ser passado por referência
			if (controle->pilha_proc_func->simbolos[i_func]->parametros[i_param].referencia) {
				//se é uma variável simples, carrega endereço
				if (controle->origem->categoria == variavel_simples) {
					sprintf(controle->saida, "CREN %d, %d", controle->origem->nivel_lexico, controle->origem->deslocamento);
					geraCodigo(NULL, controle->saida);
				//se é um parâmetro formal passado por referência, carrega valor
				} else if (controle->origem->categoria == parametro_formal && controle->origem->referencia) {
					sprintf(controle->saida, "CRVL %d, %d", controle->origem->nivel_lexico, controle->origem->deslocamento);
					geraCodigo(NULL, controle->saida);
				//se é um parâmetro formal passado por valor, carrega endereço
				} else if (controle->origem->categoria == parametro_formal && controle->origem->referencia == 0) {
					sprintf(controle->saida, "CREN %d, %d", controle->origem->nivel_lexico, controle->origem->deslocamento);
					geraCodigo(NULL, controle->saida);
				}
			//se o parâmetro deve ser passado por valor
			} else {
				//se é uma variável simples, carrega endereço
				if (controle->origem->categoria == variavel_simples) {
					sprintf(controle->saida, "CRVL %d, %d", controle->origem->nivel_lexico, controle->origem->deslocamento);
					geraCodigo(NULL, controle->saida);
				//se é um parâmetro formal passado por referência, carrega valor
				} else if (controle->origem->categoria == parametro_formal && controle->origem->referencia) {
					sprintf(controle->saida, "CRVI %d, %d", controle->origem->nivel_lexico, controle->origem->deslocamento);
					geraCodigo(NULL, controle->saida);
				//se é um parâmetro formal passado por valor, carrega endereço
				} else if (controle->origem->categoria == parametro_formal && controle->origem->referencia == 0) {
					sprintf(controle->saida, "CRVL %d, %d", controle->origem->nivel_lexico, controle->origem->deslocamento);
					geraCodigo(NULL, controle->saida);
				}
			}
		//se controle->origem não for uma função
		} else if (controle->origem->categoria != funcao) {
			//se é uma variável simples OU parâmetro formal passado por valor
			if (controle->origem->categoria == variavel_simples || (controle->origem->categoria == parametro_formal && controle->origem->referencia == 0)) {
				sprintf(controle->saida, "CRVL %d, %d", controle->origem->nivel_lexico, controle->origem->deslocamento);
				geraCodigo(NULL, controle->saida);
			//se for parâmetro formal passado por referência
			} else if (controle->origem->categoria == parametro_formal && controle->origem->referencia == 1) {
				sprintf(controle->saida, "CRVI %d, %d", controle->origem->nivel_lexico, controle->origem->deslocamento);
				geraCodigo(NULL, controle->saida);
			//se for um procedimento gera mensagem de erro
			} else if (controle->origem->categoria == procedimento) {
				sprintf(controle->saida, "Procedimento '%s' nao pode ser atribuido a uma variavel ou funcao.\n", yytext);
	            imprimeErro(controle->saida);
	        }
		}
	}
	chamada_de_funcao
;

chamada_de_funcao:
	ABRE_PARENTESES
	{
		controle->verificando_param_chamada_funcao++;

		//se for uma chamada de função com parâmetros, empilha a função e AMEM 1
		simbolo_t *simb_aux = (simbolo_t *) malloc(sizeof(simbolo_t));
		memcpy(simb_aux, controle->origem, sizeof(simbolo_t));
		insereTabelaSimbolos(controle->pilha_proc_func, simb_aux);
		sprintf(controle->saida, "AMEM 1");
		geraCodigo(NULL, controle->saida);
	}
	lista_parametros_chamada
	FECHA_PARENTESES
	{
		controle->verificando_param_chamada_funcao--;
	}
	{
		//desempilha a função
		simbolo_t *simb = removeTabelaSimbolos(controle->pilha_proc_func);
		
		if (simb->numero_parametros != simb->count_param_chamada) {
			sprintf(controle->saida, "Numero de parametros invalido na chamada do procedimento '%s'. Esperava %d e encontrou %d.", simb->identificador, simb->numero_parametros, simb->count_param_chamada);
            imprimeErro(controle->saida);
		}

		sprintf(controle->saida, "CHPR %s, %d", simb->rotulo, controle->nivel_lexico);
		geraCodigo(NULL, controle->saida);
	}
	|
	{
		//função sem parâmetros, nem precisa empilhar, é só dar AMEM 1 e chamar
		if (controle->dentro_funcao == 0 && controle->origem->categoria == funcao) {

			sprintf(controle->saida, "AMEM 1");
    		geraCodigo(NULL, controle->saida);
			simbolo_t *simb = removeTabelaSimbolos(controle->pilha_proc_func);
			if (simb->numero_parametros != simb->count_param_chamada) {
				sprintf(controle->saida, "Numero de parametros invalido na chamada do procedimento '%s'. Esperava %d e encontrou %d.", simb->identificador, simb->numero_parametros, simb->count_param_chamada);
	            imprimeErro(controle->saida);
			}

			sprintf(controle->saida, "CHPR %s, %d", simb->rotulo, controle->nivel_lexico);
			geraCodigo(NULL, controle->saida);
		//se está dentro de uma função e o símbolo é uma função, então trata a "variável" função			
		} else if (controle->dentro_funcao == 1 && controle->origem->categoria == funcao) {
			sprintf(controle->saida, "CRVL %d, %d", controle->origem->nivel_lexico, controle->origem->deslocamento);
			geraCodigo(NULL, controle->saida);
		}
	}
;


%%

main (int argc, char** argv) {
FILE* fp;
extern FILE* yyin;

	if (argc < 2 || argc > 2) {
		printf("usage compilador <arq>a %d\n", argc);
		return(-1);
	}

	fp = fopen(argv[1], "r");
	if (fp == NULL) {
		printf("usage compilador <arq>b\n");
		return(-1);
	}


/* -------------------------------------------------------------------
*  Inicia a Tabela de Símbolos
* ------------------------------------------------------------------- */

	controle = iniciaVariaveisControle();

	yyin=fp;
	yyparse();

	return 0;
}
