/* The parser specification file for resql compiler
 */
/*
 * Parser for mysql subset
 */
%{
  #include <stdio.h>
  #include <stdlib.h>
  #include <stdarg.h>
  #include <string.h>
  #include "resql.h"
  #include "parser.h"
  
%}

%union {
     int intval;        /* the integer value */
     double floatval;   /* the float value */
     char *strval;      /* the string value */
     int subtok;        /* which kind of comparition and exists */
     struct ast* a;
}
	
	/* names and literal values */

%token <strval> NAME
%token <strval> STRING
%token <intval> INTNUM
%token <intval> BOOL
%token <floatval> APPROXNUM

       /* operators and precedence levels */

%left OR
%left ANDOP
%nonassoc IN IS LIKE REGEXP
%left NOT '!'
%left BETWEEN
%left <subtok> COMPARISON /* = <> < > <= >= <=> */
%left '|'
%left '&'
%left '+' '-'
%left '*' '/' '%' MOD
%left '^'
%nonassoc UMINUS

%token ADD
%token ALL
%token AND
%token AS
%token ASC
%token BETWEEN
%token BY
%token COLUMN
%token CROSS
%token DATE
%token DATETIME
%token DECIMAL
%token DEFAULT
%token DESC
%token DISTINCT
%token DISTINCTROW
%token DIV
%token <subtok> EXISTS
%token FLOAT
%token FOR
%token FROM
%token GROUP
%token HAVING
%token INDEX
%token INNER
%token INT
%token INTEGER
%token JOIN
%token KEY
%token LEFT
%token LIKE
%token MOD
%token NATURAL
%token NOT
%token NULLX
%token NUMBER
%token ON
%token OR
%token ORDER
%token OUTER
%token RIGHT
%token SELECT
%token STRAIGHT_JOIN
%token TABLE
%token TIME
%token UNION
%token UNIQUE
%token USE
%token USING
%token VARCHAR
%token WHERE

 /* functions with special syntax */
%token FCOUNT

%type <intval> select_opts
%type <intval> opt_asc_desc
%type <intval> opt_inner_cross opt_outer
%type <intval> left_or_right opt_left_or_right_outer
%type <intval> opt_for_join
%type <a> stmt select_stmt
%type <a> opt_where opt_groupby opt_having opt_orderby opt_val_list
%type <a> opt_as_alias opt_join_condition
%type <a> groupby_list column_list select_expr_list table_references index_hint index_list val_list
%type <a> table_factor join_table join_condition table_subquery expr

%start stmt_list

%%

stmt_list: stmt ';'
  | stmt_list stmt ';'
  ;

   /* statements: select statement */

stmt: select_stmt { if(rewrite_kind) on_rewrite_aggr($1); else on_rewrite_join($1); emit_expr($1); printf(";\n"); free_ast($1); }
   ;

select_stmt: SELECT select_opts select_expr_list
                        { $$ = newselect_stmt($2,$3,NULL,NULL,NULL,NULL,NULL); }
    | SELECT select_opts select_expr_list
     FROM table_references
     opt_where opt_groupby opt_having opt_orderby   {$$ = newselect_stmt($2,$3,$5,$6,$7,$8,$9); }
;

opt_where: /* nil */   { $$ = NULL; }
   | WHERE expr { $$ = $2; }
   ;

opt_groupby: /* nil */  { $$ = NULL; }
   | GROUP BY groupby_list
                             { $$ = $3; }
   ;

groupby_list: expr opt_asc_desc
                             { $$ = newgroupby_list($2,$1,NULL); }
   | groupby_list ',' expr opt_asc_desc
                             { $$ = newgroupby_list($4,$3,$1); }
   ;

opt_asc_desc: /* nil */ { $$ = 0; }
   | ASC                { $$ = 0; }
   | DESC               { $$ = 1; }
   ;

opt_having: /* nil */   { $$ = NULL; }
   | HAVING expr { $$ = $2; }
   ;

opt_orderby: /* nil */  { $$ = NULL; }
   | ORDER BY groupby_list { $$ = $3; }
   ;

column_list: NAME { $$ = newast('v',newsymref(newsymbol($1)),NULL,NULL); free($1); }
  | column_list ',' NAME  { $$ = newast('v',newsymref(newsymbol($3)),$1,NULL); free($3); }
  ;

