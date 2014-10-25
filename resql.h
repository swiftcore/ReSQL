/*
 * structure and function Declarations for a rewriting sql compiler
 */
#ifndef RESQL_H_INCLUDED
#define RESQL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* buffer size for the symbol name space */
#define BUFSIZE 64

/*
 * nodes for attribute
 */
struct attrnode{
     char* name;
     struct attrnode* next;
};
typedef struct attrnode attr;
typedef struct attrnode* attrlist;

/*
 * nodes for table
 */
struct tablenode{
     char* name;
     attrlist keys;
     attrlist attrs;
     struct tablenode* next;
};
typedef struct tablenode table;

/*
 * This graph illustrate how is the table list being orgnized.
 *
 * table list
 *  | head
 * +------------------+	     +-----------------+	   	 +-----------------+
 * | / / / / / / / |  |	     |	  name 	    |  |	   	 |    name     	|  |
 * |---------------| ------->|--------------| -------> ... ----->|--------------| ------+
 * | / / / |  /	/ /|  |	     | keys | attrs |  |		 | keys	| attrs	|  |	|
 * +------------------+	     +---|------|------+		 +---|------|------+	=
 *			       	 |     	|			     |	    |
 *			         |      |   			    ...	   ...
 *			       	 |  	|
 *			       	 |  	|    |attr list head
 *			       	 |     	|    +----------+   +----------+		 +----------+
 *     	       	       	       	 |     	|    | / / / | 	|   |  	    |  |		 |	 |  |
 *			       	 |     	+--->|/	/ / /| ---->| name  | -------> ... ----->| name	 | --------+
 *				 |	     | / / / | 	|   |	    |  |      		 |	 |  |	   |
 *				 |	     +----------+   +----------+       	       	 +----------+  	   |
 *				 |    |key list head				    			   =
 *				 |    +----------+   +----------+  		  +----------+
 *				 |    |	/ / / |	 |   |	    |  	|   		  |	 |   |
 *				 +--->|/ / / /|	---->| name |  -------> ... ----->| name | -------+
 *				      |	/ / / |	 |   |	    | 	| 		  |	 |   |	  |
 *				      +----------+   +----------+		  +----------+	  =
 *
 *
 *
 */
typedef struct tablenode* tablelist;

/*
 * nodes for alias-name table translate
 */
struct aliasnode
{
     char* name;
     char* alias;
     struct aliasnode* next;
};

/*
 * This graph illustrate how the ailaslist is orgnized.
 * It is used for translate between tablename and its alias name.
 *
 *
 * |alias list head
 * +------------------+	   +------------------+		      +------------------+
 * | / / / | / / / |  |	   |	   | 	   |  |		      |	      |       |	 |
 * |/ /	/ /|/ /	/ /| ----->| name  | alias | -----> ... ----->|	name  | alias |	-----+
 * | / / / | / / / |  |	   |	   | 	   |  |		      |	      |       |	 |   |
 * +------------------+	   +------------------+		      +------------------+   |
 *		     								     =
 *
 *
 *
 */
typedef struct aliasnode* aliaslist;

/*
 * nodes for expr-list
 */
struct exprlistnode{
     struct ast* expr;
     struct exprlistnode* next;
};

/*
 * This graph illustrate how the exprlist is orgnized.
 * It is classify KJ,NKJ and SC, the three different kind of expression, with the same kind in one list.
 *
 *
 * |expr list head
 * +------------------+	   +------------------+		      +------------------+
 * | / / / / / / / |  |	   |	     	   |  |		      |	              |	 |
 * |/ /	/ / / /	/ /| ----->| expr-pointer  | -----> ... ----->|	expr-pointer  |	-----+
 * | / / / / / / / |  |	   |	   | 	   |  |		      |	      |       |	 |   |
 * +------------------+	   +-------|----------+		      +-------|----------+   |
 *		     		   |				      |		     =
 *				   |				      |
 *				 expr  	       	       	       	    expr
 *
 *
 *
 */
typedef struct exprlistnode* exprlist;

/*
 * nodes defination for join-graph
 */
struct join_graph_node{
     char* dist_t;
     char* dist_a;
     char* src_t;
     char* src_a;
     struct join_graph_node* next;
};
typedef struct join_graph_node* pjoin_graph_node;

