%{
#include "c++2python.h"
%}
%locations
%define parse.error verbose
%union{
    int i;
    struct ast_node *n;
	char* s;
	float f;
}

%left  <i> SHL_OP SHR_OP
%left  <i> LE_OP GE_OP
%left  <i> EQ_OP NE_OP
%left  <i> AND_OP
%left  <i> OR_OP
%right <i> ADD_ASSIGN

%token <i> IDENTIFIER CONSTANT 
%token<s> CONSTANT_STRING
%token<f> CONSTANT_F


%token INT FLOAT STRING CIN COUT 
%token IF ELSE FOR CONTINUE BREAK RETURN READ DO WHILE

%token EXTDEFS PARAS STMTS DEFS DECS ARGS LIB1 LIB2

%type <n> extdef  func para var def dec init
%type <n> expr assignment logical_or logical_and equality relational shift additive multi unary postfix primary
%type <n> program extdefs paras stmts defs decs args str real
%type <n> stmt compound_stmt compound_stmt_func in_stmt out_stmt expr_stmt selection_stmt iteration_stmt jump_stmt do_stmt while_stmt

%start program

%%

program
  : /* empty */   { set_parse_tree($$ = NULL); }
  | LIB1 LIB2 extdefs       { set_parse_tree($$ = $3); }
  ;

extdefs
  : extdef          { $$ = list_new(EXTDEFS, $1, NULL); }
  | extdefs extdef  { list_append($$ = $1, list_new(EXTDEFS, $2, NULL)); }
  ;

extdef
  : def                         { $$ = $1; }
  | INT    func compound_stmt_func   { $$ = funcdef_new(int_type(), $2, $3); }
  | FLOAT    func compound_stmt_func   { $$ = funcdef_new(float_type(), $2, $3); }
  | STRING    func compound_stmt_func   { $$ = funcdef_new(string_type(), $2, $3); }
  ;


func
  : IDENTIFIER '(' paras ')'  { $$ = funchead_new($1, $3); }
  | IDENTIFIER '('       ')'  { $$ = funchead_new($1, NULL); }
  ;

paras
  : para            { $$ = list_new(PARAS, $1, NULL); }
  | paras ',' para  { list_append($$ = $1, list_new(PARAS, $3, NULL)); }
  ;

para
  : INT    var  { $$ = para_new(int_type(), $2); }
  | FLOAT    var  { $$ = para_new(float_type(), $2); }
  | STRING    var  { $$ = para_new(string_type(), $2); }
  ;

var
  : IDENTIFIER            { $$ = var_new($1, 0); }
  | IDENTIFIER '[' CONSTANT ']'  { $$ = var_new($1, $3); }
  ;

stmts
  : stmt        { $$ = list_new(STMTS, $1, NULL); }
  | stmts stmt  { list_append($$ = $1, list_new(STMTS, $2, NULL)); }
  ;

stmt
  : compound_stmt   { $$ = $1; }
  | in_stmt			{ $$ = $1; }
  | out_stmt		{ $$ = $1; }
  | expr_stmt       { $$ = $1; }
  | selection_stmt  { $$ = $1; }
  | iteration_stmt  { $$ = $1; }
  | do_stmt  { $$ = $1; }
  | while_stmt  { $$ = $1; }
  | jump_stmt       { $$ = $1; }
  | defs			{ $$ = $1; }
  ;

compound_stmt
  : '{' defs stmts '}'  { $$ = compound_stmt_new($2, $3, NULL); }
  | '{' defs       '}'  { $$ = compound_stmt_new($2, NULL, NULL); }
  | '{'      stmts '}'  { $$ = compound_stmt_new(NULL, $2,  NULL); }
  | '{'            '}'  { $$ = compound_stmt_new(NULL, NULL,  NULL); }
  | ';'                 { $$ = compound_stmt_new(NULL, NULL, NULL); }
  
  ;
compound_stmt_func
  : compound_stmt                      { $$ = $1; }
  | '{' defs stmts RETURN expr ';''}'  { $$ = compound_stmt_new($2, $3,  $5); }
  | '{' defs       RETURN expr ';''}'  { $$ = compound_stmt_new($2, NULL,  $4); }
  | '{'      stmts RETURN expr ';''}'  { $$ = compound_stmt_new(NULL, $2,  $4); }
  | '{'            RETURN expr ';''}'  { $$ = compound_stmt_new(NULL, NULL,  $3); }  
  ;
  
jump_stmt
  : RETURN expr ';'   { $$ = return_stmt_new($2); }
  ;
  
in_stmt
  : CIN SHR_OP IDENTIFIER ';' { $$ = in_stmt_new($3); }
  ;
  
out_stmt
  : COUT SHL_OP IDENTIFIER ';' { $$ = out_stmt_new($3,NULL); }
  | COUT SHL_OP CONSTANT_STRING ';' { $$ = out_stmt_new(0,$3); }
  ;

expr_stmt
  : expr ';'  { $$ = expr_stmt_new($1); }
  ;

selection_stmt
  : IF '(' expr ')' stmt            { $$ = if_stmt_new($3, $5, NULL); }
  | IF '(' expr ')' stmt ELSE stmt  { $$ = if_stmt_new($3, $5, $7); }
  ;

