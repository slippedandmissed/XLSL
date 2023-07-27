%{
  #include "y.tab.h"
%}

alpha [a-zA-Z_]
digit [0-9]

%%

"import"                    { return IMPORT; }
"namespace"                 { return NAMESPACE; }
"struct"                    { return STRUCT; }
"if"                        { return IF; }
"else"                      { return ELSE; }
"true"                      { return TRUE; }
"false"                     { return FALSE; }
"null"                      { return NULLTOKEN; }
"uint8"                     { return UINT8; }
"int8"                      { return INT8; }
"uint16"                    { return UINT16; }
"int16"                     { return INT16; }
"uint32"                    { return UINT32; }
"int32"                     { return INT32; }
"uint64"                    { return UINT64; }
"int64"                     { return INT64; }
"bool"                      { return BOOL; }
"void"                      { return VOID; }
"return"                    { return RETURN; }
"-"?{digit}+(\.{digit}*)?   { return NUMBER; }
{alpha}({alpha}|{digit})*   { return ID; }
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
"."                         { return DOT; }
\/\/.*                      { ; }
\/\*(.*\n)*.*\*\/           { ; } 
[ \t]*                      { ; }
"\n"                        { ; }
"("                         { return OPENPAREN; }
")"                         { return CLOSEPAREN; }
"{"                         { return OPENCURLY; }
"}"                         { return CLOSECURLY; }

%%

int yywrap() {
  return 1;
}