struct join_graph_nodelist_node{
     char* tb_name;
     char* key_name;
     int in_degree;
     struct join_graph_node* node;
     struct join_graph_nodelist_node* next;
};

/*
 * This graph illustrates how the join graph is being orgnized.
 * It is a key data structrue implements the rewriting algorithm.
 * We use it to:
 * 1. get the root of the join graph
 * 2. check if the query is a tree query, also the semantic check
 * 3. generate the LOJ (left outer join) sequences.
 *
 * |join graph head
 * +---------+
 * | / / |   |
 * |/ /	/|   |
 * | / / | | |
 * +-------|-+
 *	   |		  +------------------+	   		+------------------+
 *   +-----+		  | dist_t     |     |	   		| dist_t     |	   |
 *   |			  |------------|     |	   		|------------|	   |
 * +------------------+	  | dist_a     |     |	   		| dist_a     |	   |
 * |   tb_name 	|   ----->|------------|  --------> ... ------->|------------|	-------------+
 * |------------| node|	  | src_t      |     |	     		| src_t	     |	   |	     |
 * |  key_name 	|-----|	  |------------|     |			|------------|	   |	     |
 * |------------|     |	  | src_a      |     |		       	| src_a	     |	   |	     =
 * | in_degree	|  |  |	  +------------------+		       	+------------------+
 * +---------------|--+
 *   		   |
 *   +-------------+
 *   |
 *   ...
 *   |
 * +------------------+
 * |   tb_name	|   ------> ... -----> ... -----+
 * |------------| node|	     	  		|
 * |  key_name 	|-----|	     			=
 * |------------|     |
 * | in_degree 	|  |  |
 * +---------------|--+
 *		   |
 *	 +---------+
 *	 |
 *	 =
 */
typedef struct join_graph_nodelist_node* pjoin_graph_nodelist;

struct loj_queue_node{
     pjoin_graph_node node;
     struct loj_queue_node* next;
};

/*
 * This graph illustrate how the loj queue is being orgnized.
 * It is classify KJ,NKJ and SC, the three different kind of expression, with the same kind in one list.
 *
 *
 * |loj queue head 					      |loj queue tail
 * +------------------+	   +------------------+		      +------------------+
 * | / / / / / / / |  |	   |	     	   |  |		      |	              |	 |
 * |/ /	/ / / /	/ /| ----->| node-pointer  | -----> ... ----->|	node-pointer  |	-----+
 * | / / / / / / / |  |	   |	   | 	   |  |		      |	      |       |	 |   |
 * +------------------+	   +-------|----------+		      +-------|----------+   |
 *		     		   |				      |		     =
 *				   |				      |
 *			      a join graph node	       	       	 a join graph node
 *
 *
 *
 */
typedef struct loj_queue_node* loj_queue;

int rewrite_kind;
tablelist all_tables;
aliaslist trans_table;
exprlist kj_head,kj_tail;
exprlist nkj_head,nkj_tail;
exprlist sc_head,sc_tail;
char signs[BUFSIZE];
int signs_len;
int only_attr_cmd;
pjoin_graph_nodelist jg_head;
char* schema_fname;

/* nodes in the Abstract Syntax Tree */
/* all have common initial nodetype */

struct ast {
     /*
      * ast includes all the expr types and unterminal types
      * 'I': integer
      * 'L': float
      * 'S': string
      * 'N': symref
      * 'F': build-in functions
      * 'C': user-call
      * '+': add
      * '-': minus
      * '*': multiple
      * '/': divide
      * '%': mod
      * 'D': NAME.NAME
      * 'M': - expr
      * 'A': and
      * 'O': or
      * 'T': not
      * '1': <
      * '2': >
      * '3': !=
      * '4': =
      * '5': <=
      * '6': >=
      * 'U': null
      * 'M': - expr
      * 'B': bool
      * 'E': exists
      * 'K': like
      * 'W': between...and...
      * 'Q': in
      * 'v': val_list
      * 's': select_expr_list
      * 'g': groupby_list
      * 'r': table_references
      * 'f': table_factor
      * 't': join_table
      * 'c': join_condition
      * 'i': index_list
      * 'm': select_stmt
      */
     int node_type;
     struct ast *l;
     struct ast *r;

