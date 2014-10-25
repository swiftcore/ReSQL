
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NAME = 258,
     STRING = 259,
     INTNUM = 260,
     BOOL = 261,
     APPROXNUM = 262,
     OR = 263,
     ANDOP = 264,
     REGEXP = 265,
     LIKE = 266,
     IS = 267,
     IN = 268,
     NOT = 269,
     BETWEEN = 270,
     COMPARISON = 271,
     MOD = 272,
     UMINUS = 273,
     ADD = 274,
     ALL = 275,
     AND = 276,
     AS = 277,
     ASC = 278,
     BY = 279,
     COLUMN = 280,
     CROSS = 281,
     DATE = 282,
     DATETIME = 283,
     DECIMAL = 284,
     DEFAULT = 285,
     DESC = 286,
     DISTINCT = 287,
     DISTINCTROW = 288,
     DIV = 289,
     EXISTS = 290,
     FLOAT = 291,
     FOR = 292,
     FROM = 293,
     GROUP = 294,
     HAVING = 295,
     INDEX = 296,
     INNER = 297,
     INT = 298,
     INTEGER = 299,
     JOIN = 300,
     KEY = 301,
     LEFT = 302,
     NATURAL = 303,
     NULLX = 304,
     NUMBER = 305,
     ON = 306,
     ORDER = 307,
     OUTER = 308,
     RIGHT = 309,
     SELECT = 310,
     STRAIGHT_JOIN = 311,
     TABLE = 312,
     TIME = 313,
     UNION = 314,
     UNIQUE = 315,
     USE = 316,
     USING = 317,
     VARCHAR = 318,
     WHERE = 319,
     FCOUNT = 320
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 16 "resql.y"

     int intval;        /* the integer value */
     double floatval;   /* the float value */
     char *strval;      /* the string value */
     int subtok;        /* which kind of comparition and exists */
     struct ast* a;



/* Line 1676 of yacc.c  */
#line 127 "parser.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


