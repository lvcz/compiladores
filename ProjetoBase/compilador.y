
// Testar se funciona corretamente o empilhamento de parâmetros
// passados por valor ou por referência.


%{
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "compilador.h"
#include "funcoes.h"

int n_vars_local, nivel_lexico, deslocamento, n_vars_global = 0, numVars, varsProc = 0;
int numeroRotulos, numeroParametros, proc_func = 0, i, flag = 0, flag1 = 0, chamadaProcedimento = 0, relation = 0, func = 0, parametrosChamada = 0, id_num;
char *rotulo_if, *rotulo_else, *rotulo_while, *rotulo_while2, *rotulo_procedimento, *rotulo_procedimento2, *rotulo_bloco, *labelName;

char procedureName[100], functionName[100], chr, idEsquerdo[100];

TTabela *tabela;
TSimbolo *simboloAux, *simboloAux1, *elementoEsquerdo;
TPilhaRotulos pilhaRotulos;
TPilhaTipos pilhaTipos;
TTipo tipo;
TParametro tipoParametros[100];


#define geraCodigoDMEM() \
    if (n_vars_global) { \
		geraCodigoArgumentos (NULL, "DMEM %d", n_vars_global); }

%}

%token PROGRAM ABRE_PARENTESES FECHA_PARENTESES
%token VIRGULA PONTO_E_VIRGULA DOIS_PONTOS PONTO
%token T_BEGIN T_END VAR IDENT ATRIBUICAO INTEGER BOOLEAN
%token SOMA SUBTRACAO MULTIPLICACAO DIVISAO
%token OR AND MAIOR_QUE MENOR_QUE MAIOR_OU_IGUAL MENOR_OU_IGUAL IGUAL
%token NUMERO IF THEN ELSE WHILE DO READ WRITE PROCEDURE FUNCTION
%token LABEL GOTO TRUE FALSE

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%%

programa    :{
                geraCodigo (NULL, "INPP");
             }

             PROGRAM IDENT entrada PONTO_E_VIRGULA
             bloco PONTO

             {
                 geraCodigoDMEM();
                 geraCodigo(NULL,"PARA");
             }
;

entrada		:
			ABRE_PARENTESES lista_idents FECHA_PARENTESES
			| 
;

bloco       :

            declara_labels

            parte_declara_vars

            {
                geraRotulo(&numeroRotulos, &pilhaRotulos);
            }

            procedimentos_funcoes

            {
                rotulo_bloco = desempilhaRotulo(&pilhaRotulos);
                geraCodigo(rotulo_bloco, "NADA");
            }

            comando_composto
;

declara_labels:

            LABEL

            labels PONTO_E_VIRGULA
            |
;

labels  :
            label
            | labels VIRGULA label
;

label   :

        NUMERO
        {
            geraRotulo(&numeroRotulos, &pilhaRotulos);
            labelName = desempilhaRotulo(&pilhaRotulos);
            insereRT(tabela, token, nivel_lexico, labelName);
        }
;

parte_declara_vars:  var
;


var         : VAR
            {
                deslocamento=0; numVars=0;
                if (proc_func)
                    varsProc = 0;
            }
            declara_vars
            |
;

declara_vars: declara_vars { n_vars_local = 0; } declara_var
            | { n_vars_local = 0; } declara_var
;

declara_var : conjunto_variaveis

            {
				n_vars_local = 0;
            }
            
            mais_variaveis
;

conjunto_variaveis:

            lista_id_var DOIS_PONTOS

            {
                atualizaDeslocamento (tabela, numVars);
                geraCodigoArgumentos(NULL, "AMEM %d", n_vars_local); /* AMEM */
            }

            tipo PONTO_E_VIRGULA
;

mais_variaveis  :
			mais_variaveis conjunto_variaveis
            | conjunto_variaveis
            |
;

