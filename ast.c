/****************************************************************************

 ast.c:
 Implements functions required for building the AST, type table, symbol table
 and scopes. 

*****************************************************************************/


#include "c++2python.h"

/* symble table */

static int last_sym_id = 0;

struct sym_node *sym_table = NULL;

struct sym_node* new_sym_node(const char *s, struct sym_node *next)
{
    struct sym_node *p = malloc(sizeof(struct sym_node));
    strcpy(p->str, s);
    p->sym_id = ++last_sym_id;//value post increment
    p->next = next;
    return p;
}

int sym(const char *s)
{
    for (struct sym_node *p = sym_table; p; p = p->next)
        if (strcmp(s, p->str) == 0) return p->sym_id;

    sym_table = new_sym_node(s, sym_table);
    return sym_table->sym_id;
}

char* symname(int sym_id)
{
    for (struct sym_node *p = sym_table; p; p = p->next)
    {
        if (p->sym_id == sym_id) return p->str;
    }
    report_error("sym_id %d not found", sym_id);
    return NULL;
}

/* variable and function scope */

struct vscope *current_vscope = NULL;

void begin_vscope()
{
    struct vscope *new_vscope = malloc(sizeof(struct vscope));
    new_vscope->parent = current_vscope;
    new_vscope->list = NULL;
    current_vscope = new_vscope;
}

void vscope_addnode(struct vscope *v, int sym_id, int type_id)
{
    struct vscope_node *n = malloc(sizeof(struct vscope_node));
    n->scope = v;
    n->sym_id = sym_id;
    n->type_id = type_id;
    n->next = v->list;
    v->list = n;
}

void end_vscope()
{
    current_vscope = current_vscope->parent;
}

static struct vscope_node * find_vnode_rec(struct vscope *c_vscope, int sym_id)
{
    if (!c_vscope) report_error("%s not defined", symname(sym_id));

    for (struct vscope_node *p = c_vscope->list; p; p = p->next)
        if (p->sym_id == sym_id) return p;

    return find_vnode_rec(c_vscope->parent, sym_id);
}

struct vscope_node * find_vnode(int sym_id)
{
    return find_vnode_rec(current_vscope, sym_id);
}

/* type table*/

static int last_type_id = 3;

static struct type_node *type_table = NULL;

struct type_node* find_type_node(int type_id)
{
    for (struct type_node *p = type_table; p; p = p->next)
        if (p->type_id == type_id) return p;
	
    report_error("find_type_node error");
    return NULL;
}
/**/

int parse_int_hex(char const *s)
{
    int n = 0;
    for (int i = 0; i < strlen(s); ++i)
    {
        n *= 16;
        if ('0' <= s[i] && s[i] <= '9')
            n += s[i] - '0';
        else if ('a' <= s[i] && s[i] <= 'z')
            n += s[i] - 'a' + 10;
        else if ('A' <= s[i] && s[i] <= 'Z')
            n += s[i] - 'A' + 10;
    }
    return n;
}

int parse_int_oct(char const *s)
{
    int n = 0;
    for (int i = 0; i < strlen(s); ++i)
    {
        n = n * 8 + s[i] - '0';
    }
    return n;
}

int parse_int(char const *s)
{
    int l = strlen(s);
    if (l != 1)
    {
        if (s[0] == '0')
        {
            if (s[1] == 'x' || s[1] == 'X') return parse_int_hex(s+2);
            else return parse_int_oct(s+1);
        }
    }
    int n = 0;
    for (int i = 0; i < l; ++i)
    {
        n = n * 10 + s[i] - '0';
    }
    return n;
}

float parse_float(char const *s)
{

    int l = strlen(s);
    float n = 0;
	int divisore = 1;
	int signal;
	
	for (int i = 0; i < l; ++i)
    {
		if (signal==1)divisore*=10;
		if(s[i]!='.'){
        n = n * 10 + s[i] - '0';
		
		}else{signal=1;}
		
    }
	n/=divisore;
    return n;
}

int int_type(void)
{
    return 1;
}
int float_type(void)
{
    return 2;
}
int string_type(void)
{
    return 3;
}

int func_type(ast_node *funchead)
{
    struct type_node *n = malloc(sizeof(struct type_node));
    n->type_id = ++last_type_id;
    n->ty = FUNC;
    n->as_func.para_num = 0;
    ast_node *p = funchead->funchead.paras;
    for (; p; p = p->list.tail)
    {
        n->as_func.para_type[n->as_func.para_num++] = p->list.head->para.para_type;
    }
    n->next = type_table;
    type_table = n;
    return n->type_id;
}

static ast_node *newast(int type)
{
    ast_node *node = malloc(sizeof(ast_node));
    node->type = type;
    node->type_id = -1;
    node->fg = 'f';
    return node;
}

ast_list *list_new(int type, ast_node *head, ast_list *tail)
{
    ast_list *l = newast(AST_LIST);
    l->list.type = type;
    l->list.head = head;
    l->list.tail = tail;
    return l;
}

void list_append(ast_list *first, ast_list *second)
{
    while (first && first->list.tail)
    {
        first = first->list.tail;
    }
    if (first)
    {
        first->list.tail = second;
    }
}

ast_node *funcdef_new(int ret_type, ast_node *funchead, ast_stmt *compound_stmt)
{
    ast_node *n = newast(AST_FUNCDEF);
    n->funcdef.ret_type = ret_type;
    n->funcdef.funchead = funchead;
    n->funcdef.compound_stmt = compound_stmt;
    return n;
}

