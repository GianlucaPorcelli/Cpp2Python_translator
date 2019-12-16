%option noyywrap nodefault yylineno
NUMBER [0-9]
%{
#include "c++2python.h"
%}
%%


"cin"		{ return CIN; }
"cout"		{ return COUT; }
"else"      { return ELSE; }
"for"       { return FOR; }
"do"       { return DO; }
"while"       { return WHILE; }
"if"        { return IF; }
"int"       { return INT; }
"float"       { return FLOAT; }
"string"       { return STRING; }
"return"    { return RETURN; }

[a-zA-Z_][0-9a-zA-Z_]*   { yylval.i = sym(yytext); return IDENTIFIER; }

0[xX][a-fA-F0-9]+   { yylval.i = parse_int(yytext); return CONSTANT; }
0[0-7]+             { yylval.i = parse_int(yytext); return CONSTANT; }
[0-9]+              { yylval.i = parse_int(yytext); return CONSTANT; }

{NUMBER}+\.{NUMBER}*              { yylval.f = parse_float(yytext); return CONSTANT_F; }
{NUMBER}*\.{NUMBER}+              { yylval.f = parse_float(yytext); return CONSTANT_F; }

\".*\"             { yylval.s = strdup(yytext); return CONSTANT_STRING; }




";"     { return ';'; }
","     { return ','; }
"("     { return '('; }
")"     { return ')'; }
"["     { return '['; }
"]"     { return ']'; }
"{"     { return '{'; }
"}"     { return '}'; }
"!"     { return '!'; }
"*"     { return '*'; }
"/"     { return '/'; }
"+"     { return '+'; }
"-"     { return '-'; }
"<<"    { return SHL_OP; }
">>"    { return SHR_OP; }
">"     { return '>'; }
">="    { return GE_OP; }
"<"     { return '<'; }
"<="    { return LE_OP; }
"=="    { return EQ_OP; }
"!="    { return NE_OP; }
"&&"    { return AND_OP; }
"||"    { return OR_OP; }
"="     { return '='; }
"+="    { return ADD_ASSIGN; }


[ \t\v\r\n\f]   { /* skip */ }

.       { /* ignore bad characters */ }
"#include <iostream>"		{ return LIB1; }
"using namespace std;"		{ return LIB2; }

"//".*            { /* DO NOTHING */ }
[/][*][^*]*[*]+([^*/][^*]*[*]+)*[/]       { /* DO NOTHING */ }


%%
