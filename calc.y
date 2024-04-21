%{
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "TS.h"
#include "funciones.h"
int yylex();
void yyerror(const char *s);

int echo=1; /*Variable la cual nos dira si el output se muestra o no
1-> se muestra a no se que se acaba en ;
0-> No se muestra nunca el output
NOTA: Este el echo activado o no la salida de los distintos comandos siempre se mostrarán por pantalla*/
%}

%union {
    double val; /*Para devolver numeros*/
    char *comando; /*Para saber que comando se ha introducido por terminal*/
    struct {
    	char* cadena;
    	double contenido;
    	double (*fnctptr)();
    }variable;
}

%token <variable> FUNC /*Variable recibida*/
%token <variable> VAR /*Variable recibida*/
%token <val> NUM /*Numero simple recibido*/
%token <comando> COMANDO /*Comando recibido*/
%token <comando> LOAD /*Comando recibido*/
%type <val> exp /*Variable y funcion*/
%type <variable> asignacion /*Indicamos el tipo de la variable asignacion*/
%type <variable> funcion /*Indicamos el tipo de la variable asignacion*/


%left '-' '+'
%left '*' '/'
%right NEG /* negación unaria */
%right '^' /* exponenciación */
%nonassoc ';' /* terminador que evita la impresión */

%%

input: /*Cadena vacia*/
      | input line {printf("> ");}
      ;

line: '\n'
    | exp '\n' {if(echo==1) printf ("\t%.2f\n", $1); }
    | exp ';' '\n' {/*No se hace nada*/}
    | asignacion '\n' {if(echo==1) printf("Asignado: %s = %.2f\n", $1.cadena, $1.contenido);}
    | asignacion ';' '\n' {/*No se hace nada*/}
    | comando '\n'
    | funcion '\n' {if(echo==1) printf("Resultado obtenido con %s -> %.2f\n", $1.cadena ,$1.contenido);}

    ;

comando: COMANDO {
	if (strcmp($1, "HELP")==0){
		printf("Mostrar ayuda:\n 1. HELP\n 2. EXIT\n 3. CLEAR\n 4. WORKSPACE\n 5. LOAD fichero\n 6. ECHO(ON/OFF)\n");
	}else if(strcmp($1, "EXIT")==0){
		 printf("Exit: Salir del programa.\n"); liberarTS(); finalizarLexico(); exit(0);
	}else if(strcmp($1, "CLEAR")==0){
		clear(); /*Eliminamos de la TS y liberamos su memoria, las variables, ya que si eliminamos las funciones al ser estáticas después no se podrán usar*/
	}else if(strcmp($1, "WORKSPACE")==0){
		imprimirTablaSimbolos(); /*Imprimimos nuestro entorno de trabajo, es decir, la tabla de simbolos*/
	}else if(strcmp($1, "ECHO(ON)")==0){/*En el caso de que echo se ponga en ON (esta activado por defecto) se mostrará el output a no ser que se acaba en ;*/
		echo=1;
	}else{
		echo=0; /*En cualquier otro caso sabemos que estamos en el caso de desactivar el echo, no se mostrará nunca el output*/
	}
   	}
   	| LOAD {
   		leer_archivo($1);
   	}

	;

asignacion: VAR '=' exp  {
		if(!isnan($3)){ /*Si la expresion recibida es un número, podemos realizar la asignación*/
			$1.contenido = $3;
			buscarVariable($1.cadena, $1.contenido); /*Buscamos el lexema en la TS, si no esta lo metemos y si está modificamos su valor*/
			$$=$1;
		}
		else printf("No se puede hacer la asignación\n");
	 }
	 | VAR '=' funcion {
		 if(!isnan($3.contenido)){
			$1.contenido = $3.contenido;
			buscarVariable($1.cadena, $1.contenido); /*Buscamos el lexema en la TS, si no esta lo metemos y si está modificamos su valor*/
			$$=$1;
		}
		else printf("No se puede hacer la asignación\n");

	 }
	 ;

funcion: FUNC '(' exp ')' {
	if(!isnan($3)){ /*Si la expresión es distinta de NAN, proecedemos a mirar si existe la función que se ha reconocido*/
		$1.fnctptr = recuperarContenidoFuncion($1.cadena); /*Pedimos a TS.c que nos devuelva el valor de la función*/
		int bandera = getValor(); /*Mirar valor bandera de la TS, y hacer el respectivo comportamiento*/
		if (bandera == 1){ /*La función está en la TS y hemos recuperado su correspondiente valor*/
			printf("Valor recuperado de %s en la TS -> %p\n",$1.cadena,$1.fnctptr);
			$$.contenido=(*($1.fnctptr))($3);
			$$.cadena=$1.cadena;
			$$.fnctptr=$1.fnctptr;
		}
		else{ /*La función no está en la TS, por lo que daremos un error por pantalla de que la función solicitada no se ha encontrado*/
			printf("La función %s no se ha encontrado en la TS\n",$1.cadena);
			setValor(1); /*Activamos la bandera para que la siguiente variable introducida se analice de la misma manera*/
			$$.contenido=NAN;
		}
	}
	else printf("El argumento de la función no es un número o no está definido\n");
	}
	;

exp: NUM { $$ = $1; }
    | VAR {
      	   	$1.contenido = recuperarContenidoVariable($1.cadena); /*Pedimos a TS.c que nos devuelva el valor de la variable*/
      	   	int bandera = getValor(); /*Mirar valor bandera de la TS, y hacer el respectivo comportamiento*/
      	   	if (bandera == 1){ /*La variable está en la TS y hemos recuperado su correspondiente valor*/
      	   		printf("Valor recuperado de %s en la TS -> %.2f\n",$1.cadena,$1.contenido);
      	   		$$=$1.contenido;
      	   	}
      	   	else{ /*La variable no está en la TS, por lo que daremos un error por pantalla de que la variable solicitada no se ha encontrado*/
      	   		printf("La variable %s no se ha encontrado en la TS\n",$1.cadena);
      	   		setValor(1); /*Activamos la bandera para que la siguiente variable introducida se analice de la misma manera*/
      	   		$$=NAN;
      	   	}
      	   }
    | exp '+' exp { $$ = $1 + $3; }
    | exp '-' exp { $$ = $1 - $3; }
    | exp '*' exp { $$ = $1 * $3; }
    | exp '/' exp { $$ = $1 / $3; }
    | '-' exp %prec NEG { $$ = -$2; }
    | exp '^' exp { $$ = pow($1, $3); }
    | '(' exp ')' { $$ = $2; }
    ;

%%



void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main() {
    initTS();
    printf("> ");
    while(yyparse());
    liberarTS(); /*Liberamos los recursos consumidos por la TS*/
    return 0;
}
