%{
  #include "node_types.h"
  #include "y.tab.h"
%}

alpha [a-zA-Z_]
digit [0-9]

%%

"import"                    { return IMPORT; }
"namespace"                 { return NAMESPACE; }
"struct"                    { return STRUCT; }
"self"                      { return SELF; }
"true"                      { return TRUE; }
"false"                     { return FALSE; }
"text"                      { return TEXT; }
"number"                    { return NUMBERTOKEN; }
"logical"                   { return LOGICAL; }
"void"                      { return VOID; }
"return"                    { return RETURN; }
{digit}+(\.{digit}*)?       { yylval.tokenText = malloc(sizeof(yytext)); strcpy(yylval.tokenText, (yytext)); return NUMBER; }
{alpha}({alpha}|{digit})*   { yylval.tokenText = malloc(sizeof(yytext)); strcpy(yylval.tokenText, (yytext)); return ID; }
"+"                         { return PLUS; }
"-"                         { return MINUS; }
"*"                         { return TIMES; }
"/"                         { return DIVIDE; }
"=="                        { return EQ; }
"!="                        { return NEQ; }
"<"                         { return LT; }
">"                         { return GT; }
"<="                        { return LE; }
">="                        { return GE; }
"&&"	                      { return AND; }
"||"	                      { return OR; }
"!"	                        { return NOT; }
"="                         { return ASSIGN; }
","                         { return COMMA; }
";"                         { return SEMICOLON; }
":"                         { return COLON; }
"?"                         { return QUESTION; }
"."                         { return DOT; }
\/\/.*                      { ; }
\/\*(.*\n)*.*\*\/           { ; } 
[ \t]*                      { ; }
"\n"                        { ; }
\"(\\.|[^\\"])*\"           { yylval.tokenText = malloc(sizeof(yytext)); strcpy(yylval.tokenText, (yytext)); return DOUBLEQUOTEDSTRING; }
\'(\\.|[^\\'])*\'           { yylval.tokenText = malloc(sizeof(yytext)); strcpy(yylval.tokenText, (yytext)); return SINGLEQUOTEDSTRING; }
"("                         { return OPENPAREN; }
")"                         { return CLOSEPAREN; }
"{"                         { return OPENCURLY; }
"}"                         { return CLOSECURLY; }

%%

int yywrap() {
  return 1;
}