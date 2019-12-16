/****************************************************************************

 main.c:
 Contains the main() function which drives the whole parsing process.

*****************************************************************************/

#include <stdio.h>
#include "c++2python.h"
#include "c++2python.tab.h"
#define DEBUG

static ast_node *g_parse_tree;

void yyerror(char const *s)
{
    fprintf(stdout, "Error.\n");
    fprintf(stderr, "%s\n", s);
	
}

void set_parse_tree(ast_node *tree)
{
    g_parse_tree = tree;
}

int main(int argc, char **argv)
{
    if (argc > 1) {
    	freopen(argv[1], "r", stdin);
    }
    if (argc > 2) freopen(argv[2], "w", stdout);

    yyparse(); 

    if (g_parse_tree) 
    {       

        check_semantics(g_parse_tree); 
        transtext_ast(g_parse_tree);
		printf("\nmain()");
		
		#ifdef DEBUG                   
			freopen("tree.htm", "w", stdout);
            printf("Parse tree:\n");
            print_ast(g_parse_tree);
        #endif
    }

    return 0;
}
