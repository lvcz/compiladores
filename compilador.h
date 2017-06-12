/* -------------------------------------------------------------------
 *            Arquivo: compilaodr.h
 * -------------------------------------------------------------------
 *              Autor: Bruno Muller Junior
 *               Data: 08/2007
 *      Atualizado em: [15/03/2012, 08h:22m]
 *
 * -------------------------------------------------------------------
 *
 * Tipos, protótipos e vaiáveis globais do compilador
 *
 * ------------------------------------------------------------------- */

#define TAM_TOKEN 16

typedef enum simbolos { 
  simb_program, simb_var, simb_begin, simb_end, 
  simb_identificador, simb_numero,
  simb_ponto, simb_virgula, simb_ponto_e_virgula, simb_dois_pontos,
  simb_atribuicao, simb_abre_parenteses, simb_fecha_parenteses,
  //símbolos adicionados
	simb_mais, simb_menos, simb_or, simb_mult, simb_div, simb_and, simb_igual,
	simb_if, simb_then, simb_else, simb_diff, simb_maior, simb_maior_igual,
	simb_menor, simb_menor_igual, simb_while, simb_do, simb_procedure, simb_integer,
	simb_function, simb_read, simb_write, simb_label, simb_goto, simb_boolean, simb_true,
	simb_false
} simbolos;



/* -------------------------------------------------------------------
 * variáveis globais
 * ------------------------------------------------------------------- */

extern simbolos simbolo, relacao;
extern char token[TAM_TOKEN];
extern int nivel_lexico;
extern int desloc;
extern int nl;


simbolos simbolo, relacao;
char token[TAM_TOKEN];



/* -------------------------------------------------------------------
 * estruturas e definições
 * ------------------------------------------------------------------- */

 //tipos das variáveis
 typedef enum {
 	indefinido,
 	inteiro,
 	boolean
 } tipo_t;

//categorias dos símbolos
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

//definição dos símbolos que compoem a tabela de símbolos
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

//definição da tabela de símbolos
typedef struct {
	simbolo_t **simbolos;
	int tamanho; //quantidade de posições alocadas
	int topo; //quantidade de posições utilizadas
} tabela_simbolos_t;

//definição da pilha de rótulos
typedef struct {
	char **rotulos;
	int tamanho; //quantidade de posições alocadas
	int topo; //quantidade de posições utilizadas
} pilha_rotulos_t;

//definição das variáveis de controle
typedef struct {
	tabela_simbolos_t *tabela_simbolos;
	tabela_simbolos_t *pilha_proc_func;
	pilha_rotulos_t *rotulos;
	int deslocamento;
	int nivel_lexico;
	tipo_t tipo;
	simbolo_t *destino; //destino das atribuições
	simbolo_t *origem; //origem das atribuições
	simbolo_t *simb_aux;
	int prox_rotulo;
	char *rotulo_aux;
	char *saida;
	int numero_parametros;
	int referencia;
	int dentro_funcao; //função ou procedimento
	int verificando_param_chamada_funcao;
	int eh_booleana;
	tipo_t tipo_ultima_operacao;
} controle_t;



/* -------------------------------------------------------------------
 * funções
 * ------------------------------------------------------------------- */

//inicia as variáveis de controle
controle_t *iniciaVariaveisControle();

//cria uma nova tabela de símbolos
tabela_simbolos_t *criaTabelaSimbolos();

//cria um novo símbolo com os dados passados por parâmetro
simbolo_t *criaSimbolo(char *identificador, int deslocamento, int nivel_lexico, categoria_t categoria, tipo_t tipo, char *rotulo, int numero_parametros, int referencia);

//insere símbolo na tabela
void insereTabelaSimbolos(tabela_simbolos_t *ts, simbolo_t *simbolo);

//remove e retorna o último símbolo inserido
simbolo_t *removeTabelaSimbolos(tabela_simbolos_t *ts);

//busca símbolo e o retorna, caso não encontre retorna NULL
simbolo_t *buscaTabelaSimbolos(tabela_simbolos_t *ts, char *identificador, int nivel_lexico);

//gera um rótulo com número passado por parâmetro
char *geraRotulo(int numero);

//inicia uma pilha para armazenar os rótulos
pilha_rotulos_t *criaPilhaRotulos();

//empilha um rótulo
void empilhaRotulo(pilha_rotulos_t *pilha, char *rotulo);

//desempilha e retorna o último rótulo empilhado
char *desempilhaRotulo(pilha_rotulos_t *pilha);

//remove todas as variáveis do nível léxico passado por parâmetro
int removeVariaveis(tabela_simbolos_t *ts, int nivel_lexico);

//completa informações (deslocamento e tipo) dos parâmetros
void corrigeParametros(tabela_simbolos_t *ts, tipo_t tipo, int numero_parametros);

//retorna o número de parâmetros da função ou procedimento que está no topo da tabela de símbolos
int numeroParametrosFuncProcTopo(tabela_simbolos_t *ts);

//seta deslocamento e tipo de retorno da função
void corrigeFuncao(tabela_simbolos_t *ts, tipo_t tipo, int numero_parametros);