tipo        :
             INTEGER

            {
                atualizaTipos(tabela, T_INTEGER, n_vars_local);
                if (proc_func){
                    for (i = 0; i < n_vars_local; i++){
                        tipoParametros[i].tipo = T_INTEGER;
                    }
                }
            }

             | BOOLEAN

            {
                atualizaTipos(tabela, T_BOOLEAN, n_vars_local);
                if (proc_func){
                    for (i = 0; i < n_vars_local; i++){
                        tipoParametros[i].tipo = T_BOOLEAN;
                    }
                }
            }

             | IDENT

            {
                atualizaTipos(tabela, T_UNKNOWN, n_vars_local);
            }
;

tipo_retorno    :
            INTEGER

            {
                atualizaRetornoFuncao(tabela, T_INTEGER, numeroParametros);
            }

            | BOOLEAN

            {
                atualizaRetornoFuncao(tabela, T_INTEGER, numeroParametros);
            }

            | IDENT

            {
                atualizaRetornoFuncao(tabela, T_INTEGER, numeroParametros);
            }
;

lista_id_var: lista_id_var VIRGULA variavel
            | variavel
;

variavel    :
            IDENT
            {
                n_vars_local++; numVars++;
                if (proc_func)
                    varsProc++;
                if (proc_func == 0)
                    n_vars_global++;
                if (insereVS(tabela, token, nivel_lexico, T_VALOR))
                    exit (1);
            }
;

lista_idents: lista_idents VIRGULA IDENT
            | IDENT
;


comando_composto:
            comando
            | T_BEGIN comandos T_END
;

comandos    :
            comandos PONTO_E_VIRGULA comando
            | comando
;

comando     : atribuicao_procedimento
            | leitura
            | imprime
            | condicional
            | repeticao
            | goto
            | chamada_label
;

chamada_label :

            NUMERO

            {
                simboloAux = procuraSimbolo(tabela, token, nivel_lexico, proc_func);
                geraCodigoArgumentos(simboloAux->rotulo, "ENRT %d %d", nivel_lexico, n_vars_local);
            }

            DOIS_PONTOS comando
;

goto    :
        GOTO NUMERO
        {
            simboloAux = procuraSimbolo(tabela, token, nivel_lexico, proc_func);
            geraCodigoArgumentos(NULL, "DSVR %s, %d, %d", simboloAux->rotulo, simboloAux->nivel_lexico, nivel_lexico);
            //geraCodigoDesvio("DSVR", simboloAux->rotulo, simboloAux->nivel_lexico, nivel_lexico);
        }
;

procedimentos_funcoes:

            procedimentos
            | funcoes
            |
;

funcoes :   funcoes funcao
            | funcao

funcao  :

            FUNCTION IDENT

            {
                proc_func = 1;
                func = 1;
                strcpy (procedureName, token);
                nivel_lexico++;
                geraRotulo(&numeroRotulos, &pilhaRotulos);
                rotulo_procedimento = desempilhaRotulo(&pilhaRotulos);
                if (insereFN(tabela, procedureName, nivel_lexico, rotulo_procedimento))
                    exit(1);
                empilhaRotulo(&pilhaRotulos, rotulo_procedimento);
            }

            parametros_procedimento

            {
                atualizaProcedimento(tabela, procedureName, nivel_lexico, numeroParametros, tipoParametros);
                if (numeroParametros)
                    atualizaDeslocamentoParametros(tabela, numeroParametros);
            }

            DOIS_PONTOS tipo_retorno PONTO_E_VIRGULA

            bloco_proc_func

            {
                proc_func = 0;
                func = 0;
            }
;


procedimentos   :   procedimentos procedimento
            | procedimento
;