ast_node *funchead_new(int sym_name, ast_list *paras)
{
    ast_node *n = newast(AST_FUNCHEAD);
    n->funchead.sym_name = sym_name;
    n->funchead.paras = paras;
    return n;
}

ast_node *para_new(int para_type, ast_node *var)
{
    ast_node *n = newast(AST_PARA);
    n->para.para_type = para_type;
    n->para.var = var;
    return n;
}

ast_node *var_new(int sym_name,int constant)
{
    ast_node *n = newast(AST_VAR);
    n->var.sym_name = sym_name;
    n->var.constant = constant;

    return n;
}

ast_stmt *compound_stmt_new(ast_list *defs, ast_list *stmts, ast_expr *expr )
{
    ast_stmt *s = newast(AST_COMPOUND_STMT);
    s->compound_stmt.defs = defs;
    s->compound_stmt.stmts = stmts;
	s->compound_stmt.expr = expr;
    return s;
}
 
 ast_stmt *in_stmt_new(int sym_name)
{
    ast_stmt *s = newast(AST_IN_STMT);  
    s->in_stmt.sym_name = sym_name;
    return s;
}

 ast_stmt *out_stmt_new(int sym_name, char* costante)
{
    ast_stmt *s = newast(AST_OUT_STMT);  
    s->out_stmt.sym_name = sym_name;
	s->out_stmt.costante = costante;
    return s;
}


ast_stmt *expr_stmt_new(ast_expr *expr)
{
    ast_stmt *s = newast(AST_EXPR_STMT);
    s->expr_stmt.expr = expr;
    return s;
}

ast_stmt *if_stmt_new(ast_expr *cond, ast_stmt *then, ast_stmt *els)
{
    ast_stmt *s = newast(AST_IF_STMT);
    s->if_stmt.cond = cond;
    s->if_stmt.then = then;
    s->if_stmt.els = els;
    return s;
}

ast_stmt *for_stmt_new(ast_expr *init, ast_expr *cond, ast_expr *incr, ast_stmt *body)
{
    ast_stmt *s = newast(AST_FOR_STMT);
    s->for_stmt.init = init;
    s->for_stmt.cond = cond;
    s->for_stmt.incr = incr;
    s->for_stmt.body = body;
    return s;
}

ast_stmt *do_stmt_new(ast_stmt *stmt,ast_expr *expr)
{
    ast_stmt *s = newast(AST_DO_STMT);
    s->do_stmt.stmt = stmt;
    s->do_stmt.expr = expr;
    return s;
}

ast_stmt *while_stmt_new(ast_expr *expr,ast_stmt *stmt)
{
    ast_stmt *s = newast(AST_WHILE_STMT);
    s->while_stmt.stmt = stmt;
    s->while_stmt.expr = expr;
    return s;
}

ast_stmt *return_stmt_new(ast_expr *retval)
{
    ast_stmt *s = newast(AST_RETURN_STMT);
    s->return_stmt.retval = retval;
    return s;
}

ast_node *def_new(int def_type, ast_list *decs)
{
    ast_node *n = newast(AST_DEF);
    n->def.def_type = def_type;
    n->def.decs = decs;
    return n;
}

ast_node *def_s_new(int def_type, ast_node *str)
{
    ast_node *n = newast(AST_S_DEF);
    n->def_s.def_type = def_type;
    n->def_s.str = str;
    return n;
}

ast_node *def_f_new(int def_type, ast_node *real)
{
    ast_node *n = newast(AST_F_DEF);
    n->def_f.def_type = def_type;
    n->def_f.real = real;
    return n;
}

ast_node *dec_new(ast_node *var, ast_node *init)
{
    ast_node *n = newast(AST_DEC);
    n->dec.var = var;
    n->dec.init = init;
    return n;
}

ast_node *str_new(ast_node *var, char* stringa)
{
    ast_node *n = newast(AST_STR);
    n->str.var = var;
    n->str.stringa = stringa;
    return n;
}

ast_node *real_new(ast_node *var, float real)
{
    ast_node *n = newast(AST_REAL);
    n->real.var = var;
    n->real.real = real;
    return n;
}

ast_expr *binop_new(int op, ast_expr *lhs, ast_expr *rhs)
{
    ast_expr *e = newast(AST_BINOP);
    e->binop.op = op;
    e->binop.lhs = lhs;
    e->binop.rhs = rhs;
    return e;
}

ast_expr *prefix_new(int op, ast_expr *unary)
{
    ast_expr *e = newast(AST_PREFIX);
    e->prefix.op = op;
    e->prefix.unary = unary;
    return e;
}

ast_expr *postfix_new(int op, ast_expr *unary)
{
    ast_expr *e = newast(AST_POSTFIX);
    e->postfix.op = op;
    e->postfix.unary = unary;
    return e;
}

ast_expr *func_call_new(ast_expr *postfix, ast_list *args)
{
    ast_expr *e = newast(AST_FUNC_CALL);
    e->func_call.postfix = postfix;
    e->func_call.args = args;
    return e;
}

ast_expr *id_new(int sym_name)
{
    ast_expr *e = newast(AST_ID);
    e->id.sym_name = sym_name;
    return e;
}

ast_expr *const_new(int number)
{
    ast_expr *e = newast(AST_CONST);
    e->constant.number = number;
    return e;
}

