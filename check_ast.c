/****************************************************************************

 check_ast.c:
 Implements functions required for checking the AST types according to scopes.


*****************************************************************************/

#include "c++2python.h"
#include <ctype.h>

typedef void (*ast_checker)(ast_node *n);

static ast_checker g_ast_checkers[AST_TYPE_LIMIT];
static const char* g_ast_names[AST_TYPE_LIMIT];

/* report error */

void report_error(const char *fmt, ...)
{
	
    va_list args;
    char buffer[1024];

    va_start(args, fmt);
    vsnprintf(buffer, sizeof buffer, fmt, args);
    va_end(args);

    fprintf(stdout, "Error.\n");
    fprintf(stderr, "Error: %s\n", buffer);
    exit(1);
}

static int trace_type(int type_id)
{
    if (type_id == 1) return 1;
	if (type_id == 2) return 2;
	if (type_id == 3) return 3;
    struct type_node *t = find_type_node(type_id);
    if (t->ty == FUNC) return t->as_func.ret_type;
    return type_id;
}

static int is_type_of_int(int type_id)
{	
    return trace_type(type_id) == 1;
}

static int is_type_of_float(int type_id)
{
	return trace_type(type_id) == 2;
}

static int is_type_of_string(int type_id)
{	
    return trace_type(type_id) == 3;
}


/* check in current scope if the sym_id exists */

static struct vscope_node* check_vscope(struct vscope *v, int sym_id)
{
    struct vscope_node *n = v->list;
    for (; n; n = n->next)
    {
        if (n->sym_id == sym_id) return n;
    }
    return NULL;
}

/* check in all scope if the sym_id exists */
static struct vscope_node* check_vscope_all(struct vscope *v, int sym_id)
{
    struct vscope *s = v;
    struct vscope_node *n = s->list;
    for (; s; s = s->parent)
    {
        for (n = s->list; n; n = n->next)
        {
            if (n->sym_id == sym_id) return n;
        }
    }
    return NULL;
}

static void check_list(ast_node *n)
{
    ast_node *p = n;
    for (; p; p = p->list.tail)
    {
        check_ast(p->list.head);
        p->fg = p->list.head->fg;
    }
}

/* Reserved words can not be used as identifiers. Reserved words can be found in TOKENs */

/* record the def_type */
static int def_type;

static void check_def(ast_node *n)
{
    def_type = n->def.def_type;
    n->type_id = def_type;
    if(n->def.decs)check_ast(n->def.decs);
    n->fg = n->def.decs->fg;
}

static void check_def_s(ast_node *n)
{
    def_type = n->def_s.def_type;
    n->type_id = def_type;
    check_ast(n->def_s.str);
    n->fg = n->def_s.str->fg;
}

static void check_def_f(ast_node *n)
{
    def_type = n->def_f.def_type;
    n->type_id = def_type;
    check_ast(n->def_f.real);
    n->fg = n->def_f.real->fg;
}

static void check_dec(ast_node *n)
{
    check_ast(n->dec.var);
    n->type_id = def_type;
    if (n->dec.init)
    {
        check_ast(n->dec.init);
        ast_node *p = n->dec.init;
    }
    n->fg = n->dec.var->fg;
}

static void check_str(ast_node *n)
{
    check_ast(n->str.var);
    n->type_id = def_type;
    n->fg = n->str.var->fg;
}

static void check_real(ast_node *n)
{
    check_ast(n->real.var);
    n->type_id = def_type;
    n->fg = n->real.var->fg;
}


static void check_var(ast_node *n)
{
    /* check variables should not be re-declared */
    if (check_vscope(current_vscope, n->var.sym_name))
        report_error("%s has already been declared", symname(n->var.sym_name));
	n->type_id = def_type;
    vscope_addnode(current_vscope, n->var.sym_name, def_type);
    if (current_vscope->parent == NULL) n->fg = 'g'; /* global use $gp */	
}