     /* specially for between..and... */
     struct ast* rr;
};
typedef struct ast* past;

/* built-in function */
struct fncall {
     int node_type;			/* type F */
                          /* only count function currently */
     struct ast *l;  /* list of arguments */
};
typedef struct fncall* pfncall;

/* user function */
struct ufncall {
  int node_type;			/* type C */
  struct ast *l;		/* list of arguments */
  struct symref *s;
};
typedef struct ufncall* pufncall;

struct select_expr_list {
     int node_type;                     /* type s */
     /* one select expression */
     struct ast* expr;

     /* options for alias for
      * table or attribute
      * name
      */
     struct symref*  as_alias;
     struct select_expr_list* next;
};
typedef struct select_expr_list* pselect_expr_list;

struct groupby_list{

     int node_type;                     /* type g */
     struct ast* expr;
     /* options for group by | order by orders
      * 0: no options and  for asc
      * 1: for desc
      */
     int opt_asc_desc;
     struct groupby_list* next;
};
typedef struct groupby_list* pgroupby_list;

struct table_references{
     int node_type;                     /* type r */
     /* to use which generation form
      * 1: table_factor
      * 2: join_table
      */
     int ref_type;
     struct ast* table_ref;
     struct table_references* next;
};
typedef struct table_references* ptable_references;

struct table_factor{
     int node_type;                     /* type f */
     /* to use which generation form
      * 1: NAME opt_as_alias index_hint  // opt_as_alias is also a NAME
      * 2: NAME.NAME opt_as_alias index_hint
      * 3: table_subquery opt_as NAME
      * 4: (table_references)
      */
     int factor_type;
     struct symref* s;
     struct symref* s2;
     struct symref* s3;
     struct ast* l;
};
typedef struct table_factor* ptable_factor;

struct join_table{
     int node_type;                      /* type t */

     /* define all the join types
      * to use which generation form
      * 64: JOIN
      * 65: INNER JOIN
      * 66: CROSS JOIN
      *
      * 128: STRAIGHT_JOIN
      *
      * 193: LEFT
      * 197: LEFT OUTER
      * 194: RIGHT
      * 198: RIGHT OUTER
      *
      * 257: NATRAL LEFT
      * 261: NATRAL LEFT OUTER
      * 258: NATRAL RIGHT
      * 262: NATRAL RIGHT OUTER
      * 256: NATRAL
      */
     int join_type;
     struct ast* table_ref;
     struct ast* table_fct;
     struct ast* join_cond;
     /* need to modified */
};
typedef struct join_table* pjoin_table;

struct join_condition{
     int node_type;                     /* type c */
     /*
      * define the condition type
      * to use which generation form
      * 1: ON expr
      * 2: USING (column_list) , column_list is a kind of val_list
      */
     int con_type;
     struct ast* l;
};
typedef struct join_condition* pjoin_condition;

struct index_list{
     int node_type;                     /* type i */
     /*
      * the symbol referenced;
      */
     struct symref* s;
     struct index_list* next;
};
typedef struct index_list* pindex_list;


/* the defination for a full possible format
* of the select statement
*/
struct select_stmt{
     int node_type;                     /* type m */
     /* the type of select options
      * 0: no options
      * 1: all
      * 2: distinct
      * 3: distinct all
      * 4: distinctrow
      * 5: distinctrow all
      * 6: distinct distinctrow
      * 7: distinct distinctrow all
      */
     int sel_type;
     struct select_expr_list* sel_expr_list;
     struct table_references* table_refs;

     /* options for where conditions */
     struct ast* opt_where_expr;

     /* group by attrs list */
     struct groupby_list* gpb_list;

     /* options for having conditions */
     struct ast* opt_having_expr;

     /* order by attr list */
     struct groupby_list* odb_list;
};
typedef struct select_stmt* pselect_stmt;

struct intval {
     int node_type;			/* type I */
     int number;
};
typedef struct intval* pintval;

struct floatval {
     int node_type;              /* type L */
     double number;
};
typedef struct floatval* pfloatval;

struct strval {
     int node_type;             /* type S */
     char* str;
};
typedef struct strval* pstrval;