select_opts:                          { $$ = 0; }
| select_opts ALL                 { if($$ & 01) yyerror("duplicate ALL option"); $$ = $1 | 01; }
| select_opts DISTINCT            { if($$ & 02) yyerror("duplicate DISTINCT option"); $$ = $1 | 02; }
| select_opts DISTINCTROW         { if($$ & 04) yyerror("duplicate DISTINCTROW option"); $$ = $1 | 04; }
  ;

select_expr_list: expr opt_as_alias { $$ = newselect_expr_list($1,$2,NULL); }
    | select_expr_list ',' expr opt_as_alias { $$ = newselect_expr_list($3,$4,$1); }
    | '*' { $$ = NULL; }
    ;

table_references:    table_factor { $$ = newtable_references(1,$1,NULL); }
    | join_table   { $$ = newtable_references(2,$1,NULL); }
    | table_references ',' table_factor { $$ = newtable_references(1,$3,$1); }
    | table_references ',' join_table { $$ = newtable_references(2,$3,$1); }
    ;

table_factor:
    NAME opt_as_alias index_hint { $$ = newtable_factor(1,newsymref(newsymbol($1)),$2,NULL,$3);free($1); }
  | NAME '.' NAME opt_as_alias index_hint { $$ = newtable_factor(2,newsymref(newsymbol($1)),newsymref(newsymbol($3)),$4,$5); free($1); free($3); }
  | table_subquery opt_as NAME { $$ = newtable_factor(3,newsymref(newsymbol($3)),NULL,NULL,$1); free($3);  }
  | '(' table_references ')' { $$ = newtable_factor(4,NULL,NULL,NULL,$2); }
  ;

opt_as: AS 
  | /* nil */
  ;

opt_as_alias: AS NAME { $$ = newsymref(newsymbol($2)); free($2); }
  | NAME              { $$ = newsymref(newsymbol($1)); free($1); }
  | /* nil */         { $$ = NULL; }
  ;

join_table:
    table_factor opt_inner_cross JOIN table_factor opt_join_condition
                  { $$ = newjoin_table(0100+$2,$1,$4,$5); }
  | join_table opt_inner_cross JOIN table_factor opt_join_condition
                  { $$ = newjoin_table(0100+$2,$1,$4,$5); }
  | table_factor STRAIGHT_JOIN table_factor opt_join_condition
                  { $$ = newjoin_table(0200,$1,$3,$4); }
  | join_table STRAIGHT_JOIN table_factor opt_join_condition
                  { $$ = newjoin_table(0200,$1,$3,$4); }
  | table_factor left_or_right opt_outer JOIN table_factor join_condition
                  { $$ = newjoin_table(0300+$2+$3,$1,$5,$6); }
  | join_table left_or_right opt_outer JOIN table_factor join_condition
                  { $$ = newjoin_table(0300+$2+$3,$1,$5,$6); }
  | table_factor NATURAL opt_left_or_right_outer JOIN table_factor
                  { $$ = newjoin_table(0400+$3,$1,$5,NULL); }
  | join_table NATURAL opt_left_or_right_outer JOIN table_factor
                  { $$ = newjoin_table(0400+$3,$1,$5,NULL); }
  ;

opt_inner_cross: /* nil */ { $$ = 0; }
   | INNER { $$ = 1; }
   | CROSS  { $$ = 2; }
   ;

opt_outer: /* nil */  { $$ = 0; }
   | OUTER {$$ = 4; }
   ;

left_or_right: LEFT { $$ = 1; }
    | RIGHT { $$ = 2; }
    ;

opt_left_or_right_outer: LEFT opt_outer { $$ = 1 + $2; }
   | RIGHT opt_outer  { $$ = 2 + $2; }
   | /* nil */ { $$ = 0; }
   ;

opt_join_condition: join_condition  { $$ = $1; }
   | /* nil */    { $$ = NULL; }
   ;

join_condition:
    ON expr { $$ = newjoin_condition(1,$2); }
    | USING '(' column_list ')' { $$ = newjoin_condition(2,$3); }
    ;

index_hint:
     USE KEY opt_for_join '(' index_list ')'
                  { $$ = $5; }
   | /* nil */    { $$ = NULL; }
   ;

opt_for_join: FOR JOIN { $$ = 1; }
   | /* nil */ { $$ = 0; }
   ;

index_list: NAME  { $$ = newindex_list(newsymref(newsymbol($1)),NULL); free($1); }
   | index_list ',' NAME { $$ = newindex_list(newsymref(newsymbol($3)),$1); free($3); }
   ;

