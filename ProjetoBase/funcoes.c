//=====================================================================================================================
// 						 			            BIBLIOTECAS
//=====================================================================================================================

#include <stdio.h>
#include <stdlib.h>
#include "compilador.h"
#include "funcoes.h"
#include <string.h>

//=====================================================================================================================
// 						 					    RÓTULOS
//=====================================================================================================================

void geraRotulo(int *numeroRotulos, TPilhaRotulos *pilhaRotulos) {
    char *novoRotulo;
    novoRotulo = (char *) malloc (sizeof (char [ROTULO_TAM]));
    if (*numeroRotulos > 9)
        sprintf(novoRotulo, "R%d", *numeroRotulos);
    else
        sprintf(novoRotulo, "R0%d", *numeroRotulos);
    *numeroRotulos = *numeroRotulos + 1;
    empilhaRotulo(pilhaRotulos, novoRotulo);
}


void iniciaPilhaRotulos(TPilhaRotulos *pilha) {
    pilha->topo = 0;
}

void empilhaRotulo (TPilhaRotulos *pilha, char *novoElemento) {
    pilha->elemento[pilha->topo] = novoElemento;
    pilha->topo++;
}

char *desempilhaRotulo(TPilhaRotulos *pilha) {
    if (pilha->topo > 0) {
        pilha->topo--;
        return pilha->elemento[pilha->topo];
    }
    return NULL;
}

//=====================================================================================================================
// 						 			            VERIFICAÇÃO DE TIPOS
//=====================================================================================================================

void iniciaPilhaTipos(TPilhaTipos *pilha) {
    pilha->topo = 0;
}

void empilhaTipo(TPilhaTipos *pilha, TTipo novoElemento) {
    pilha->elemento[pilha->topo] = novoElemento;
    pilha->topo++;
}

int desempilhaTipo(TPilhaTipos *pilha) {
    if (pilha->topo > 0) {
        pilha->topo--;
        return pilha->elemento[pilha->topo];
    }
    return 0;
}

int verificaTipos(TPilhaTipos *pilhaTipos, TOperacao operacao){
    TTipo tipoDireito, tipoEsquerdo;
    tipoDireito = desempilhaTipo(pilhaTipos);
    tipoEsquerdo = desempilhaTipo(pilhaTipos);
    switch (operacao) {
      case T_CALCULO:
        empilhaTipo(pilhaTipos, tipoDireito);
        break;
      case T_COMPARACAO:
        empilhaTipo(pilhaTipos, T_BOOLEAN);
        break;
      case T_ATRIBUICAO:
        break;
      }
    if (tipoDireito != tipoEsquerdo){
        printf ("Os tipos não conferem!!\n");
        return 1;
    }
    return 0;
}

//=====================================================================================================================
// 						 			            FUNCOES
//=====================================================================================================================

void atualizaRetornoFuncao (TTabela *tabela, TTipo tipo, int numeroParametros){
    TSimbolo *simbolo;
    simbolo = tabela->ultimo;
    while (1){
        if (simbolo->categoria == FUNCAO){
            simbolo->tipo = tipo;
            break;
        }
        simbolo = simbolo->anterior;
    };
    if (!numeroParametros)
        simbolo->end_retorno = (-4);
    else
        simbolo->end_retorno = (-3) - numeroParametros - 1;
    return;
}

//=====================================================================================================================
// 						 			            PROCEDIMENTOS
//=====================================================================================================================

void atualizaProcedimento(TTabela *tabela, char *procedureName, int nivelLexico, int numParametros, TParametro tipoParametros[100]){
    TSimbolo *simbolo;
    int contador;
    simbolo = tabela->ultimo;
    while (1){
        if (strcmp(procedureName, simbolo->id) == 0 ){
            contador = 0;
            //atualiza procedimento
            simbolo->numParametros = numParametros;
            while (numParametros > 0){
                simbolo->tipoParametros[contador].tipo = tipoParametros[contador].tipo;
                simbolo->tipoParametros[contador].passagem = tipoParametros[contador].passagem;
                numParametros--;
                contador++;
            }
            return;
        };
        simbolo = simbolo->anterior;
    }
}

//=====================================================================================================================
// 						 			            TABELA DE SÍMBOLOS
//=====================================================================================================================

void atualizaDeslocamentoParametros(TTabela *tabela, int numeroParametros){
    TSimbolo *simbolo;
    simbolo = tabela->ultimo;
    int contador = 0;
    while (numeroParametros > 0){
        if (simbolo->categoria == PF){
            simbolo->deslocamento = (-4) - contador;
            contador++;
            numeroParametros--;
        }
        simbolo = simbolo->anterior;
    }
}

TSimbolo *criaSimbolo (){
    TSimbolo *simbolo;
    simbolo = malloc (sizeof (TSimbolo));
    if (simbolo == NULL) {
        printf("Erro de alocação de simbolo!");
    }
    simbolo->anterior = simbolo->proximo = NULL;
}

