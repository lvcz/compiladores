/* -------------------------------------------------------------------
 *            Arquivo: compilaodr.h
 * -------------------------------------------------------------------
 *              Autor: Bruno Muller Junior
 *               Data: 08/2007
 *      Atualizado em: [15/03/2012, 08h:22m]
 *
 * -------------------------------------------------------------------
 *
 * Tipos, prot�tipos e vai�veis globais do compilador
 *
 * ------------------------------------------------------------------- */

#define TAM_TOKEN 16

typedef enum simbolos { 
  simb_program, simb_var, simb_begin, simb_end, 
  simb_identificador, simb_numero,
  simb_ponto, simb_virgula, simb_ponto_e_virgula, simb_dois_pontos,
  simb_atribuicao, simb_abre_parenteses, simb_fecha_parenteses,
  //s�mbolos adicionados
	simb_mais, simb_menos, simb_or, simb_mult, simb_div, simb_and, simb_igual,
	simb_if, simb_then, simb_else, simb_diff, simb_maior, simb_maior_igual,
	simb_menor, simb_menor_igual, simb_while, simb_do, simb_procedure, simb_integer,
	simb_function, simb_read, simb_write, simb_label, simb_goto, simb_boolean, simb_true,
	simb_false
} simbolos;



/* -------------------------------------------------------------------
 * vari�veis globais
 * ------------------------------------------------------------------- */

extern simbolos simbolo, relacao;
extern char token[TAM_TOKEN];
extern int nivel_lexico;
extern int desloc;
extern int nl;


simbolos simbolo, relacao;
char token[TAM_TOKEN];



/* -------------------------------------------------------------------
 * estruturas e defini��es
 * ------------------------------------------------------------------- */

 //tipos das vari�veis
 typedef enum {
 	indefinido,
 	inteiro,
 	boolean
 } tipo_t;

//categorias dos s�mbolos
 typedef enum {
 	variavel_simples,
 	parametro_formal,
 	funcao,
 	procedimento,
 	label
 } categoria_t;

 typedef struct {
 	tipo_t tipo;
 	int referencia;
 } info_parametros_t;

//defini��o dos s�mbolos que compoem a tabela de s�mbolos
typedef struct simbolo_t {
	char *identificador;
	tipo_t tipo;
	categoria_t categoria;
	int nivel_lexico;
	int deslocamento;
	char *rotulo;
	int referencia;
	int numero_parametros;
	int count_param_chamada;
	info_parametros_t *parametros;
} simbolo_t;

//defini��o da tabela de s�mbolos
typedef struct {
	simbolo_t **simbolos;
	int tamanho; //quantidade de posi��es alocadas
	int topo; //quantidade de posi��es utilizadas
} tabela_simbolos_t;

//defini��o da pilha de r�tulos
typedef struct {
	char **rotulos;
	int tamanho; //quantidade de posi��es alocadas
	int topo; //quantidade de posi��es utilizadas
} pilha_rotulos_t;

//defini��o das vari�veis de controle
typedef struct {
	tabela_simbolos_t *tabela_simbolos;
	tabela_simbolos_t *pilha_proc_func;
	pilha_rotulos_t *rotulos;
	int deslocamento;
	int nivel_lexico;
	tipo_t tipo;
	simbolo_t *destino; //destino das atribui��es
	simbolo_t *origem; //origem das atribui��es
	simbolo_t *simb_aux;
	int prox_rotulo;
	char *rotulo_aux;
	char *saida;
	int numero_parametros;
	int referencia;
	int dentro_funcao; //fun��o ou procedimento
	int verificando_param_chamada_funcao;
	int eh_booleana;
	tipo_t tipo_ultima_operacao;
} controle_t;



/* -------------------------------------------------------------------
 * fun��es
 * ------------------------------------------------------------------- */

//inicia as vari�veis de controle
controle_t *iniciaVariaveisControle();

//cria uma nova tabela de s�mbolos
tabela_simbolos_t *criaTabelaSimbolos();

//cria um novo s�mbolo com os dados passados por par�metro
simbolo_t *criaSimbolo(char *identificador, int deslocamento, int nivel_lexico, categoria_t categoria, tipo_t tipo, char *rotulo, int numero_parametros, int referencia);

//insere s�mbolo na tabela
void insereTabelaSimbolos(tabela_simbolos_t *ts, simbolo_t *simbolo);

//remove e retorna o �ltimo s�mbolo inserido
simbolo_t *removeTabelaSimbolos(tabela_simbolos_t *ts);

//busca s�mbolo e o retorna, caso n�o encontre retorna NULL
simbolo_t *buscaTabelaSimbolos(tabela_simbolos_t *ts, char *identificador, int nivel_lexico);

//gera um r�tulo com n�mero passado por par�metro
char *geraRotulo(int numero);

//inicia uma pilha para armazenar os r�tulos
pilha_rotulos_t *criaPilhaRotulos();

//empilha um r�tulo
void empilhaRotulo(pilha_rotulos_t *pilha, char *rotulo);

//desempilha e retorna o �ltimo r�tulo empilhado
char *desempilhaRotulo(pilha_rotulos_t *pilha);

//remove todas as vari�veis do n�vel l�xico passado por par�metro
int removeVariaveis(tabela_simbolos_t *ts, int nivel_lexico);

//completa informa��es (deslocamento e tipo) dos par�metros
void corrigeParametros(tabela_simbolos_t *ts, tipo_t tipo, int numero_parametros);

//retorna o n�mero de par�metros da fun��o ou procedimento que est� no topo da tabela de s�mbolos
int numeroParametrosFuncProcTopo(tabela_simbolos_t *ts);

//seta deslocamento e tipo de retorno da fun��o
void corrigeFuncao(tabela_simbolos_t *ts, tipo_t tipo, int numero_parametros);