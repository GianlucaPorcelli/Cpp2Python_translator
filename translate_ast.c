#include "c++2python.h"
#include <string.h>

typedef void (*ast_translator)(ast_node *n);

static ast_translator g_ast_translators[AST_TYPE_LIMIT];
static const char* g_ast_names[AST_TYPE_LIMIT];


void emit(const char *fmt, ...)
{
    va_list args;
    char buffer[1024], format[1024];

    va_start(args, fmt);
    vsnprintf(buffer, sizeof buffer, fmt, args);
    va_end(args);

    sprintf(format, "%s", buffer);

    fprintf(stdout, "%s", format);
}

char *split = "";
int tabn = 0;
void emit_tab() {
	for (int i = 0; i < tabn; ++i) {
		emit("\t");
	}
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

static void trans_list(ast_node *n)
{
    for (; n; n = n->list.tail)
    {	
        trans_ast(n->list.head);
        if (n->list.tail) {emit("%s ", split);}
    } 
}

static void trans_funcdef(ast_node *n)
{
	emit("\ndef ");
    trans_ast(n->funcdef.funchead);
    emit(":");
	split = "";
	++tabn;
    trans_ast(n->funcdef.compound_stmt);
	ast_node *p= n->funcdef.compound_stmt;
	if (!p->compound_stmt.expr) emit("\n#Lost return statement or it is in a {}");
	if( p->compound_stmt.expr){
	ast_node *x= p->compound_stmt.expr;
	if((x->type_id)!=(n->funcdef.ret_type)){emit("\n#Return type is not correct");}
	}
    --tabn;
}

static void trans_funchead(ast_node *n)
{	
	char *s = symname(n->funchead.sym_name);
	if (!strcmp(s, "main")) {
		emit("main()");
		return;
	}
    emit("%s(", s);
    split = ", ";
    trans_ast(n->funchead.paras);
	split = "";
    emit(")");
}

static void trans_para(ast_node *n)
{
	char *s = "";
    emit("%s ", s);
    trans_ast(n->para.var);
}

static void trans_def(ast_node *n)
{	
	char *s = "";
	trans_ast(n->def.decs);	
}


static void trans_def_s(ast_node *n)
{	
	char *s = "";	
	trans_ast(n->def_s.str);
	
}

static void trans_def_f(ast_node *n)
{	
	char *s = "";	
	trans_ast(n->def_f.real);
	
}

static void trans_dec(ast_node *n)
{    
	emit("\n");
	emit_tab(); 
	if (n->dec.init){
	if(n->dec.var->var.constant!=0) report_error("Impossible array assignement");
    trans_ast(n->dec.var);
    emit(" = ");
    ast_node *p = n->dec.init;
        if (p->type == AST_LIST)
        {
        emit("{");
        trans_ast(n->dec.init);
        emit("}");
        }
        else
        {
        trans_ast(n->dec.init);
        }

					}else	{  
							if(n->dec.var->var.constant == 0){trans_ast(n->dec.var); emit(" = 0");
							}
							else{
								char *s = symname(n->dec.var->var.sym_name);
								emit("%s = [0",s);
								for(int i=0;i<n->dec.var->var.constant-1;i++){
								emit(",0");/*default array initialization*/}
								emit("]");
								}
								
					}
}

static void trans_str(ast_node *n)
{    
	emit("\n");
	emit_tab(); 
	trans_ast(n->str.var);
	if(n->str.stringa)
	emit(" = %s",n->str.stringa);
    else emit(" = \"null\"");
}

static void trans_real(ast_node *n)
{    
	emit("\n");
	emit_tab(); 
	trans_ast(n->real.var);
	emit(" = %f",n->real.real);
}

static void trans_var(ast_node *n)
{
	if(n->var.constant==0){
   emit("%s", symname(n->var.sym_name));
	}
}

static void trans_compound_stmt(ast_node *n)
{	
	split = "";
	trans_ast(n->compound_stmt.defs);
    trans_ast(n->compound_stmt.stmts);
	if (n->compound_stmt.expr){
		emit("\n");emit_tab(); emit("return "); trans_ast(n->compound_stmt.expr);//emit(";");
	}	
}

static void trans_in_stmt(ast_node *n)
{
	emit("\n");
    emit_tab();
	emit("%s = input (\"inserisci la variabile %s: \")", symname(n->in_stmt.sym_name),symname(n->in_stmt.sym_name));

}

static void trans_out_stmt(ast_node *n)
{
	if(n->out_stmt.sym_name!=0){
			emit("\n");
			emit_tab();
			emit("print(%s)", symname(n->out_stmt.sym_name));
		}else
		if((n->out_stmt.costante)&&(strcmp(n->out_stmt.costante,"\"\\n\""))){
			emit("\n");
			emit_tab();
			emit("print(%s)",n->out_stmt.costante);	
		}
}

static void trans_expr_stmt(ast_node *n)
{	
	emit("\n");
	emit_tab();
    trans_ast(n->expr_stmt.expr);    
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
		return "and";
	case OR_OP:
		return "or";
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

static int check_bool(int op) {
	switch (op)
	{
	case GE_OP:
        return 1;
    case LE_OP:
        return 1;  
	case '>':
        return 1;
    case '<':
        return 1;
    case EQ_OP:
        return 1;
    case NE_OP:
        return 1;
	case AND_OP:
		return 1;
	case OR_OP:
		return 1;
	}
	return 0;
}

int check_bool_lr_bool(int op) {
	switch (op)
	{
	case AND_OP:
		return 1;
	case OR_OP:
		return 1;
	}
	return 0;
}


static void trans_bool(ast_node *n, int mustbool) {
	if (!mustbool) {
		trans_ast(n);
		return;
	}
	if (n->type == AST_PREFIX) {
		if (n->prefix.op == '!') {
			emit("(");
			trans_bool(n->prefix.unary, 0);
			emit(") == 0");
			return;
		}
	}
	if (n->type == AST_CONST) {
		emit("%d != 0", n->constant.number);
	}	
	if (n->type == AST_ID) {
		char *s = symname(n->id.sym_name);
		emit("%s != 0", s);
	}
	if (n->type == AST_FUNC_CALL) {
		emit("(");	
		trans_ast(n->func_call.postfix);
		emit("(");
		if (n->func_call.args) {
			split = ", ";
			trans_ast(n->func_call.args);
			split = "";
		}
		emit(")) != 0");
	}
	if (n->type == AST_POSTFIX) {
		emit("(");
	    trans_ast(n->postfix.unary);
		emit(") != 0");	
	}
	if (n->type == AST_BINOP) {
		int tobebool = check_bool_lr_bool(n->binop.op);
		int alreadybool = check_bool(n->binop.op);
		if (!alreadybool) emit("(");
		trans_bool(n->binop.lhs, tobebool);
		emit(" %s ", binop_instr(n->binop.op));
		trans_bool(n->binop.rhs, tobebool);
		if (!alreadybool) emit(") != 0");
	}
}

static void trans_if_stmt(ast_node *n)
{
	emit("\n");
	emit_tab();
	emit("if (");
    trans_bool(n->if_stmt.cond, 1);
    emit("):");
    ++tabn;
    trans_ast(n->if_stmt.then);
    --tabn;
    if (n->if_stmt.els) {
    	
    	emit("\n");
		emit_tab();
		emit("else:");
    	++tabn;
    	trans_ast(n->if_stmt.els);
    	--tabn;
    }
}

static void trans_for_stmt(ast_node *n)
{
	if(n->for_stmt.cond){
	emit("\n");
	emit_tab();
    if ((n->for_stmt.init->type == AST_BINOP)&&(n->for_stmt.init->binop.rhs->type==AST_CONST)&&(n->for_stmt.init->binop.rhs->constant.number==0)){
	//cond	
			const char *op = binop_instr(n->for_stmt.cond->binop.op);
			const char *op2 = binop_instr(n->for_stmt.incr->binop.op);
		
	
	if ((n->for_stmt.incr->type == AST_BINOP)&&(op2=="+=")&&(n->for_stmt.incr->binop.lhs->type==AST_ID)&&(n->for_stmt.incr->binop.rhs->type==AST_CONST)){
		int numero=n->for_stmt.incr->binop.rhs->constant.number;	
	
	if ((numero==1)&&(n->for_stmt.cond->type == AST_BINOP)&&(op=="<")&&(op2=="+=")&&(n->for_stmt.init->binop.lhs->type==AST_ID)&&(n->for_stmt.cond->binop.lhs->type==AST_ID)&&(n->for_stmt.cond->binop.rhs->type==AST_ID)){

		char *s1 = symname(n->for_stmt.init->binop.lhs->id.sym_name);
		char *s2 = symname(n->for_stmt.cond->binop.lhs->id.sym_name);
		char *s3 = symname(n->for_stmt.cond->binop.rhs->id.sym_name);
		char *s4 = symname(n->for_stmt.incr->binop.lhs->id.sym_name);
		if(((s1==s2)&&(s1==s4)))
		{
		const char *op =binop_instr(n->for_stmt.cond->binop.op);

		
		int tobebool = check_bool_lr_bool(n->binop.op);
		emit("for ");
		trans_bool(n->for_stmt.cond->binop.lhs, tobebool);
		emit(" in range (");
		trans_bool(n->for_stmt.init->binop.rhs, tobebool);
		emit(",");
		trans_bool(n->for_stmt.cond->binop.rhs, tobebool);
		emit("):");
		++tabn;
		trans_ast(n->for_stmt.body);
		--tabn;		
		}else{emit("\n#The cycle variable must be present both in condition and increment statement\n");};

	}else {		emit("\n#3)Implemented form: \n#for(x=0;x<variable;x+=1)\n#x and variable must be previously declared\n");};
	
	}else {		emit("\n#2)Implemented form: \n#for(x=0;x<variable;x+=1)\n#x and variable must be previously declared\n");};
		
	}else {		emit("\n#1)Implemented form: \n#for(x=0;x<variable;x+=1)\n#x and variable must be previously declared\n");};
	
	}else{emit_tab();emit("for (;;)\n#WARNING: for statement create an infinite loop.\n");}
	if(!n->for_stmt.init)emit("#You have to define a previous initial value of loop variable. You may have an infinite loop\n");
	if(!n->for_stmt.incr)emit("#You have to define an increment of a of loop variable in the for statement. You may have an infinite loop\n");

}

static void trans_do_stmt(ast_node *n)
{
	emit("\n");
	emit_tab();
	const char *op = binop_instr(n->do_stmt.expr->binop.op);
	if((n->do_stmt.expr->type == AST_BINOP)&&(op=="=")){
		emit("#Not translatable do loop");
		
	}else{
	emit("while True:");
	tabn++;
	trans_ast(n->do_stmt.stmt);
	emit("\n");
	emit_tab();
	emit("if((");
	trans_bool(n->do_stmt.expr, 1);
	emit(") == 0):\n");
	tabn++;
	emit_tab();
	emit("break");
	tabn--;
	
	tabn--;
	}
}

static void trans_while_stmt(ast_node *n)
{
	emit("\n");
	emit_tab();
	const char *op = binop_instr(n->while_stmt.expr->binop.op);
	if((n->while_stmt.expr->type == AST_BINOP)&&(op=="=")){
		emit("#Not translatable while loop");
		
	}else{
	emit("while ");
	trans_bool(n->while_stmt.expr, 1);
	emit(":");
	tabn++;
	emit_tab();
	trans_ast(n->while_stmt.stmt);
	tabn--;
	}
}

static void trans_return_stmt(ast_node *n)
{
	emit("\n");
	emit_tab();
	emit("return ");
    trans_ast(n->return_stmt.retval);
}

static void trans_binop(ast_node *n)
{	
	if(((is_type_of_string(n->binop.lhs->type_id))||(is_type_of_string(n->binop.rhs->type_id)))&&(binop_instr(n->binop.op)=="+=")){
	emit("#It's impossible to convert the equivalent operation");}else{
    trans_ast(n->binop.lhs);
    emit(" %s ", binop_instr(n->binop.op));
    trans_ast(n->binop.rhs);
	}
}

static void trans_prefix(ast_node *n)
{
	emit("%c", n->prefix.op);
    trans_ast(n->prefix.unary);	
}

static void trans_postfix(ast_node *n)
{	
    trans_ast(n->postfix.unary);
}

static void trans_func_call(ast_node *n)
{
    trans_ast(n->func_call.postfix);
    emit("(");
    if (n->func_call.args) {
    	split = ", ";
    	trans_ast(n->func_call.args);
    	split = "";
    }
    emit(")");
}

static void trans_id(ast_node *n) {
	char *s = symname(n->id.sym_name);
	emit("%s", s);
}

static void trans_const(ast_node *n) {
	emit("%d", n->constant.number);
}

int binop_reuse(int op)
{
    switch (op)
    {
    case '=':
    case ADD_ASSIGN:
        return 1;
    }
    return 0;
}

static void init_ast_translators()
{
    if (g_ast_translators[0]) return;

    g_ast_translators[AST_LIST] = trans_list;
    g_ast_translators[AST_FUNCDEF] = trans_funcdef;
    g_ast_translators[AST_FUNCHEAD] = trans_funchead;
    g_ast_translators[AST_PARA] = trans_para;
    g_ast_translators[AST_VAR] = trans_var;
    g_ast_translators[AST_COMPOUND_STMT] = trans_compound_stmt;
    g_ast_translators[AST_IN_STMT] = trans_in_stmt;
    g_ast_translators[AST_OUT_STMT] = trans_out_stmt;
    g_ast_translators[AST_EXPR_STMT] = trans_expr_stmt;
    g_ast_translators[AST_IF_STMT] = trans_if_stmt;
    g_ast_translators[AST_FOR_STMT] = trans_for_stmt;
    g_ast_translators[AST_DO_STMT] = trans_do_stmt;
    g_ast_translators[AST_WHILE_STMT] = trans_while_stmt;
    g_ast_translators[AST_RETURN_STMT] = trans_return_stmt;
    g_ast_translators[AST_DEF] = trans_def;
    g_ast_translators[AST_S_DEF] = trans_def_s;
    g_ast_translators[AST_F_DEF] = trans_def_f;
    g_ast_translators[AST_DEC] = trans_dec;
    g_ast_translators[AST_STR] = trans_str;
    g_ast_translators[AST_REAL] = trans_real;
    g_ast_translators[AST_BINOP] = trans_binop;
    g_ast_translators[AST_PREFIX] = trans_prefix;
    g_ast_translators[AST_POSTFIX] = trans_postfix;
    g_ast_translators[AST_FUNC_CALL] = trans_func_call;
    g_ast_translators[AST_ID] = trans_id;
    g_ast_translators[AST_CONST] = trans_const;


    g_ast_names[AST_LIST] = "trans_list";
    g_ast_names[AST_FUNCDEF] = "trans_funcdef";
    g_ast_names[AST_FUNCHEAD] = "trans_funchead";
    g_ast_names[AST_PARA] = "trans_para";
    g_ast_names[AST_VAR] = "trans_var";
    g_ast_names[AST_COMPOUND_STMT] = "trans_compound_stmt";
	g_ast_names[AST_IN_STMT] = "trans_in_stmt";
	g_ast_names[AST_OUT_STMT] = "trans_out_stmt";
    g_ast_names[AST_EXPR_STMT] = "trans_expr_stmt";
    g_ast_names[AST_IF_STMT] = "trans_if_stmt";
    g_ast_names[AST_DO_STMT] = "trans_do_stmt";
    g_ast_names[AST_WHILE_STMT] = "trans_while_stmt";
    g_ast_names[AST_RETURN_STMT] = "trans_return_stmt";
    g_ast_names[AST_DEF] = "trans_def";
    g_ast_names[AST_S_DEF] = "trans_def_s";
    g_ast_names[AST_F_DEF] = "trans_def_f";
    g_ast_names[AST_DEC] = "trans_dec";
    g_ast_names[AST_STR] = "trans_str";
    g_ast_names[AST_REAL] = "trans_real";
    g_ast_names[AST_BINOP] = "trans_binop";
    g_ast_names[AST_PREFIX] = "trans_prefix";
    g_ast_names[AST_POSTFIX] = "trans_postfix";
    g_ast_names[AST_FUNC_CALL] = "trans_func_call";
    g_ast_names[AST_ID] = "trans_id";
    g_ast_names[AST_CONST] = "trans_const";

}

void trans_ast(ast_node *n)
{
    init_ast_translators();
    if (n)
    {
        #ifdef DEBUG
            fprintf(stderr, "[DEBUG] trans_ast n->type=%s\n", g_ast_names[n->type]);
        #endif

        g_ast_translators[n->type](n);
    }
}

int main_sym;

void transtext_ast(ast_node *n)
{	   
    trans_ast(n);    
}