procedimento    :

            PROCEDURE IDENT

            {
                proc_func = 1;
                strcpy (procedureName, token);
                nivel_lexico++;
                geraRotulo(&numeroRotulos, &pilhaRotulos);
                rotulo_procedimento = desempilhaRotulo(&pilhaRotulos);
                if (inserePR(tabela, procedureName, nivel_lexico, rotulo_procedimento)){
                    exit(1);
                };
                empilhaRotulo(&pilhaRotulos, rotulo_procedimento);
            }

            parametros_procedimento

            {
                atualizaProcedimento(tabela, procedureName, nivel_lexico, numeroParametros, tipoParametros);
                if (numeroParametros)
                    atualizaDeslocamentoParametros(tabela, numeroParametros);
            }

            PONTO_E_VIRGULA bloco_proc_func


            {
                proc_func = 0;
            }
;

bloco_proc_func:

            {
                /*  DESVIA SEMPRE       */
                rotulo_procedimento2 = desempilhaRotulo(&pilhaRotulos);
                rotulo_procedimento = desempilhaRotulo(&pilhaRotulos);
                if ((strcmp(rotulo_procedimento, "R00") == 0) && (flag == 0)){
                    flag = 1;
                    geraCodigoArgumentos (NULL, "DSVS %s", rotulo_procedimento);
                }
                else{
                    if ((strcmp(rotulo_procedimento, "R00") != 0) && (flag == 1)){
                        geraCodigoArgumentos (NULL, "DSVS %s", rotulo_procedimento);
                    }
                }
                empilhaRotulo(&pilhaRotulos, rotulo_procedimento);
                empilhaRotulo(&pilhaRotulos, rotulo_procedimento2);

                /*  GERA ROTULO E ENTRA PROCEDIMENTO */
                rotulo_procedimento = desempilhaRotulo(&pilhaRotulos);
                geraCodigoArgumentos(rotulo_procedimento, "ENPR %d", nivel_lexico);
            }

            declara_labels

            parte_declara_vars

            {
                atualizaNumVarsLocal (tabela, procedureName, varsProc);
                geraRotulo(&numeroRotulos, &pilhaRotulos);
            }

            procedimentos_funcoes

            {
                rotulo_bloco = desempilhaRotulo(&pilhaRotulos);
                geraCodigo(rotulo_bloco, "NADA");
            }

            comando_composto PONTO_E_VIRGULA

            {
                simboloAux = procuraSimbolo(tabela, procedureName, nivel_lexico, 1);
                if (simboloAux->nVarsLocal)
                    geraCodigoArgumentos (NULL, "DMEM %d", simboloAux->nVarsLocal);
                geraCodigoArgumentos (NULL, "RTPR %d, %d", nivel_lexico, numeroParametros);
                nivel_lexico--;
            }
;

parametros_procedimento  :

            {
                numeroParametros = 0;
            }

            ABRE_PARENTESES
            conjunto_parametros
            FECHA_PARENTESES

            |
;

conjunto_parametros    :

            // REGRA PARA MAIS DE 1 CONJUNTO DE PARAMETROS
            conjunto_parametros PONTO_E_VIRGULA

            {
                n_vars_local = 0;
            }

            lista_parametros DOIS_PONTOS tipo

            |
            // REGRA PARA 1 CONJUNTO DE PARAMETROS

            {
                n_vars_local = 0;
            }

            lista_parametros DOIS_PONTOS tipo

            {
                //atualiza tipos
            }

            // REGRA PARA NENHUM PARAMETRO

            |

;

lista_parametros  :

            // REGRA PARA MAIS DE 1 VARIÁVEL DO MESMO TIPO SEPARADO POR VÍRGULAS

            lista_parametros VIRGULA parametro

            |

            // REGRA PARA 1 VARIÁVEL DE UM CERTO TIPO

            parametro
;

parametro   :

            IDENT

            {
                n_vars_local++;
                numeroParametros++;
                inserePF(tabela, token, nivel_lexico, T_VALOR);
                tipoParametros[numeroParametros-1].passagem = T_VALOR;
            }

            |

            VAR IDENT
            {
                n_vars_local++;
                numeroParametros++;
                inserePF(tabela, token, nivel_lexico, T_REFERENCIA);
                tipoParametros[numeroParametros-1].passagem = T_REFERENCIA;
            }
