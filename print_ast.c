/****************************************************************************

 print_ast.c:
 Implements functions required for printing the AST in HTML format.
 For the sake of printing the parse tree in a hierarchical style, list representation
 in HTML with tags < ul > and < li > is leveraged.

*****************************************************************************/


#include <stdio.h>
#include "c++2python.h"


typedef void (*ast_printer)(ast_node *n);

static ast_printer g_ast_printers[AST_TYPE_LIMIT];

static void print_list(ast_node *n)
{
    printf("<ul>\n");
    for (; n; n = n->list.tail)
    {
        printf("<li>\n");
        print_ast(n->list.head);
        printf("</li>\n");
    }
    printf("</ul>\n");
}

static void print_funcdef(ast_node *n)
{
    printf("<ul>\n");
    printf("<li>funcdef</li>\n");
    printf("<li>ret_type: %d</li>\n", n->funcdef.ret_type);
    printf("<li>funchead:\n");
    print_ast(n->funcdef.funchead);
    printf("</li>\n");
    printf("<li>funcbody:\n");
    print_ast(n->funcdef.compound_stmt);
    printf("</li>\n");
    printf("</ul>\n");
}

static void print_funchead(ast_node *n)
{
    printf("<ul>\n");
    printf("<li>funchead</li>\n");
    printf("<li>sym_name: %d</li>\n", n->funchead.sym_name);
    printf("<li>paras:\n");
    print_ast(n->funchead.paras);
    printf("</li>\n");
    printf("</ul>\n");
}

static void print_para(ast_node *n)
{
    printf("<ul>\n");
    printf("<li>para</li>\n");
    printf("<li>para_type: %d</li>\n", n->para.para_type);
    printf("<li>var:\n");
    print_ast(n->para.var);
    printf("</li>\n");
    printf("</ul>\n");
}

static void print_var(ast_node *n)
{
    printf("<ul>\n");
    printf("<li>var</li>\n");
    printf("<li>sym_name: %d</li>\n", n->var.sym_name);
    printf("</ul>\n");
}

static void print_compound_stmt(ast_node *n)
{
    printf("<ul>\n");
    printf("<li>compound_stmt</li>\n");
    printf("<li>defs:\n");
    print_ast(n->compound_stmt.defs);
    printf("</li>\n");
    printf("<li>stmts:\n");
    print_ast(n->compound_stmt.stmts);
    printf("</li>\n");
	printf("<li>expr_stmt</li>\n");
    printf("<li>expr:\n");
    print_ast(n->compound_stmt.expr);
    printf("</li>\n");
    printf("</ul>\n");
}

static void print_in_stmt(ast_node *n)
{
    printf("<ul>\n");
    printf("<li>in_stmt</li>\n");
    printf("<li>variabile:\n");
    printf("<li>sym_name: %d</li>\n", n->in_stmt.sym_name);
    printf("</li>\n");
    printf("</ul>\n");
}

static void print_out_stmt(ast_node *n)
{
    printf("<ul>\n");
    printf("<li>out_stmt</li>\n");
    printf("<li>variabile:\n");
    printf("<li>sym_name: %d</li>\n", n->out_stmt.sym_name);
	printf("<li>str:\n");
    printf("<li>%s</li>\n", n->out_stmt.costante);
    printf("</li>\n");
    printf("</li>\n");
    printf("</ul>\n");
}

static void print_expr_stmt(ast_node *n)
{
    printf("<ul>\n");
    printf("<li>expr_stmt</li>\n");
    printf("<li>expr:\n");
    print_ast(n->expr_stmt.expr);
    printf("</li>\n");
    printf("</ul>\n");
}

static void print_if_stmt(ast_node *n)
{
    printf("<ul>\n");
    printf("<li>if_stmt</li>\n");
    printf("<li>cond:\n");
    print_ast(n->if_stmt.cond);
    printf("</li>\n");
    printf("<li>then:\n");
    print_ast(n->if_stmt.then);
    printf("</li>\n");
    printf("<li>els:\n");
    print_ast(n->if_stmt.els);
    printf("</li>\n");
    printf("</ul>\n");
}

static void print_for_stmt(ast_node *n)
{
    printf("<ul>\n");
    printf("<li>for_stmt</li>\n");
    printf("<li>init:\n");
    print_ast(n->for_stmt.init);
    printf("</li>\n");
    printf("<li>cond:\n");
    print_ast(n->for_stmt.cond);
    printf("</li>\n");
    printf("<li>incr:\n");
    print_ast(n->for_stmt.incr);
    printf("</li>\n");
    printf("<li>body:\n");
    print_ast(n->for_stmt.body);
    printf("</li>\n");
    printf("</ul>\n");
}

static void print_do_stmt(ast_node *n)
{
	printf("<ul>\n");
    printf("<li>do_stmt</li>\n");
    printf("<li>state:\n");
    print_ast(n->do_stmt.stmt);
    printf("</li>\n");
    printf("<li>condizione:\n");
    print_ast(n->do_stmt.expr);
    printf("</li>\n");
    printf("</ul>\n");

   
}

static void print_while_stmt(ast_node *n)
{
    printf("<ul>\n");
	printf("<li>while_stmt</li>\n");
    printf("<li>condizione:\n");
    print_ast(n->while_stmt.expr);
    printf("<li>state:\n");
    print_ast(n->while_stmt.stmt);
    printf("</li>\n");
    printf("</ul>\n");

}

static void print_return_stmt(ast_node *n)
{
    printf("<ul>\n");
    printf("<li>return_stmt</li>\n");
    printf("<li>retval:\n");
    print_ast(n->return_stmt.retval);
    printf("</li>\n");
    printf("</ul>\n");
}