iteration_stmt
  : FOR '(' expr ';' expr ';' expr ')' stmt   { $$ = for_stmt_new($3,   $5,   $7,   $9); }
  | FOR '(' expr ';' expr ';'      ')' stmt   { $$ = for_stmt_new($3,   $5,   NULL, $8); }
  | FOR '(' expr ';'      ';' expr ')' stmt   { $$ = for_stmt_new($3,   NULL, $6,   $8); }
  | FOR '(' expr ';'      ';'      ')' stmt   { $$ = for_stmt_new($3,   NULL, NULL, $7); }
  | FOR '('      ';' expr ';' expr ')' stmt   { $$ = for_stmt_new(NULL, $4,   $6,   $8); }
  | FOR '('      ';' expr ';'      ')' stmt   { $$ = for_stmt_new(NULL, $4,   NULL, $7); }
  | FOR '('      ';'      ';' expr ')' stmt   { $$ = for_stmt_new(NULL, NULL, $5,   $7); }
  | FOR '('      ';'      ';'      ')' stmt   { $$ = for_stmt_new(NULL, NULL, NULL, $6); }
  ;

do_stmt
  : DO stmt WHILE '(' expr ')' ';'   { $$ = do_stmt_new($2,   $5); }
  ;
  
while_stmt
  : WHILE '(' expr ')'stmt    { $$ = while_stmt_new($3,   $5); }
  ;

defs
  : def       { $$ = list_new(DEFS, $1, NULL); }
  | defs def  { list_append($$ = $1, list_new(DEFS, $2, NULL)); }
  ;

def
  : INT    decs ';'    		{ $$ = def_new(int_type(), $2); }
  | FLOAT   real ';'  		{ $$ = def_f_new(float_type(), $2); }
  | STRING    str ';'  	{ $$ = def_s_new(string_type(), $2); }
  ;

real
  : var           { $$ = real_new($1, 0); }
  | var '=' CONSTANT_F  { $$ = real_new($1, $3); }
  | var '=' CONSTANT  { $$ = real_new($1, $3); }
  ;
  
str
  : var           { $$ = str_new($1, NULL); }
  | var '=' CONSTANT_STRING  { $$ = str_new($1, $3); }
  ;
  

decs
  : dec           { $$ = list_new(DECS, $1, NULL); }
  | decs ',' dec  { list_append($$ = $1, list_new(DECS, $3, NULL)); }
  ;

dec
  : var           { $$ = dec_new($1, NULL); }
  | var '=' init  { $$ = dec_new($1, $3); }
  ;

init
  : expr                { $$ = $1; }
  ;

expr
  : assignment  { $$ = $1; }
  ;

assignment
  : logical_or                      { $$ = $1; }
  | unary  '='         assignment   { $$ = binop_new('=', $1, $3); }
  | unary  ADD_ASSIGN  assignment   { $$ = binop_new(ADD_ASSIGN, $1, $3); }
  ;

logical_or
  : logical_and                   { $$ = $1; }
  | logical_or OR_OP logical_and  { $$ = binop_new(OR_OP, $1, $3); }
  ;

logical_and
  : equality                      { $$ = $1; }
  | logical_and AND_OP equality   { $$ = binop_new(AND_OP, $1, $3); }
  ;

equality
  : relational                  { $$ = $1; }
  | equality EQ_OP relational   { $$ = binop_new(EQ_OP, $1, $3); }
  | equality NE_OP relational   { $$ = binop_new(NE_OP, $1, $3); }
  ;

relational
  : shift                   { $$ = $1; }
  | relational '>'   shift  { $$ = binop_new('>', $1, $3); }
  | relational GE_OP shift  { $$ = binop_new(GE_OP, $1, $3); }
  | relational '<'   shift  { $$ = binop_new('<', $1, $3); }
  | relational LE_OP shift  { $$ = binop_new(LE_OP, $1, $3); }
  ;

shift
  : additive                { $$ = $1; }
  ;

additive
  : multi               { $$ = $1; }
  | additive '+' multi  { $$ = binop_new('+', $1, $3); }
  | additive '-' multi  { $$ = binop_new('-', $1, $3); }
  ;

multi
  : unary             { $$ = $1; }
  | multi '*' unary   { $$ = binop_new('*', $1, $3); }
  | multi '/' unary   { $$ = binop_new('/', $1, $3); }
  ;

unary
  : postfix       { $$ = $1; }
  | '!' unary     { $$ = prefix_new('!', $2); }
  ;

postfix
  : primary                 { $$ = $1; }
  | postfix '(' args ')'    { $$ = func_call_new($1, $3); }
  | postfix '('      ')'    { $$ = func_call_new($1, NULL); }
  ;

primary
  : IDENTIFIER    { $$ = id_new($1); }
  | CONSTANT      { $$ = const_new($1); }
  | CONSTANT_F      { $$ = const_new($1); }
  | '(' expr ')'  { $$ = $2; }
  ;

args
  : expr            { $$ = list_new(ARGS, $1, NULL); }
  | args ',' expr   { list_append($$ = $1, list_new(ARGS, $3, NULL)); }
  ;