static int length_of(ast_node *n)
{
    if (n && n->type == AST_LIST)
    {
        return 1 + length_of(n->list.tail);
    }
    return 0;
}

static void check_funcdef(ast_node *n)
{
    check_ast(n->funcdef.funchead);
    check_ast(n->funcdef.compound_stmt);
    int main_sym = sym("main");
	int m= n->funcdef.funchead->funchead.sym_name;
	if (m==main_sym){if ((n->funcdef.ret_type)!=1) report_error("main function must be int");}
    end_vscope();
}

static void check_funchead(ast_node *n)
{
    /* check function name should not be re-declared */
    if (check_vscope(current_vscope, n->funchead.sym_name))
        report_error("%s has already been declared", symname(n->funchead.sym_name));

    n->type_id = func_type(n);
    vscope_addnode(current_vscope, n->funchead.sym_name, n->type_id);
    begin_vscope();
    check_ast(n->funchead.paras);
}

/* check the parameters declared in a function */
static void check_para(ast_node *n)
{
    /* check parametes should not have the same name */
    if (check_vscope(current_vscope, n->para.var->var.sym_name))
        report_error("%s has been declared twice", symname(n->para.var->var.sym_name));
    n->type_id = n->para.para_type;
    def_type = n->type_id;
    check_ast(n->para.var);
}

static void check_compound_stmt(ast_node *n)
{
    check_ast(n->compound_stmt.defs);
    check_ast(n->compound_stmt.stmts);
	check_ast(n->compound_stmt.expr);
}

static void check_in_stmt(ast_node *n)
{
	if (check_vscope(current_vscope, n->in_stmt.sym_name)){
	}else report_error("Not declared input variable");
}

static void check_out_stmt(ast_node *n)
{
		if(n->out_stmt.sym_name!=0){
	if (check_vscope(current_vscope, n->out_stmt.sym_name)){
	}else report_error("Not declared output variable");
		}
}

static void check_expr_stmt(ast_node *n)
{
    check_ast(n->expr_stmt.expr);
    n->type_id = n->expr_stmt.expr->type_id;
}

static void check_if_stmt(ast_node *n)
{
    check_ast(n->if_stmt.cond);
    check_ast(n->if_stmt.then);
    check_ast(n->if_stmt.els);
}


/* check wheather break and continue are in for loop */

static void check_for_stmt(ast_node *n)
{
    check_ast(n->for_stmt.init);
    if (n->for_stmt.cond)
    {
        check_ast(n->for_stmt.cond);
    }
    check_ast(n->for_stmt.incr);
    check_ast(n->for_stmt.body);
	
	
}

static void check_do_stmt(ast_node *n)
{
    check_ast(n->do_stmt.stmt);
    if (n->do_stmt.expr)
    {
        check_ast(n->do_stmt.expr);
        
    }
    
}

static void check_while_stmt(ast_node *n)
{
    check_ast(n->while_stmt.stmt);
    if (n->while_stmt.expr)
    {
        check_ast(n->while_stmt.expr);
        
    }
    
}

static void check_return_stmt(ast_node *n)
{
    check_ast(n->return_stmt.retval);
    n->type_id = n->return_stmt.retval->type_id;
}

