/****************************************************************************

 c++2python.h:
 Declares the data structure of ast_node, type_node, scope_node, sym_node and
 other functions prototypes which are used through out the building of the compiler.

*****************************************************************************/

#ifndef cpp2python_H_
#define cpp2python_H_

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include "c++2python.tab.h"

/** Parse functions **/

extern int yylex(void);
extern void yyerror(char const *s);
extern int yyparse(void);

/** AST nodes **/

typedef struct ast_node {
    enum {
        AST_LIST,
        AST_FUNCDEF, AST_FUNCHEAD, AST_PARA,
        AST_VAR, 
        AST_COMPOUND_STMT,AST_IN_STMT, AST_OUT_STMT, AST_EXPR_STMT, AST_IF_STMT, AST_FOR_STMT, AST_DO_STMT, AST_WHILE_STMT,
        AST_RETURN_STMT, 
        AST_DEF, AST_S_DEF, AST_F_DEF, AST_DEC, AST_STR, AST_REAL, AST_ASS,
        AST_BINOP, AST_PREFIX, AST_POSTFIX,
        AST_FUNC_CALL,
        AST_ID, AST_CONST,
        AST_TYPE_LIMIT
    } type;
    
    union {
        struct {
            int type;
            struct ast_node *head;
            struct ast_node *tail;
        } list;

        struct {
            int ret_type;
            struct ast_node *funchead;
            struct ast_node *compound_stmt;
        } funcdef;

        struct {
            int sym_name;
            struct ast_node *paras;
        } funchead;

        struct {
            int para_type;
            struct ast_node *var;
        } para;

        struct {
            int sym_name;
			int constant;
        } var;

        struct {
            struct ast_node *defs;
            struct ast_node *stmts;
			struct ast_node *expr;
			
        } compound_stmt;
		
		struct {
            int sym_name;
        } in_stmt;
		
		struct {
            int sym_name;
			char* costante;
        } out_stmt;

        struct {
            struct ast_node *expr;
        } expr_stmt;

        struct {
            struct ast_node *cond;
            struct ast_node *then;
            struct ast_node *els;
        } if_stmt;

        struct {
            struct ast_node *init;
            struct ast_node *cond;
            struct ast_node *incr;
            struct ast_node *body;
        } for_stmt;
		
		struct {
            struct ast_node *stmt;
            struct ast_node *expr;
        } do_stmt;
		
		struct {
			struct ast_node *expr;
            struct ast_node *stmt;
            
        } while_stmt;

        struct {
            struct ast_node *retval;
        } return_stmt;

        struct {
            int def_type;
            struct ast_node *decs;
        } def;
		
		struct {
            int def_type;
            struct ast_node *str;
        } def_s;
		
		struct {
            int def_type;
            struct ast_node *real;
        } def_f;


        struct {
            struct ast_node *var;
            struct ast_node *init;
        } dec;
		
		struct {
            struct ast_node *var;
			char* stringa;
        } str;
		
		struct {
            struct ast_node *var;
			float real;
        } real;

        struct {
            int op;
            struct ast_node *lhs;
            struct ast_node *rhs;
        } binop;

        struct {
            int op;
            struct ast_node *unary;
        } prefix;

        struct {
            int op;
            struct ast_node *unary;
        } postfix;

        struct {
            struct ast_node *postfix;
            struct ast_node *args;
        } func_call;

        struct {
            int sym_name;
        } id;

        struct {
            int number;
        } constant;
		
		
    };
    int type_id;
    char fg;
} ast_node;

typedef ast_node ast_expr;
typedef ast_node ast_list;
typedef ast_node ast_stmt;


struct sym_node
{
  char str[1024];
  int sym_id;
  struct sym_node *next;
};

extern struct sym_node *sym_table;

extern int sym(char const *s);
extern char * symname(int sym_id);
extern int parse_int(char const *s);
extern float parse_float(char const *s);

struct vscope
{
	struct vscope *parent;
	struct vscope_node *list;
};

struct vscope_node
{
    struct vscope *scope;
	int sym_id;
	int type_id;
	struct vscope_node *next;
};

extern struct vscope *current_vscope;

extern void begin_vscope();
extern void vscope_addnode(struct vscope *v, int sym_id, int type_id);
extern void end_vscope();

enum TYPE {FUNC};

struct type_node
{
  int type_id;
  enum TYPE ty;
  struct
    {
      int ret_type;
      int para_num; 
      int para_type[1000];
    } as_func;
  struct type_node *next;
};

extern int int_type(void);
extern int float_type(void);
extern int string_type(void);
extern int func_type(ast_node *funchead);

extern struct type_node* find_type_node(int type_id);

extern struct vscope_node * find_vnode(int sym_id);

extern ast_list *list_new(int type, ast_node *head, ast_list *tail);
extern void list_append(ast_list *first, ast_list *second);

extern ast_node *funcdef_new(int ret_type, ast_node *funchead, ast_stmt *compound_stmt);
extern ast_node *funchead_new(int sym_name, ast_list *paras);
extern ast_node *para_new(int para_type, ast_node *var);
extern ast_node *var_new(int sym_name,int constant);

extern ast_stmt *compound_stmt_new(ast_list *defs, ast_list *stmts, ast_expr *expr);
extern ast_stmt *in_stmt_new(int sym_name);
extern ast_stmt *out_stmt_new(int sym_name, char* costante);
extern ast_stmt *expr_stmt_new(ast_expr *expr);
extern ast_stmt *if_stmt_new(ast_expr *cond, ast_stmt *then, ast_stmt *els);
extern ast_stmt *for_stmt_new(ast_expr *init, ast_expr *cond, ast_expr *incr, ast_stmt *body);
extern ast_stmt *do_stmt_new(ast_stmt *stmt, ast_expr *expr);
extern ast_stmt *while_stmt_new(ast_expr *expr,ast_stmt *stmt );
extern ast_stmt *return_stmt_new(ast_expr *retval);

extern ast_node *def_new(int def_type, ast_list *decs);
extern ast_node *def_s_new(int def_type, ast_node *str);
extern ast_node *def_f_new(int def_type, ast_node *real);

extern ast_node *dec_new(ast_node *var, ast_node *init);
extern ast_node *str_new(ast_node *var, char* stringa);
extern ast_node *real_new(ast_node *var, float real);

extern ast_expr *binop_new(int op, ast_expr *lhs, ast_expr *rhs);
extern ast_expr *prefix_new(int op, ast_expr *unary);
extern ast_expr *postfix_new(int op, ast_expr *unary);
extern ast_expr *func_call_new(ast_expr *postfix, ast_list *args);
extern ast_expr *id_new(int sym_name);
extern ast_expr *const_new(int number);

/** Declarations **/

extern void set_parse_tree(ast_node *tree);
extern void print_ast(ast_node *n);
extern void report_error(const char *fmt, ...);
extern void check_ast(ast_node *n);
extern void check_semantics(ast_node *ast);
extern void trans_ast(ast_node *ast);
extern void transtext_ast(ast_node *ast);

extern int binop_reuse(int op);

#endif