;

leitura: READ ABRE_PARENTESES parametros_leitura FECHA_PARENTESES
;

imprime: WRITE ABRE_PARENTESES parametros_imprime FECHA_PARENTESES
;

parametros_leitura:

            parametros_leitura VIRGULA IDENT

            {
                geraCodigo (NULL, "LEIT");
                simboloAux = procuraSimbolo(tabela, token, nivel_lexico, proc_func);
                geraArmazena (*simboloAux);
            }

            | IDENT

            {
                geraCodigo (NULL, "LEIT");
                simboloAux = procuraSimbolo(tabela, token, nivel_lexico, proc_func);
                geraArmazena (*simboloAux);

            }
;

parametros_imprime: parametros_imprime VIRGULA parametro_imprime

            | parametro_imprime
;

parametro_imprime:

            IDENT

            {
                simboloAux = procuraSimbolo(tabela, token,nivel_lexico, proc_func);
                geraCarregaValor(*simboloAux);
                geraCodigo (NULL, "IMPR");
            }
;

atribuicao  :
            {
                elementoEsquerdo = procuraSimbolo(tabela, idEsquerdo, nivel_lexico, proc_func);
                if (elementoEsquerdo == NULL){
                    printf ("Erro, variável não encontrada na Tabela de Símbolos\n");
                    exit(1);
                }
                empilhaTipo(&pilhaTipos, elementoEsquerdo->tipo);
            }

            ATRIBUICAO expressao

            {
                if(verificaTipos (&pilhaTipos, T_ATRIBUICAO))
                    exit(1);
                geraArmazena(*elementoEsquerdo);
            }
;

atribuicao_procedimento  :

            IDENT

            {
                strcpy (idEsquerdo, token);
            }

            atrib_proc
;

atrib_proc  :

            atribuicao

            |

            {
                chamadaProcedimento = 1;
                elementoEsquerdo = procuraSimbolo(tabela, idEsquerdo, nivel_lexico, 1);
                if (elementoEsquerdo == NULL){
                    printf ("Erro, procedimento/funcao não encontrado na Tabela de Símbolos\n");
                    exit(1);
                }
            }

            chamada_procedimento

            {
                strcpy(rotulo_procedimento, elementoEsquerdo->rotulo);
                if (numeroRotulos > 9){
                    geraCodigoArgumentos (NULL, "CHPR R%c%c, %d", rotulo_procedimento[1], rotulo_procedimento[2], nivel_lexico);
                }
                else{
                    geraCodigoArgumentos (NULL, "CHPR R0%c, %d", rotulo_procedimento[2], nivel_lexico);
                }
                chamadaProcedimento = 0;
            }

;

chamada_procedimento   :

            ABRE_PARENTESES

            parametros_chamada

            FECHA_PARENTESES

            |

            ABRE_PARENTESES FECHA_PARENTESES

            |
;

parametros_chamada: parametros_chamada VIRGULA expressao
            {
            if (flag1){
                parametrosChamada++;
                verificaAssinatura(*simboloAux, *simboloAux1, parametrosChamada, id_num);
                }
            }
            | expressao
            {
            if (flag1){
                parametrosChamada++;
                verificaAssinatura(*simboloAux, *simboloAux1, parametrosChamada, id_num);
                }
            }
;

relacao  :  MAIOR_QUE  {  relation = 0; }
		  | MENOR_QUE  { relation = 1; }
		  | MAIOR_OU_IGUAL { relation = 2; }
		  | MENOR_OU_IGUAL { relation = 3; }
		  | IGUAL  {  relation = 4; }
;