static const char * binop_instr(int op)
{
    switch (op)
    {
    case ADD_ASSIGN:
        return "+=";
    case GE_OP:
        return ">=";
    case LE_OP:
        return "<=";
    case EQ_OP:
        return "==";
    case NE_OP:
        return "!=";
    case SHL_OP:
        return "<<";
    case SHR_OP:
        return ">>";
    case AND_OP:
		return "&";
	case OR_OP:
		return "|";
	case '+':
        return "+";
    case '-':
        return "-";
    case '*':
        return "*";
    case '/':
        return "/";
    case '>':
        return ">";
    case '<':
        return "<";
	case '=':
		return "=";
    }
    return "Error??";
}
static void check_binop(ast_node *n)
{
	check_ast(n->binop.lhs);    check_ast(n->binop.rhs);

	const char *op = binop_instr(n->binop.op);
	if(op=="="){
		if(is_type_of_int(n->binop.lhs->type_id)){
			if (is_type_of_string(n->binop.rhs->type_id))
			report_error("It's impossible to assign a string value to an integer variable");
		}	
		if(is_type_of_float(n->binop.lhs->type_id)){
			check_ast(n->binop.rhs);
			if (is_type_of_string(n->binop.rhs->type_id))
			report_error("It's impossible to assign a string value to a real variable");
		}
	}else{
		if(op!="+="){
	if ((is_type_of_int(n->binop.rhs->type_id))&&(is_type_of_string(n->binop.lhs->type_id))){ report_error("Bad Expression statement; string type variable compared with an integer type variable");}
	if ((is_type_of_string(n->binop.rhs->type_id))&&(is_type_of_int(n->binop.lhs->type_id))){ report_error("Bad Expression statement; string type variable compared with an integer type variable");}
	if ((is_type_of_float(n->binop.rhs->type_id))&&(is_type_of_string(n->binop.lhs->type_id))){ report_error("Bad Expression statement; string type variable compared with a real type variable");}
	if ((is_type_of_string(n->binop.rhs->type_id))&&(is_type_of_float(n->binop.lhs->type_id))){ report_error("Bad Expression statement; string type variable compared with a real type variable");}
		}else if(is_type_of_string(n->binop.rhs->type_id)) report_error("Bad expression statement; the selected operation is not operable to string type variable");
	}	
	//
    n->type_id = 1;
	
}

static void check_prefix(ast_node *n)
{
    check_ast(n->prefix.unary);
    n->type_id = n->prefix.unary->type_id;
}

static void check_postfix(ast_node *n)
{
    check_ast(n->postfix.unary);
    n->type_id = n->postfix.unary->type_id;
    n->fg = n->postfix.unary->fg;
}
/* The number and type of variable(s) passed should match the definition of the function */

static void check_func_call(ast_node *n)
{
    if (!check_vscope_all(current_vscope, n->func_call.postfix->id.sym_name))
    {
        report_error("function %s not declared", symname(n->func_call.postfix->id.sym_name));
    }

    check_ast(n->func_call.postfix);
    n->type_id = n->func_call.postfix->type_id;
    struct type_node *t = find_type_node(n->type_id);

    /* check the identifier of a function call is of type function */
    if (t->ty != FUNC)
    {
        report_error("the identifier %s is not of type FUNC", symname(n->func_call.postfix->id.sym_name));
    }

    /* check the argument number and type */
    ast_node *p = n->func_call.args;
    for (int i = 0; i < t->as_func.para_num; ++i)
    {
        if (!p)
        {
            report_error("insufficient arguments in function %s", symname(n->func_call.postfix->id.sym_name));
        }
        check_ast(p->list.head);
        int given = trace_type(p->list.head->type_id);
        int expected = t->as_func.para_type[i];
        p = p->list.tail;
    }
    if (p)
    {
        report_error("too many arguments in function %s", symname(n->func_call.postfix->id.sym_name));
    }
    n->fg = n->func_call.postfix->fg;
}



static void check_id(ast_node *n)
{
    /* check variables have been declared before usage */

    if (!check_vscope_all(current_vscope, n->id.sym_name))
    {
        report_error("%s is not declared", symname(n->id.sym_name));
    }

    struct vscope_node *vnode = find_vnode(n->id.sym_name);
    n->type_id = vnode->type_id;

    if (vnode->scope->parent == NULL) n->fg = 'g'; /* global use $gp */
}

static void check_const(ast_node *n)
{
    n->type_id = 1;
}