int insereVS(TTabela *tabela, char *id, int nivel_lexico, TPassagem valor_referencia) {
    TSimbolo *simbolo;
    simbolo = criaSimbolo ();

    /*  PREPARA SIMBOLO  */
    strcpy (simbolo->id, id);
    simbolo->categoria = VARIAVELSIMPLES;
    simbolo->nivel_lexico = nivel_lexico;
    simbolo->passagem = valor_referencia;
    simbolo->tipo = T_INDEFINIDO;
    //

    /*  EMPILHA SIMBOLO  */
    if (tabela->num_simbolos == 0) {
        tabela->primeiro = simbolo;
    }
    else {
    simbolo->anterior = tabela->ultimo;
    tabela->ultimo->proximo  = simbolo;
    simbolo->proximo = NULL;
    }
    //

    /*  AJUSTA TABELA   */
    tabela->ultimo = simbolo;
    tabela->num_simbolos++;
    //
    return 0;
}

int insereRT(TTabela *tabela, char *id, int nivel_lexico, char *rotulo) {
    TSimbolo *simbolo;
    if (simbolo = procuraSimbolo(tabela, id, nivel_lexico, 1)){
        printf("Erro, Label ja declarada!\n");
        return 1;
    }
    else {

    simbolo = criaSimbolo ();

    /*  PREPARA SIMBOLO  */
    strcpy (simbolo->id, id);
    simbolo->categoria = ROTULO;
    simbolo->nivel_lexico = nivel_lexico;
    strcpy (simbolo->rotulo, rotulo);
    simbolo->tipo = T_INDEFINIDO;
    //

    /*  EMPILHA SIMBOLO  */
    if (tabela->num_simbolos == 0) {
        tabela->primeiro = simbolo;
    }
    else {
    simbolo->anterior = tabela->ultimo;
    tabela->ultimo->proximo  = simbolo;
    simbolo->proximo = NULL;
    }
    //

    /*  AJUSTA TABELA   */
    tabela->ultimo = simbolo;
    tabela->num_simbolos++;
    //
    return 0;
    }
}

int inserePR(TTabela *tabela, char *id, int nivel_lexico, char *rotulo) {
    TSimbolo *simbolo;
    if (simbolo = procuraSimbolo(tabela, id, nivel_lexico, 1)){
        printf("Erro, Procedimento ja declarado!\n");
        return 1;
    }
    else {

    simbolo = criaSimbolo ();

    /*  PREPARA SIMBOLO  */
    strcpy (simbolo->id, id);
    simbolo->categoria = PROCEDIMENTO;
    simbolo->nivel_lexico = nivel_lexico + 1;
    strcpy (simbolo->rotulo, rotulo);
    simbolo->tipo = T_INDEFINIDO;
    //

    /*  EMPILHA SIMBOLO  */
    if (tabela->num_simbolos == 0) {
        tabela->primeiro = simbolo;
    }
    else {
    simbolo->anterior = tabela->ultimo;
    tabela->ultimo->proximo  = simbolo;
    simbolo->proximo = NULL;
    }
    //

    /*  AJUSTA TABELA   */
    tabela->ultimo = simbolo;
    tabela->num_simbolos++;
    //
    return 0;
    }
}

int insereFN(TTabela *tabela, char *id, int nivel_lexico, char *rotulo){
    TSimbolo *simbolo;
    if (simbolo = procuraSimbolo(tabela, id, nivel_lexico, 1)){
        printf("Erro, Funcao ja declarada!\n");
        return 1;
    }
    else {

    simbolo = criaSimbolo ();

    /*  PREPARA SIMBOLO  */
    strcpy (simbolo->id, id);
    simbolo->categoria = FUNCAO;
    simbolo->nivel_lexico = nivel_lexico;
    strcpy (simbolo->rotulo, rotulo);
    simbolo->tipo = T_INDEFINIDO;
    //

    /*  EMPILHA SIMBOLO  */
    if (tabela->num_simbolos == 0) {
        tabela->primeiro = simbolo;
    }
    else {
    simbolo->anterior = tabela->ultimo;
    tabela->ultimo->proximo  = simbolo;
    simbolo->proximo = NULL;
    }
    //

    /*  AJUSTA TABELA   */
    tabela->ultimo = simbolo;
    tabela->num_simbolos++;
    //
    return 0;
    }
}

void inserePF(TTabela *tabela, char *id, int nivel_lexico, TPassagem valor_referencia) {
    TSimbolo *simbolo;

    simbolo = criaSimbolo ();

    /*  PREPARA SIMBOLO  */
    strcpy (simbolo->id, id);
    simbolo->categoria = PF;
    simbolo->nivel_lexico = nivel_lexico;
    simbolo->passagem = valor_referencia;
    simbolo->tipo = T_INDEFINIDO;
    //

    /*  EMPILHA SIMBOLO  */
    if (tabela->num_simbolos == 0) {
        tabela->primeiro = simbolo;
    }
    else {
    simbolo->anterior = tabela->ultimo;
    tabela->ultimo->proximo  = simbolo;
    simbolo->proximo = NULL;
    }
    //

    /*  AJUSTA TABELA   */
    tabela->ultimo = simbolo;
    tabela->num_simbolos++;
    //
    }