expressao   :

            expressao_simples relacao expressao
            {
                switch (relation){
                    case 0:
                        geraCodigo(NULL,"CMMA");
                    break;
                    case 1:
                        geraCodigo(NULL,"CMME");
                    break;
                    case 2:
                        geraCodigo(NULL,"CMAG");
                    break;
                    case 3:
                        geraCodigo(NULL,"CMEG");
                    break;
                    case 4:
                        geraCodigo(NULL,"CMIG");
                    break;
                }

                if(verificaTipos (&pilhaTipos, T_COMPARACAO))
                    exit(1);
            }
            | expressao_simples
;

expressao_simples: expressao_simples SOMA termo
			{
                if(verificaTipos (&pilhaTipos, T_CALCULO))
                    exit(1);
                geraCodigo(NULL, "SOMA");
			}
            | expressao_simples SUBTRACAO termo
            {
                if(verificaTipos (&pilhaTipos, T_CALCULO))
                    exit(1);
                geraCodigo(NULL, "SUBT");
            }
            | expressao_simples OR termo
            {
                if(verificaTipos (&pilhaTipos, T_COMPARACAO))
                    exit(1);
                geraCodigo(NULL, "OR");
            }
            | expressao_simples AND termo
            {
                if(verificaTipos (&pilhaTipos, T_COMPARACAO))
                    exit(1);
                geraCodigo(NULL, "AND");
            }
            | termo
;

termo       : fator MULTIPLICACAO termo
            {
                if(verificaTipos (&pilhaTipos, T_CALCULO))
                    exit(1);
                geraCodigo(NULL, "MULT");
            }
            | fator DIVISAO termo
            {
                if(verificaTipos (&pilhaTipos, T_CALCULO))
                    exit(1);
                geraCodigo(NULL, "DIVI");
            }
            | fator AND termo
            {
                if(verificaTipos (&pilhaTipos, T_COMPARACAO))
                    exit(1);
                geraCodigo(NULL, "AND");
            }
            | fator
;

fator       :

            NUMERO

            {
                empilhaTipo(&pilhaTipos, T_INTEGER);
                geraCodigoArgumentos(NULL, "CRCT %d", atoi(token));
                if (flag1){
                    id_num = 0;
                }
            }
            
            |

			booleano
		
            |

            funcao_variavel

            | ABRE_PARENTESES expressao FECHA_PARENTESES
;

booleano:			
			TRUE
			{
				geraCodigo(NULL, "CRCT 1");
				empilhaTipo(&pilhaTipos, T_BOOLEAN);
			}
			
			| 
			
			FALSE
			{
				geraCodigo(NULL, "CRCT 0");
				empilhaTipo(&pilhaTipos, T_BOOLEAN);
			}
;

funcao_variavel    :

            IDENT

            {
                strcpy(idEsquerdo, token);
            }

            verifica
;

verifica    :

            {
                simboloAux1 = procuraSimbolo(tabela, idEsquerdo, nivel_lexico, 1);
                //GERA CODIGO AMEM SE FOR FUNCAO
                if (simboloAux1->categoria == FUNCAO){
                    empilhaTipo(&pilhaTipos, simboloAux1->tipo);
                    geraCodigo(NULL, "AMEM 1");
                }
                flag1 = 1;
                parametrosChamada = 0;
            }

            ABRE_PARENTESES

            parametros_chamada

            FECHA_PARENTESES

            {
                flag1 = 0;
            }

            {
                strcpy(rotulo_procedimento, simboloAux1->rotulo);
                geraCodigoArgumentos (NULL, "CHPR R0%c, %d", rotulo_procedimento[2], nivel_lexico);
            }

            |

            {
                simboloAux = procuraSimbolo(tabela, idEsquerdo, nivel_lexico, proc_func);
                if (flag1){
                    id_num = 1;
                }
                else{
                    geraCarregaValor(*simboloAux);
                }
                empilhaTipo(&pilhaTipos, simboloAux->tipo);
            }
;