table_subquery: '(' select_stmt ')' { $$ = $2; }
   ;

   /**** expressions ****/

expr: NAME          { $$ = newsymref(newsymbol($1)); free($1); }
   | NAME '.' NAME { $$ = newast('D',newsymref(newsymbol($1)),newsymref(newsymbol($3)),NULL); free($1); free($3); }
   | STRING        { $$ = newstring($1); free($1); }
   | INTNUM        { $$ = newint($1); }
   | APPROXNUM     { $$ = newfloat($1); }
   | BOOL          { $$ = newint(0); }
   ;

expr: expr '+' expr { $$ = newast('+',$1,$3,NULL); }
   | expr '-' expr { $$ = newast('-',$1,$3,NULL); }
   | expr '*' expr { $$ = newast('*',$1,$3,NULL); }
   | expr '/' expr { $$ = newast('/',$1,$3,NULL); }
   | expr '%' expr { $$ = newast('%',$1,$3,NULL); }
   | expr MOD expr { $$ = newast('%',$1,$3,NULL); }
   | '-' expr %prec UMINUS { $$ = newast('M',$2,NULL,NULL); }
   | expr ANDOP expr { $$ = newast('A',$1,$3,NULL); }
   | expr OR expr { $$ = newast('O',$1,$3,NULL); }
   | expr COMPARISON expr { $$ = newcmp($2,$1,$3); }
   | expr COMPARISON '(' select_stmt ')' { $$ = newcmp($2,$1,$4); }
   | NOT expr { $$ = newast('T',$2,NULL,NULL); }
   | '!' expr { $$ = newast('T',$2,NULL,NULL); }
   ;    

expr:  expr IS NULLX     { $$ = newast('U',$1,NULL,NULL); }
   |   expr IS NOT NULLX { $$ = newast('T',newast('U',$1,NULL,NULL),NULL,NULL); }
   |   expr IS BOOL      { $$ = newast('B',$1,NULL,NULL); }
   |   expr IS NOT BOOL  { $$ = newast('T',newast('B',$1,NULL,NULL),NULL,NULL); }
   ;

expr: expr BETWEEN expr AND expr %prec BETWEEN { $$ = newast('W',$1,$3,$5); }
   ;


val_list: expr { $$ = newast('v',$1,NULL,NULL); }
   | expr ',' val_list { $$ = newast('v',$1,$3,NULL); }
   ;

opt_val_list: /* nil */ { $$ = NULL; }
   | val_list  { $$ = $1; }
   ;

expr: expr IN '(' val_list ')'       { $$ = newast('Q',$1,$4,NULL); }
   | expr NOT IN '(' val_list ')'    { $$ = newast('T',newast('Q',$1,$5,NULL),NULL,NULL); }
   | expr IN '(' select_stmt ')'     { $$ = newast('Q',$1,$4,NULL); }
   | expr NOT IN '(' select_stmt ')' { $$ = newast('T',newast('Q',$1,$5,NULL),NULL,NULL); }
   | EXISTS '(' select_stmt ')'      { if($1)
	                                  $$ = newast('T',newast('E',$3,NULL,NULL),NULL,NULL);
	                               else
	                                  $$ = newast('E',$3,NULL,NULL);}
   ;

expr: NAME '(' opt_val_list ')' {  $$ = newcall(newsymref(newsymbol($1)),$3);
	                            rewrite_kind=1;
				    free($1); }
   ;

  /* functions with special syntax */
expr: FCOUNT '(' '*' ')' { $$ = newfunc(NULL); }
   | FCOUNT '(' expr ')' { $$ = newfunc($3);  }
   ;

expr: expr LIKE expr { $$ = newast('K',$1,$3,NULL); }
   | expr NOT LIKE expr { $$ = newast('T',newast('K',$1,$4,NULL),NULL,NULL); }
   ;

%%


void sparse(int ac, char **av)
{
  extern FILE *yyin;

  if(ac > 1 && !strcmp(av[1], "-d")) {
    ac--; av++;
  }

  if(ac > 1 && (yyin = fopen(av[1], "r")) == NULL) {
    perror(av[1]);
    exit(1);
  }

  yyparse();
  /*
  if(!yyparse())
    printf("SQL parse worked\n");
  else
    printf("SQL parse failed\n");
  */
}
