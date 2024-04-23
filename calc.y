%{
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "TS.h"
#include "funciones.h"

#define RED     "\x1b[31m"
#define RESET   "\x1b[0m"

extern FILE *yyin;
int yylex();
void yyerror(const char *s);
extern void liberarMemoria();
extern char* yytext;

int echo=1; /*Variable la cual nos dira si el output se muestra o no
1-> se muestra a no se que se acaba en ;
0-> No se muestra nunca el output
NOTA: Este el echo activado o no la salida de los distintos comandos siempre se mostrarán por pantalla*/


int procesandoArchivo=0; /*Variable la cual nos dira si el estamos procesando el contenido de un archivo o no
1-> estamos procesando un archivo
0-> no estamos procesando un archivo
Inicialmente no estamos procesando un archivo, por lo que la bandera es 0*/
%}

%union {
    double val; /*Para devolver numeros*/
    char *lexema; /*Para saber que comando se ha introducido por terminal*/
    struct {
    	char* cadena;
    	double contenido;
    }token; /*Para devolver variables y funciones*/
		
}

%token <lexema> FUNC /*Función recibida*/
%token <token> VAR /*Variable recibida*/
%token <token> CONS /*Constante recibida*/
%token <val> NUM /*Numero simple recibido*/
%token FinalFichero /*End of file de fichero recibido*/
%token <lexema> COMANDO /*Comando recibido*/
%token <lexema> LOAD /*Comando recibido*/
%type <val> exp /*Variable*/
%type <token> asignacion /*Indicamos el tipo de la variable asignacion*/
%type <token> funcion /*Indicamos el tipo de la variable funcion*/


%left '-' '+'
%left '*' '/'
%right NEG /* negación unaria */
%right '^' /* exponenciación */
%nonassoc ';' /* terminador que evita la impresión */

%%

input: /*Cadena vacia*/
      | input line { 
										if(procesandoArchivo) printf(">> "); //Diferenciando asi los printfs, podemos distinguir si estamos en un archivo o no
										else printf("> ");
										} /*Liberamos las direcciones de memoria usadas en la línea*/
			| input FinalFichero {
									  printf("Archivo introducido por terminal correctamente procesado\n"); 
										procesandoArchivo=0; 
										printf("> "); 
										}
      ;

line: '\n'
    | exp '\n' {if(echo==1 && !isnan($1)) printf ("Resultado de la expresión -> %.2f\n", $1); } /*Mostramos el valor de la asignación si el echo esta activado y tiene un valor distinto de NaN*/
    | exp ';' '\n' {/*No se hace nada*/}
    | asignacion '\n' {if(echo==1 && !isnan($1.contenido)) printf("Asignado: %s = %.2f\n", $1.cadena, $1.contenido); free($1.cadena); } 
    | asignacion ';' '\n' {free($1.cadena);}
    | comando '\n'
    | funcion '\n' {if(echo==1 && !isnan($1.contenido)) printf("Resultado obtenido con %s -> %.2f\n", $1.cadena ,$1.contenido); free($1.cadena);}
		| funcion ';' '\n' {free($1.cadena);}
		| error '\n' {yyerrok;}
    ;

comando: COMANDO {
	if (strcmp($1, "HELP")==0){
		help(); /*Mostramos la ayuda*/
	}
	else if(strcmp($1, "EXIT")==0){
		 printf("Exit: Salir del programa.\n");
		 if(yyin!=stdin && yyin !=NULL){ //Este if se hace por si acaso se ha ejecutado un EXIT dentro de un archivo, asi nos aseguramos de liberar la memoria
				fclose(yyin);
				yyin=NULL;
		 } 
		 free($1); liberarTS(); finalizarLexico(); exit(0);
	}
	else if(strcmp($1, "CLEAR")==0){
		clear(); /*Eliminamos de la TS y liberamos su memoria, las variables, ya que si eliminamos las funciones al ser estáticas después no se podrán usar*/
	}
	else if(strcmp($1, "WORKSPACE")==0){
		imprimirTablaSimbolos(); /*Imprimimos nuestro entorno de trabajo, es decir, la tabla de simbolos*/
	}
	else if(strcmp($1, "ECHO(ON)")==0){/*En el caso de que echo se ponga en ON (esta activado por defecto) se mostrará el output a no ser que se acaba en ;*/
		echo=1;
	}
	else{
		echo=0; /*En cualquier otro caso sabemos que estamos en el caso de desactivar el echo, no se mostrará nunca el output*/
	}
	free($1);
	}
	| LOAD {
		procesandoArchivo=1; /*Activamos la bandera de que estamos procesando un archivo*/
		leer_archivo($1);
		free($1);
	}
	;