repeticao   :
            WHILE

            {
                /*  GERA DOIS ROTULOS           */
                /*  ESCREVE ROTULO INICIO WHILE */
                geraRotulo(&numeroRotulos, &pilhaRotulos);
                rotulo_while = desempilhaRotulo(&pilhaRotulos);
                geraCodigo (rotulo_while, "NADA");
                empilhaRotulo(&pilhaRotulos, rotulo_while);
                geraRotulo(&numeroRotulos, &pilhaRotulos);
            }

            expressao

            {
                /*  DESVIA SE FALSO */
                rotulo_while = desempilhaRotulo(&pilhaRotulos);
                geraCodigoArgumentos (NULL, "DSVF %s", rotulo_while);
                empilhaRotulo(&pilhaRotulos, rotulo_while);
            }

            DO comando_composto

            {
                /*  ESCREVE ROTULO FIM DO WHILE */
                rotulo_while = desempilhaRotulo(&pilhaRotulos);
                rotulo_while2 = desempilhaRotulo(&pilhaRotulos);
                geraCodigoArgumentos (NULL, "DSVS %s", rotulo_while2);
                geraCodigo (rotulo_while, "NADA");
            }
;

condicional : if_then cond_else
;

if_then  :

            IF

            {
                /*  GERA DOIS ROTULOS   */
                geraRotulo(&numeroRotulos, &pilhaRotulos);
                geraRotulo(&numeroRotulos, &pilhaRotulos);
            }

            expressao

            {   /*  DESVIA SE FALSO */
                rotulo_if = desempilhaRotulo(&pilhaRotulos);
                geraCodigoArgumentos (NULL, "DSVF %s", rotulo_if);
                empilhaRotulo(&pilhaRotulos, rotulo_if);
            }

            THEN comando_composto

            {
                /*  DESVIA SEMPRE   */
                rotulo_else = desempilhaRotulo(&pilhaRotulos);
                rotulo_if = desempilhaRotulo(&pilhaRotulos);
                geraCodigoArgumentos (NULL, "DSVS %s", rotulo_if);
                empilhaRotulo(&pilhaRotulos, rotulo_if);
                empilhaRotulo(&pilhaRotulos, rotulo_else);

                /*  ESCREVE ROTULO DO IF    */
                rotulo_if = desempilhaRotulo(&pilhaRotulos);
                geraCodigo(rotulo_if, "NADA");
            }
;

cond_else   :

            ELSE comando_composto
            {
                /*  ESCREVE ROTULO DO ELSE  */
                rotulo_else = desempilhaRotulo(&pilhaRotulos);
                geraCodigo(rotulo_else, "NADA");
            }

            | %prec LOWER_THAN_ELSE

            {
                /*  DESEMPILHA ROTULO DESNECESSARIO DO ELSE  */
                rotulo_else = desempilhaRotulo(&pilhaRotulos);
                geraCodigo(rotulo_else, "NADA");
            }
;

%%

main (int argc, char** argv) {
   FILE* fp;
   extern FILE* yyin;

   if (argc<2 || argc>2) {
         printf("usage compilador <arq>a %d\n", argc);
         return(-1);
      }

   fp=fopen (argv[1], "r");
   if (fp == NULL) {
      printf("usage compilador <arq>b\n");
      return(-1);
   }
/* -------------------------------------------------------------------
 *  Inicia Pilhas Auxiliares
 * ------------------------------------------------------------------- */

  iniciaPilhaRotulos(&pilhaRotulos);
  iniciaPilhaTipos(&pilhaTipos);

/* -------------------------------------------------------------------
 *  Inicia a Tabela de Símbolos
 * ------------------------------------------------------------------- */

 tabela = malloc (sizeof(TTabela));
 tabela->primeiro = tabela->ultimo = NULL;

 /* ------------------------------------------------------------------- */


   yyin=fp;
   yyparse();

   return 0;
}
