%{
#include "calc.tab.h"
#include "TS.h"
#include "funciones.h"
%}

%%

"ECHO(ON)"                           {yylval.comando = strdup(yytext); return COMANDO; }
"ECHO(OFF)"                          {yylval.comando = strdup(yytext); return COMANDO; }

"HELP"                                {yylval.comando = strdup(yytext); return COMANDO; }
"WORKSPACE"                           {yylval.comando = strdup(yytext); return COMANDO; }
"EXIT"                                {yylval.comando = strdup(yytext); return COMANDO; }
"CLEAR"                               {yylval.comando = strdup(yytext); return COMANDO; }
[a-zA-Z_][a-zA-Z0-9_]*                {
                                        int tipo = tipoIdentificador(yytext);
                                        yylval.variable.cadena = strdup(yytext);
                                        if(tipo==0) return VAR;
                                        else return FUNC;
                                      }

LOAD[ \t]+([a-zA-Z0-9_.\-]+\.txt)     {
                                        yylval.comando = strdup(yytext + 5); // Extraemos el archivo directamente, no se guarda "LOAD "
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
[ \t]+              { /* Ignorar espacios en blanco y tabs */ }
\n                  {return '\n'; }
.                                     { return *yytext; }

<<EOF>> {
    terminar_archivo();
}

%%