static void init_ast_checkers()
{
    if (g_ast_checkers[0]) return;
    g_ast_checkers[AST_LIST] = check_list;
    g_ast_checkers[AST_FUNCDEF] = check_funcdef;
    g_ast_checkers[AST_FUNCHEAD] = check_funchead;
    g_ast_checkers[AST_PARA] = check_para;
    g_ast_checkers[AST_VAR] = check_var;
    g_ast_checkers[AST_COMPOUND_STMT] = check_compound_stmt;
    g_ast_checkers[AST_IN_STMT] = check_in_stmt;
    g_ast_checkers[AST_OUT_STMT] = check_out_stmt;
    g_ast_checkers[AST_EXPR_STMT] = check_expr_stmt;
    g_ast_checkers[AST_IF_STMT] = check_if_stmt;
    g_ast_checkers[AST_FOR_STMT] = check_for_stmt;
	g_ast_checkers[AST_DO_STMT] = check_do_stmt;
	g_ast_checkers[AST_WHILE_STMT] = check_while_stmt;
    g_ast_checkers[AST_RETURN_STMT] = check_return_stmt;
    g_ast_checkers[AST_DEF] = check_def;
    g_ast_checkers[AST_S_DEF] = check_def_s;
    g_ast_checkers[AST_F_DEF] = check_def_f;
    g_ast_checkers[AST_DEC] = check_dec;
	g_ast_checkers[AST_STR] = check_str;
	g_ast_checkers[AST_REAL] = check_real;
    g_ast_checkers[AST_BINOP] = check_binop;
    g_ast_checkers[AST_PREFIX] = check_prefix;
    g_ast_checkers[AST_POSTFIX] = check_postfix;
    g_ast_checkers[AST_FUNC_CALL] = check_func_call;
    g_ast_checkers[AST_ID] = check_id;
    g_ast_checkers[AST_CONST] = check_const;
	
    g_ast_names[AST_LIST] = "check_list";
    g_ast_names[AST_FUNCDEF] = "check_funcdef";
    g_ast_names[AST_FUNCHEAD] = "check_funchead";
    g_ast_names[AST_PARA] = "check_para";
    g_ast_names[AST_VAR] = "check_var";
    g_ast_names[AST_COMPOUND_STMT] = "check_compound_stmt";
    g_ast_names[AST_IN_STMT] = "check_in_stmt";
    g_ast_names[AST_OUT_STMT] = "check_out_stmt";
    g_ast_names[AST_EXPR_STMT] = "check_expr_stmt";
    g_ast_names[AST_IF_STMT] = "check_if_stmt";
    g_ast_names[AST_FOR_STMT] = "check_for_stmt";
	g_ast_names[AST_DO_STMT] = "check_do_stmt";
	g_ast_names[AST_WHILE_STMT] = "check_while_stmt";
    g_ast_names[AST_RETURN_STMT] = "check_return_stmt";
    g_ast_names[AST_DEF] = "check_def";
    g_ast_names[AST_S_DEF] = "check_def_s";
    g_ast_names[AST_F_DEF] = "check_def_f";
    g_ast_names[AST_DEC] = "check_dec";
    g_ast_names[AST_STR] = "check_str";
    g_ast_names[AST_REAL] = "check_real";
    g_ast_names[AST_BINOP] = "check_binop";
    g_ast_names[AST_PREFIX] = "check_prefix";
    g_ast_names[AST_POSTFIX] = "check_postfix";
    g_ast_names[AST_FUNC_CALL] = "check_func_call";
    g_ast_names[AST_ID] = "check_id";
    g_ast_names[AST_CONST] = "check_const";
}

void check_ast(ast_node *n)
{
    init_ast_checkers();
    if (n)
    {
        #ifdef DEBUG
            fprintf(stderr, "[DEBUG] check_ast n->type=%s\n", g_ast_names[n->type]);
        #endif

        g_ast_checkers[n->type](n);
    }
}

extern int main_sym;

void check_semantics(ast_node *ast)
{
    begin_vscope();
    check_ast(ast);

    /* check program must contain a function int main() to be the entrance */
    if (!check_vscope(current_vscope, sym("main")))
        report_error("the program doesn't contain int main() function as entrance");

    main_sym = sym("main");
    end_vscope();
}