asignacion: VAR '=' exp  {
		if(!isnan($3)){ /*Si la expresion recibida es un número, podemos realizar la asignación*/
			$1.contenido = $3;
			int valida = buscarVariable($1.cadena, $1.contenido); /*Buscamos el lexema en la TS, si no esta lo metemos y si está modificamos su valor*/
			if(valida==1) $$=$1;
			else{
				printf(RED"El nombre de la variable coincide con la de una función o constante\n"RESET);
				$$.contenido=NAN;
				free($1.cadena);
			}
		}
		else printf(RED"No se puede hacer la asignación de la expresión a la variable\n"RESET);
	 }
	 | VAR '=' funcion {
		 if(!isnan($3.contenido)){
			$1.contenido = $3.contenido;
			buscarVariable($1.cadena, $1.contenido); /*Buscamos el lexema en la TS, si no esta lo metemos y si está modificamos su valor*/
			$$=$1;
		}
		else printf(RED"No se pudo asignar el resultado de la función a la variable\n"RESET);
		free($3.cadena);
	 }

	 /*Tenemos que diseñar los casos en los que se le intente asignar un valor a una constante, ya sea una expresión o el resultado de una función*/
	 | CONS '=' exp {
		 printf(RED"No se puede asignar una expresión a una constante\n"RESET); $$.contenido=NAN;
	 }
	 | CONS '=' funcion {
		 printf(RED"No se puede asignar el resultado de una función a una constante\n"RESET); $$.contenido=NAN; free($3.cadena);
	 }
	 ;


funcion: FUNC '(' exp ')' {
	if(!isnan($3)){ /*Si la expresión es distinta de NAN, proecedemos a mirar si existe la función que se ha reconocido*/
		double(*funcion)() = recuperarContenidoFuncion($1); /*Pedimos a TS.c que nos devuelva el valor de la función*/
		int bandera = getValor(); /*Mirar valor bandera de la TS, y hacer el respectivo comportamiento*/
		if (bandera == 1){ /*La función está en la TS y hemos recuperado su correspondiente valor*/
			printf("Valor recuperado de %s en la TS -> %p\n",$1, funcion);
			$$.contenido=funcion($3);
			$$.cadena = $1;
		}
		else{ /*La función no está en la TS, por lo que daremos un error por pantalla de que la función solicitada no se ha encontrado*/
			printf(RED"La función %s no se ha encontrado en la TS\n"RESET,$1);
			setValor(1); /*Activamos la bandera para que la siguiente variable introducida se analice de la misma manera*/
			$$.cadena = $1;
			$$.contenido=NAN;
		}
	}
	else printf(RED"El argumento de la función no es un número o es una variable que no está definido\n"RESET);
	
	}
	;

exp: NUM { $$ = $1; }
    | VAR {
      	   	$1.contenido = recuperarContenidoVarCons($1.cadena); /*Pedimos a TS.c que nos devuelva el valor de la variable*/
      	   	int bandera = getValor(); /*Mirar valor bandera de la TS, y hacer el respectivo comportamiento*/
      	   	if (bandera == 1){ 
							/*La variable está en la TS y hemos recuperado su correspondiente valor*/
      	   		printf("Valor recuperado de %s en la TS -> %.2f\n",$1.cadena,$1.contenido);
      	   		$$=$1.contenido;
      	   	}
      	   	else{ /*La variable no está en la TS, por lo que daremos un error por pantalla de que la variable solicitada no se ha encontrado*/
      	   		printf(RED"La variable %s no se ha encontrado en la TS\n"RESET,$1.cadena);
      	   		setValor(1); /*Activamos la bandera para que la siguiente variable introducida se analice de la misma manera*/
      	   		$$=NAN;
      	   	}
						free($1.cadena); /*Liberamos la memoria de la cadena que hemos usado*/
      	   }
		| CONS {
      $1.contenido = recuperarContenidoVarCons($1.cadena); /*Pedimos a TS.c que nos devuelva el valor de la variable*/
			/*En el caso de que sea una constante, siempre entraremos aquí ya que las constantes siempre están en la TS
			*/
			printf("Valor recuperado de %s en la TS -> %.2f\n",$1.cadena,$1.contenido);
			$$=$1.contenido;
			free($1.cadena); /*Liberamos la memoria de la cadena que hemos usado*/
		}			 
    | exp '+' exp { $$ = $1 + $3; }
    | exp '-' exp { $$ = $1 - $3; }
    | exp '*' exp { $$ = $1 * $3; }
    | exp '/' exp {
										if($3==0){
											printf(RED"No se puede dividir entre 0\n"RESET);
											$$=NAN;
										}
										else $$ = $1 / $3; 
									}
		| exp '%' exp {
										if($3==0){
											printf(RED"No se puede hacer el módulo entre 0\n"RESET);
											$$=NAN;
										}
										else $$ = fmod($1, $3); 
									}							
    | '-' exp %prec NEG { $$ = -$2; }
    | exp '^' exp { $$ = pow($1, $3); }
    | '(' exp ')' { $$ = $2; }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, RED"Error: %s\n"RESET, s);
}

int main() {
    initTS();
    printf("> ");
    yyparse(); 
    liberarTS(); /*Liberamos los recursos consumidos por la TS*/
		finalizarLexico(); /*Liberamos los recursos consumidos por el analizador lexico*/
    return 0;
}
