//=====================================================================================================================
// 						 			            CONSTANTES
//=====================================================================================================================

#define ROTULO_TAM 5  /* Tamanho maximo do 'char' para o rotulo no MEPA  */
#define PILHA_TAM 255
#define TAM_LISTA_PARAM 255


//=====================================================================================================================
// 						 			       ESTRUTURAS PARA TABELA DE SÍMBOLOS
//=====================================================================================================================

typedef enum TCategoria {
    FUNCAO, PF, PROCEDIMENTO, PROGRAMA, ROTULO, VARIAVELSIMPLES
    }TCategoria;

typedef enum TTipo {
    T_INTEGER=1, T_BOOLEAN=2, T_PROCEDURE=3, T_FUNCTION=4, T_VOID=5, T_UNKNOWN=9, T_INDEFINIDO=8
    }TTipo;

typedef enum TPassagem {
  T_REFERENCIA=1, T_VALOR=2
} TPassagem;

typedef struct TParametro {
  TTipo tipo;
  TPassagem passagem;
} TParametro;

typedef struct TSimbolo {
    char id[TAM_TOKEN];
    int nivel_lexico;
    TCategoria categoria;
    TTipo tipo;

  union {
    int deslocamento;
    int end_retorno;
  };

  union {
    TPassagem passagem;
    struct {
      int numParametros;
      int nVarsLocal;
      char rotulo[TAM_ROTULO];
      TParametro tipoParametros[100];
    };
  };

  struct TSimbolo *anterior, *proximo;

} TSimbolo;

typedef struct TTabela {
  TSimbolo *primeiro, *ultimo;
  int num_simbolos;
} TTabela;

//=====================================================================================================================
// 						 			  ESTRUTURAS PARA PILHAS DE ROTULOS E TIPOS
//=====================================================================================================================

typedef struct TPilhaRotulos {
  char *elemento[PILHA_TAM];
  int topo;
} TPilhaRotulos;

typedef struct TPilhaTipos {
  TTipo elemento[PILHA_TAM];
  int topo;
} TPilhaTipos;

typedef enum TOperacao {
  T_CALCULO, T_COMPARACAO, T_ATRIBUICAO,
} TOperacao;

//=====================================================================================================================
// 						 			        FUNCOES PARA ROTULOS
//=====================================================================================================================

void geraRotulo (int *numeroRotulos, TPilhaRotulos *pilhaRotulos);
void iniciaPilhaRotulos (TPilhaRotulos *pilha);
void empilhaRotulo (TPilhaRotulos *pilha, char *novoElemento);
char *desempilhaRotulo (TPilhaRotulos *pilha);

//=====================================================================================================================
// 						 			        FUNCOES PARA TIPOS
//=====================================================================================================================

void iniciaPilhaTipos (TPilhaTipos *pilha);
void empilhaTipo (TPilhaTipos *pilha, TTipo novoElemento);
int desempilhaTipo (TPilhaTipos *pilha);
int verificaTipos (TPilhaTipos *pilhaTipos, TOperacao operacao);

//=====================================================================================================================
// 						 			 FUNCOES PARA TABELA DE SÍMBOLOS
//=====================================================================================================================

void atualizaDeslocamentoParametros(TTabela *tabela, int numeroParametros);
int insereVS(TTabela *tabela, char *id, int nivel_lexico, TPassagem valor_referencia);
int inserePR (TTabela *tabela, char *id, int nivel_lexico, char *rotulo);
int insereFN(TTabela *tabela, char *id, int nivel_lexico, char *rotulo);
int insereRT(TTabela *tabela, char *id, int nivel_lexico, char *rotulo);
TSimbolo *criaSimbolo ();
TSimbolo *procuraSimbolo(TTabela *tabela, char *id, int nivel_lexico, int proc);
void atualizaTipos(TTabela *tabela,TTipo tipo, int n_vars_local);
void atualizaDeslocamento(TTabela *tabela, int n_vars_local);

//=====================================================================================================================
// 						 			 FUNCOES PARA PROCEDURES
//=====================================================================================================================

//=====================================================================================================================
// 						 			 FUNCOES PARA FUNCTIONS
//=====================================================================================================================

void atualizaRetornoFuncao (TTabela *tabela, TTipo tipo, int numeroParametros);

//=====================================================================================================================
// 						 				    FUNÇÕES AUXILIARES
//=====================================================================================================================

void geraArmazena(TSimbolo simbolo);
void geraCarregaValor(TSimbolo simbolo);
void geraCodigoDesvio (char *comando, char *rotulo, int nivel_lexico_destino, int nivel_lexico_chamador);
void atualizaNumVarsLocal(TTabela *tabela, char *procedureName, int varsProc);
void verificaAssinatura(TSimbolo simbolo, TSimbolo simboloProcFunc, int parametrosChamada, int id_num);