static void print_def(ast_node *n)
{
    printf("<ul>\n");
    printf("<li>def int</li>\n");
    printf("<li>def_type: %d</li>\n", n->def.def_type);
    printf("<li>dec:\n");
    print_ast(n->def.decs);
    printf("</li>\n");
    printf("</ul>\n");
}

static void print_def_s(ast_node *n)
{
    printf("<ul>\n");
    printf("<li>def stringa</li>\n");
    printf("<li>def_type: %d</li>\n", n->def_s.def_type);
    printf("<li>str:\n");
    print_ast(n->def_s.str);
    printf("</li>\n");
    printf("</ul>\n");
}

static void print_def_f(ast_node *n)
{
    printf("<ul>\n");
    printf("<li>def float</li>\n");
    printf("<li>def_type: %d</li>\n", n->def_f.def_type);
    printf("<li>real:\n");
    print_ast(n->def_f.real);
    printf("</li>\n");
    printf("</ul>\n");
}

static void print_dec(ast_node *n)
{
    printf("<ul>\n");
    printf("<li>dec</li>\n");
    printf("<li>var:\n");
    print_ast(n->dec.var);
    printf("</li>\n");
    printf("<li>init:\n");
    print_ast(n->dec.init);
    printf("</li>\n");
    printf("</ul>\n");
}

static void print_str(ast_node *n)
{
    printf("<ul>\n");
    printf("<li>var:\n");
    print_ast(n->str.var);
    printf("</li>\n");
    printf("<li>char:\n");
    printf("<li>%s</li>\n", n->str.stringa);
    printf("</li>\n");
    printf("</ul>\n");
}

static void print_real(ast_node *n)
{
    printf("<ul>\n");
    printf("<li>var:\n");
    print_ast(n->real.var);
    printf("</li>\n");
    printf("<li>real:\n");
    printf("<li>%f</li>\n", n->real.real);
    printf("</li>\n");
    printf("</ul>\n");
}



static void print_binop(ast_node *n)
{
    printf("<ul>\n");
    printf("<li>binop</li>\n");
    printf("<li>op: %d</li>\n", n->binop.op);
    printf("<li>lhs:\n");
    print_ast(n->binop.lhs);
    printf("</li>\n");
    printf("<li>rhs:\n");
    print_ast(n->binop.rhs);
    printf("</li>\n");
    printf("</ul>\n");
}

static void print_prefix(ast_node *n)
{
    printf("<ul>\n");
    printf("<li>prefix</li>\n");
    printf("<li>op: %d</li>\n", n->prefix.op);
    printf("<li>unary:\n");
    print_ast(n->prefix.unary);
    printf("</li>\n");
    printf("</ul>\n");
}

static void print_postfix(ast_node *n)
{
    printf("<ul>\n");
    printf("<li>postfix</li>\n");
    printf("<li>op: %d</li>\n", n->postfix.op);
    printf("<li>unary:\n");
    print_ast(n->postfix.unary);
    printf("</li>\n");
    printf("</ul>\n");
}

static void print_func_call(ast_node *n)
{
    printf("<ul>\n");
    printf("<li>func_call</li>\n");
    printf("<li>postfix:\n");
    print_ast(n->func_call.postfix);
    printf("</li>\n");
    printf("<li>args:\n");
    print_ast(n->func_call.args);
    printf("</li>\n");
    printf("</ul>\n");
}

static void print_id(ast_node *n)
{
    printf("<ul>\n");
    printf("<li>id</li>\n");
    printf("<li>sym_name: %d</li>\n", n->id.sym_name);
    printf("</ul>\n");
}

static void print_const(ast_node *n)
{
    printf("<ul>\n");
    printf("<li>const</li>\n");
    printf("<li>number: %d</li>\n", n->constant.number);
    printf("</ul>\n");
}

static void init_ast_printers()
{
    if (g_ast_printers[0]) return;
    g_ast_printers[AST_LIST] = print_list;
    g_ast_printers[AST_FUNCDEF] = print_funcdef;
    g_ast_printers[AST_FUNCHEAD] = print_funchead;
    g_ast_printers[AST_PARA] = print_para;
    g_ast_printers[AST_VAR] = print_var;
    g_ast_printers[AST_COMPOUND_STMT] = print_compound_stmt;
	g_ast_printers[AST_IN_STMT] = print_in_stmt;
	g_ast_printers[AST_OUT_STMT] = print_out_stmt;
    g_ast_printers[AST_EXPR_STMT] = print_expr_stmt;
    g_ast_printers[AST_IF_STMT] = print_if_stmt;
    g_ast_printers[AST_FOR_STMT] = print_for_stmt;
	g_ast_printers[AST_DO_STMT] = print_do_stmt;
	g_ast_printers[AST_WHILE_STMT] = print_while_stmt;
    g_ast_printers[AST_RETURN_STMT] = print_return_stmt;
    g_ast_printers[AST_DEF] = print_def;
    g_ast_printers[AST_DEF] = print_def;
    g_ast_printers[AST_S_DEF] = print_def_s;
    g_ast_printers[AST_F_DEF] = print_def_f;
    g_ast_printers[AST_DEC] = print_dec;
    g_ast_printers[AST_STR] = print_str;
    g_ast_printers[AST_REAL] = print_real;
    g_ast_printers[AST_BINOP] = print_binop;
    g_ast_printers[AST_PREFIX] = print_prefix;
    g_ast_printers[AST_POSTFIX] = print_postfix;
    g_ast_printers[AST_FUNC_CALL] = print_func_call;
    g_ast_printers[AST_ID] = print_id;
    g_ast_printers[AST_CONST] = print_const;
}

void print_ast(ast_node *n)
{
    init_ast_printers();
    if (n)
    {
        g_ast_printers[n->type](n);
    }
    else
    {
        printf("NULL");
    }
}
