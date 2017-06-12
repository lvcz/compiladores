#define TAM_TOKEN 16
#define TAM_ROTULO 7

char buffer[1023];
#define geraCodigoArgumentos(rot, fmt, ...) \
  sprintf(buffer, fmt, __VA_ARGS__); \
    geraCodigo(rot, buffer);

typedef enum simbolos {
  simb_program, simb_var, simb_begin, simb_end,
  simb_identificador, simb_numero,
  simb_ponto, simb_virgula, simb_ponto_e_virgula, simb_dois_pontos,
  simb_atribuicao, simb_integer, simb_boolean, simb_abre_parenteses,
  simb_fecha_parenteses, simb_soma,
  simb_subtracao, simb_multiplicacao, simb_divisao, simb_or, simb_and,
  simb_maior_que, simb_menor_que, simb_maior_ou_igual, simb_menor_ou_igual,
  simb_igual, simb_do, simb_while, simb_else, simb_then, simb_if, simb_read,
  simb_write, simb_procedure, simb_function, simb_label, simb_goto, simb_true, simb_false
} simbolos;



/* -------------------------------------------------------------------
 * VARIÁVEIS GLOBAIS
 * ------------------------------------------------------------------- */

extern simbolos simbolo, relacao;
extern char token[TAM_TOKEN];
extern int nivel_lexico;
extern int desloc;
extern int nl;


simbolos simbolo, relacao;
char token[TAM_TOKEN];



