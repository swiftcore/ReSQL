/* the resql compiler scanner specification file,
 * which only include the select statement of the sql lauguage.
 */
/*
 * Scanner for mysql subset
 */

%option noyywrap nodefault yylineno case-insensitive
%{
#include "parser.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

void yyerror(char *s, ...);
int oldstate;

%}

%s BTWMODE

%%

  /* keywords */

ADD	{ return ADD; }
ALL	{ return ALL; }

  /* Hack for BETWEEN ... AND ... 
   * return special AND token if BETWEEN seen
   */
<BTWMODE>AND	{ BEGIN INITIAL; return AND; }
AND	{ return ANDOP; }
AS	{ return AS; }
ASC	{ return ASC; }
BETWEEN	{ BEGIN BTWMODE; return BETWEEN; }
BY	{ return BY; }
COLUMN	{ return COLUMN; }
CROSS	{ return CROSS; }
DATE	{ return DATE; }
DATETIME	{ return DATETIME; }
NUMERIC|DEC|DECIMAL	{ return DECIMAL; }
DEFAULT	{ return DEFAULT; }
DESC	{ return DESC; }
DISTINCT	{ return DISTINCT; }
DISTINCTROW	{ return DISTINCTROW; }
DIV	{ return DIV; }
EXISTS	{ yylval.subtok = 0; return EXISTS; }
NOT[ \t\n]+EXISTS	{ yylval.subtok = 1; return EXISTS; }
FLOAT4?	{ return FLOAT; }
FOR	{ return FOR; }
FROM	{ return FROM; }
GROUP	{ return GROUP; }
HAVING	{ return HAVING; }
IN	{ return IN; }
INNER	{ return INNER; }
INT4?|INTEGER	{ return INTEGER; }
IS	{ return IS; }
JOIN	{ return JOIN; }
INDEX|KEY	{ return KEY; }
LEFT	{ return LEFT; }
LIKE	{ return LIKE; }
MOD	{ return MOD; }
NATURAL	{ return NATURAL; }
NOT	{ return NOT; }
NULL	{ return NULLX; }
NUMBER	{ return NUMBER; }
ON	{ return ON; }
OR	{ return OR; }
ORDER	{ return ORDER; }
OUTER	{ return OUTER; }
RIGHT	{ return RIGHT; }
SELECT	{ return SELECT; }
STRAIGHT_JOIN	{ return STRAIGHT_JOIN; }
TABLE	{ return TABLE; }
TIME	{ return TIME; }
UNION	{ return UNION; }
UNIQUE	{ return UNIQUE; }
USE	{ return USE; }
USING	{ return USING; }
VARCHAR(ACTER)?	{ return VARCHAR; }
WHERE   { return WHERE; }

   /* numbers */

-?[0-9]+	        { yylval.intval = atoi(yytext); return INTNUM; } 

-?[0-9]+"."[0-9]* |
-?"."[0-9]+	        { yylval.floatval = atof(yytext) ;
                                  return APPROXNUM; }
    /* booleans */
TRUE	{ yylval.intval = 1; return BOOL; }
UNKNOWN	{ yylval.intval = -1; return BOOL; }
FALSE	{ yylval.intval = 0; return BOOL; }

   /* strings */

'(\\.|''|[^'\n])*'	|
\"(\\.|\"\"|[^"\n])*\"  { yylval.strval = strdup(yytext); return STRING; }

'(\\.|[^'\n])*$	        { yyerror("Unterminated string %s", yytext); }
\"(\\.|[^"\n])*$	{ yyerror("Unterminated string %s", yytext); }

   /* hex strings */
X'[0-9A-F]+' |  
0X[0-9A-F]+  { yylval.strval = strdup(yytext); return STRING; }

   /* bit strings */

0B[01]+      |
B'[01]+'     { yylval.strval = strdup(yytext); return STRING; }


   /* operators */
[-+&~|^/%*(),.;!]   { return yytext[0]; }

"&&"		{ return ANDOP; }
"||"            { return OR; }

"="	{ yylval.subtok = 4; return COMPARISON; }
">="	{ yylval.subtok = 6; return COMPARISON; }
">"	{ yylval.subtok = 2; return COMPARISON; }
"<="	{ yylval.subtok = 5; return COMPARISON; }
"<"	{ yylval.subtok = 1; return COMPARISON; }
"!="	|
"<>"	{ yylval.subtok = 3; return COMPARISON; }


	/* 
         * peek ahead and return function if name(
         */
COUNT    { int c = input(); unput(c);
           if(c == '(') return FCOUNT;
           yylval.strval = strdup(yytext);
           return NAME; }

[A-Za-z][A-Za-z0-9_]*	{ yylval.strval = strdup(yytext);
                          return NAME; }
`[^`/\\.\n]+`           { yylval.strval = strdup(yytext+1);
                          yylval.strval[yyleng-2] = 0;
                          return NAME; }

`[^`\n]*$               { yyerror("unterminated quoted name %s", yytext); }


@\"[^"\n]*$ { yyerror("unterminated quoted user variable %s", yytext); }
@`[^`\n]*$ { yyerror("unterminated quoted user variable %s", yytext); }
@'[^'\n]*$ { yyerror("unterminated quoted user variable %s", yytext); }


	/* everything else */
[ \t\n]         /* white space */
.               { yyerror("mystery character '%c'", *yytext); }

%%

