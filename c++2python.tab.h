/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_C_2PYTHON_TAB_H_INCLUDED
# define YY_YY_C_2PYTHON_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    SHL_OP = 258,
    SHR_OP = 259,
    LE_OP = 260,
    GE_OP = 261,
    EQ_OP = 262,
    NE_OP = 263,
    AND_OP = 264,
    OR_OP = 265,
    ADD_ASSIGN = 266,
    IDENTIFIER = 267,
    CONSTANT = 268,
    CONSTANT_STRING = 269,
    CONSTANT_F = 270,
    INT = 271,
    FLOAT = 272,
    STRING = 273,
    CIN = 274,
    COUT = 275,
    IF = 276,
    ELSE = 277,
    FOR = 278,
    CONTINUE = 279,
    BREAK = 280,
    RETURN = 281,
    READ = 282,
    DO = 283,
    WHILE = 284,
    EXTDEFS = 285,
    PARAS = 286,
    STMTS = 287,
    DEFS = 288,
    DECS = 289,
    ARGS = 290,
    LIB1 = 291,
    LIB2 = 292
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 6 "c++2python.y" /* yacc.c:1909  */

    int i;
    struct ast_node *n;
	char* s;
	float f;

#line 99 "c++2python.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_C_2PYTHON_TAB_H_INCLUDED  */