struct symref {
     int node_type;			/* type N */
     struct symbol *s;
};
typedef struct symref* psymref;

/* symbol table */
struct symbol{      /* a variable name */
     char *name;
};
typedef struct symbol* psymbol;

/* simple symtab of fixed size */
#define NHASH 9997

struct symbol symtab[NHASH];

/* list of symbols, for an argument list */
struct symlist {
  past expr;
  struct symlist *next;
};

void init_symtab();
psymbol newsymbol(char* s);

struct symlist *newsymlist(struct ast* expr, struct symlist *next);
void symlistfree(struct symlist *sl);

/* build an AST */
past newast(int node_type,past l, past r, past rr);
past newcmp(int cmp_type,past l, past r);
past newfunc(past l);
past newcall(past s, past l);
past newselect_expr_list(past exp, past als, past n);
past newgroupby_list(int opt_ad, past expr,past n);
past newtable_references(int reft, past table_r, past n);
past newtable_factor(int factor_t, past s, past s2, past s3, past l);
past newjoin_table(int join_type, past table_r, past table_f, past join_c);
past newjoin_condition(int join_t,past expr);
past newindex_list(past s, past n);
past newselect_stmt(int sel_t, past sel_el, past table_rs, past opt_w, past gpb_l,past opt_h, past odb);
past newint(int n);
past newfloat(double f);
past newstring(char* s);
past newsymref(psymbol s);

/* free the AST tree nodes */
void free_select_expr_list(pselect_expr_list a);
void free_groupby_list(pgroupby_list a);
void free_table_references(ptable_references a);
void free_table_factor(ptable_factor a);
void free_join_table(pjoin_table a);
void free_join_condition(pjoin_condition a);
void free_index_list(pindex_list a);
void free_select_stmt(pselect_stmt a);
void free_fncall(pfncall a);
void free_ufncall(pufncall a);
void free_ast(past a);

/* emit the AST tree nodes */
void emit_expr(past pa);
void emit_null(past pa, const char* app);
void emit_bool(past pa, const char* app);
void emit_in(past pa, const char* app);
void emit_like(past pa, const char* app);
void emit_fncall(pfncall pa);
void emit_ufncall(pufncall pa);
void emit_compare(past pa, const char* comp);
void emit_select_expr_list(pselect_expr_list psel_l);
void emit_table_factor(ptable_factor ptf);
void emit_index_list(pindex_list pil);
void emit_join_condition(pjoin_condition pjc);
void emit_join_table_base(pjoin_table pjt, const char* app);
void emit_join_table(pjoin_table pjt);
void emit_table_references(ptable_references ptr);
void emit_groupby_list(pgroupby_list pgpb_l);
void emit_select_stmt(pselect_stmt stmt);

/* manipulation of rewriting sql data-structure */
tablelist newtable(char* name);
attrlist newattr(char* name);
loj_queue newloj_queue_node();
attrlist build_attrs(FILE* fp, int n);
tablelist build_table(FILE* fp);
void print_tables(tablelist head);
tablelist build_tables(const char* filename);
void free_attrs(attrlist head);
void free_tables();
aliaslist build_trans_table(ptable_references tb_refs);
void free_trans_table(aliaslist al);
void init_expr_lists();
void free_expr_list(exprlist el);
void insert_kj_expr(past expr);
void insert_nkj_expr(past expr);
void insert_sc_expr(past expr);
void emit_kj_exprs();
void emit_nkj_exprs();
void emit_sc_exprs();
void emit_nsc_exprs();
char* translate(char* alias);
char* anti_translate(char* tbn);
char* get_key(const char* tbn);
void init(past stmt);
void clear(past stmt);

/* sql rewriting functions */
void emit_rewriting_select_opts(int sel_type);
//void rewrite_join();
void semantic_error(const char* s, ...);

/* symtab lookup and insert item */
psymbol lookup(const char* sym);

/* interface to the lexer */
extern int yylineno; /* from lexer */
void yyerror(const char *s, ...);
void emit(const char *s, ...);
void sparse(int ac, char **av);

extern int debug;
void dumpast(struct ast *a, int level);

#endif // RESQL_H_INCLUDED
