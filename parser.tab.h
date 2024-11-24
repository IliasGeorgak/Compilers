/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
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
    TK_STRING = 258,
    TK_IDENT = 259,
    TK_INT = 260,
    TK_REAL = 261,
    KW_TRUE = 262,
    KW_FALSE = 263,
    KW_IF = 264,
    KW_ELSE = 265,
    TK_AND = 266,
    TK_OR = 267,
    TK_NOT = 268,
    TK_MOD = 269,
    TK_POWER = 270,
    TK_COMP_GR = 271,
    TK_COMP_LESS = 272,
    TK_COMP = 273,
    TK_COMP_NEQ = 274,
    TK_COMP_LEQ = 275,
    TK_COMP_GEQ = 276,
    TK_ASSGN_IN = 277,
    TK_ASSGN_DE = 278,
    TK_ASSGN_MU = 279,
    TK_ASSGN_DIV = 280,
    TK_ASSGN_MOD = 281,
    TK_ARROW = 282,
    TK_ARRAY_CR = 283,
    TK_MEMBER = 284,
    KW_INT = 285,
    KW_SCA = 286,
    KW_STR = 287,
    KW_BOOL = 288,
    KW_CONST = 289,
    KW_ENDIF = 290,
    KW_FOR = 291,
    KW_IN = 292,
    KW_ENDFOR = 293,
    KW_WHILE = 294,
    KW_ENDWHILE = 295,
    KW_BREAK = 296,
    KW_CONT = 297,
    KW_COMP = 298,
    KW_ENDCOMP = 299,
    KW_OF = 300,
    KW_DEF = 301,
    KW_ENDDEF = 302,
    KW_MAIN = 303,
    KW_RET = 304
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 67 "parser.y"

  char* str;

#line 111 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