void atualizaTipos(TTabela *tabela, TTipo tipo, int n_vars_local){
    TSimbolo *simbolo;
    simbolo = tabela->ultimo;
    while (n_vars_local > 0){
        simbolo->tipo = tipo;
        n_vars_local--;
        simbolo = simbolo->anterior;
    }
}

void atualizaDeslocamento(TTabela *tabela, int nVars){
    TSimbolo *simbolo;
    simbolo = tabela->ultimo;
    while (nVars > 0){
        simbolo->deslocamento = nVars - 1;
        nVars--;
        simbolo = simbolo->anterior;
    }
}


TSimbolo *procuraSimbolo(TTabela *tabela, char *id, int nivel_lexico, int proc_func){
    TSimbolo *aux = tabela->ultimo;
    while (aux) {
        if ((strcmp(aux->id, id) == 0) && ((aux->nivel_lexico <= nivel_lexico) || (proc_func == 1))){
            return aux;
        }
        aux = aux->anterior;
    }
    return NULL;
}

//=====================================================================================================================
// 						 				        FUNÇÕES AUXILIARES
//=====================================================================================================================

void geraArmazena(TSimbolo simbolo) {
    if (simbolo.categoria == FUNCAO){
        geraCodigoArgumentos (NULL, "ARMZ %d, %d", simbolo.nivel_lexico, simbolo.end_retorno);
        return;
    }
    if (simbolo.passagem == T_VALOR){
        geraCodigoArgumentos (NULL, "ARMZ %d, %d", simbolo.nivel_lexico, simbolo.deslocamento);
    }
    else{
        geraCodigoArgumentos (NULL, "ARMI %d, %d", simbolo.nivel_lexico, simbolo.deslocamento);
    }
}

void verificaAssinatura(TSimbolo simbolo, TSimbolo simboloProcFunc, int parametroChamada, int id_num){
    parametroChamada--;
    //PARAMETRO É UM NUM
    if (id_num == 0 && simboloProcFunc.tipoParametros[parametroChamada].passagem == 1){
        printf ("ERRO PARAMETRO NÃO COINCIDE COM TIPO DA FUNÇÃO\n");
    }
    else{
        //FUNCAO VALOR CHAMADA VALOR
        if (simboloProcFunc.tipoParametros[parametroChamada].passagem == 2 && simbolo.passagem == 2) {
            geraCodigoArgumentos (NULL, "CRVL %d, %d", simbolo.nivel_lexico, simbolo.deslocamento);
        }
        else{
            //FUNCAO REFERENCIA CHAMADA VALOR
            if (simboloProcFunc.tipoParametros[parametroChamada].passagem == 1 && simbolo.passagem == 2) {
                geraCodigoArgumentos (NULL, "CREN %d, %d", simbolo.nivel_lexico, simbolo.deslocamento);
            }
            else{
                //FUNCAO REFERENCIA CHAMADA REFERENCIA
                if (simboloProcFunc.tipoParametros[parametroChamada].passagem == 1 && simbolo.passagem == 1) {
                    geraCodigoArgumentos (NULL, "CRVL %d, %d", simbolo.nivel_lexico, simbolo.deslocamento);
                }
                else{
                    //FUNCAO VALOR CHAMADA REFERENCIA
                    if (simboloProcFunc.tipoParametros[parametroChamada].passagem == 2 && simbolo.passagem == 1) {
                        geraCodigoArgumentos (NULL, "CRVI %d, %d", simbolo.nivel_lexico, simbolo.deslocamento);
                    }
                }
            }
        }
    }
}

void geraCarregaValor(TSimbolo simbolo) {
    if (simbolo.passagem == T_VALOR) {
        geraCodigoArgumentos(NULL, "CRVL %d, %d", simbolo.nivel_lexico, simbolo.deslocamento);
    }
    else {
        geraCodigoArgumentos(NULL, "CRVI %d, %d", simbolo.nivel_lexico, simbolo.deslocamento);
    }
}

void geraCarregaEndereco(TSimbolo simbolo) {
    geraCodigoArgumentos(NULL, "CREN %d, %d", simbolo.nivel_lexico, simbolo.deslocamento);
}

void atualizaNumVarsLocal(TTabela *tabela, char *id, int varsProc){
    TSimbolo *aux = tabela->ultimo;
    while (aux) {
        if (strcmp(aux->id, id) == 0){
            aux->nVarsLocal = varsProc;
            return;
        }
        aux = aux->anterior;
    }
}

