%{
#include "calc.tab.h"
#include "TS.h"
%}

%%
[a-zA-Z_][a-zA-Z0-9_]*                { yylval.variable.cadena = strdup(yytext); return VAR; }
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



%%

