%{
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "TS.h"
int yylex();
void yyerror(const char *s);
%}

%union {
    double val; /*Para devolver numeros*/
    struct {
    	char* cadena;
    	double contenido;
    }variable;
}

%token <variable> VAR /*Numero simple*/
%token <val> NUM /*Numero simple*/
%type <val> exp /*Variable y funcion*/


%left '-' '+'
%left '*' '/'
%right NEG /* negación unaria */
%right '^' /* exponenciación */
%nonassoc ';' /* terminador que evita la impresión */

%%

input: /*Cadena vacia*/
      | input line
      ;

line: '\n'
    | exp '\n' { printf ("\t%.10f\n", $1); }
    | exp ';' '\n' {/*No se hace nada*/}
    | asignacion '\n'
    ;

asignacion: VAR '=' exp  { $1.contenido = $3; printf("Asignado: %s = %.10f\n", $1.cadena, $1.contenido); }

exp: NUM { $$ = $1; }
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
    printf("> ");
    while(yyparse());
    return 0;
}
