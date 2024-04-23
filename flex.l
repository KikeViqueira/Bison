%{
#include "calc.tab.h"
#include "TS.h"
#include "funciones.h"

#define RED "\x1b[31m"
#define RESET "\x1b[0m"

%}

%%

"ECHO(ON)"                           {yylval.lexema = strdup(yytext); return COMANDO; }
"ECHO(OFF)"                          {yylval.lexema = strdup(yytext); return COMANDO; }
"HELP"                                {yylval.lexema = strdup(yytext); return COMANDO; }
"WORKSPACE"                           {yylval.lexema = strdup(yytext); return COMANDO; }
"EXIT"                                {yylval.lexema = strdup(yytext); return COMANDO; }
"CLEAR"                               {yylval.lexema = strdup(yytext); return COMANDO; }

[a-zA-Z_][a-zA-Z0-9_]*                {
                                        int tipo = tipoIdentificador(yytext);
                                        yylval.token.cadena = strdup(yytext);  
                                        if(tipo==0) return VAR;
                                        else if (tipo==1) return FUNC;
                                        else return CONS;
                                      }

LOAD[ \t]+([a-zA-Z0-9_.\-]+)".txt"     { 
                                        strtok(yytext, " ");
                                        yytext = strtok(NULL, " "); // Asignamos a yytext el nombre del archivo
                                        yylval.lexema = strdup(yytext); // Guardamos el nombre del archivo                                        
                                        return LOAD; // Retornar un token LOAD a Bison
                                      }

[0-9]+(\.[0-9]*)?([eE][-+]?[0-9]+)?   { yylval.val = atof(yytext); return NUM; }

"="                                   { return '='; }
"**"                                  { return '^'; }
"+"                                   { return '+'; }
"-"                                   { return '-'; }
"*"                                   { return '*'; }
"/"                                   { return '/'; }
"^"                                   { return '^'; }
"("                                   { return '('; }
")"                                   { return ')'; }
";"                                   { return ';'; }
"%"                                   { return '%'; }

[ \t]+              { /* Ignorar espacios en blanco y tabs */ }

\n                  {return '\n'; }

.                   { printf(RED "Error léxico: Caracter no reconocido: %s\n" RESET, yytext);}   

<<EOF>> {
    terminar_archivo();
    return FinalFichero;
}

%%
