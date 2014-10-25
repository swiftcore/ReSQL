/*
 * All resql compiler useful functions
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "resql.h"

// build a new symbol node and return its addr
psymbol newsymbol(char* s)
{
     psymbol sp = (psymbol)malloc(sizeof(struct symbol));
     sp->name = strdup(s);

     return sp;
}

// build a new abstract syntax tree node and return its addr
past newast(int node_type,past l, past r, past rr)
{
     past a = (past)malloc(sizeof(struct ast));

     if(!a)
     {
	  yyerror("out of space");
	  exit(0);
     }

     a->node_type = node_type;
     a->l = l;
     a->r = r;
     a->rr = rr;

     return a;
}

// build a int node and return its addr
past newint(int n)
{
     pintval a = (pintval)malloc(sizeof(struct intval));

     if(!a)
     {
	  yyerror("out of space");
	  exit(0);
     }

     a->node_type = 'I';
     a->number = n;

     return (past)a;
}

// build a float node and return its addr
past newfloat(double f)
{
     pfloatval a = (pfloatval)malloc(sizeof(struct floatval));

     if(!a)
     {
	  yyerror("out of space");
	  exit(0);
     }

     a->node_type = 'L';
     a->number = f;

     return (past)a;
}

// build a string node and return its addr
past newstring(char* s)
{
     pstrval a = (pstrval)malloc(sizeof(struct strval));

     if(!a)
     {
	  yyerror("out of space");
	  exit(0);
     }

     a->node_type = 'S';
     a->str = strdup(s);

     return (past)a;
}

// build a symref node and return its addr
past newsymref(psymbol s)
{
     psymref a = (psymref)malloc(sizeof(struct symref));

     if(!a)
     {
	  yyerror("out of space");
	  exit(0);
     }

     a->node_type = 'N';
     a->s = s;

     return (past)a;
}

// build a compare expr node and return its addr
past newcmp(int cmp_type, past l,  past r)
{
     past a = (past)malloc(sizeof(struct ast));

     if(!a)
     {
	  yyerror("out of space");
	  exit(0);
     }

     a->node_type = '0' + cmp_type;
     a->l = l;
     a->r = r;
     a->rr = NULL;

     return a;
}

// build a function node and return its addr
past newfunc(past l)
{
     pfncall a = (pfncall)malloc(sizeof(struct fncall));

     if(!a)
     {
	  yyerror("out of space");
	  exit(0);
     }

     a->node_type = 'F';
     a->l = l;

     return (past)a;
}

// build a user-define function node and return its addr
past newcall(past s, past l)
{
     pufncall a = (pufncall)malloc(sizeof(struct ufncall));

     if(!a)
     {
	  yyerror("out of space");
	  exit(0);
     }

     a->node_type = 'C';
     a->s = (psymref)s;   /* function name */
     a->l = l;

     return (past)a;
}

// build a select expression list node and return its addr
past newselect_expr_list(past exp, past als, past n)
{
     pselect_expr_list a = (pselect_expr_list)malloc(sizeof(struct select_expr_list));

     if(!a)
     {
	  yyerror("out of space");
	  exit(0);
     }

     a->node_type = 's';
     a->expr = exp;
     a->as_alias = (psymref)als;
     a->next = (pselect_expr_list)n;

     return (past)a;
}

// build a groupby list node and return its addr
past newgroupby_list(int opt_ad, past expr, past n)
{
     pgroupby_list a = (pgroupby_list)malloc(sizeof(struct groupby_list));

     if(!a)
     {
	  yyerror("out of space");
	  exit(0);
     }

     a->node_type = 'g';
     a->opt_asc_desc = opt_ad;
     a->expr = expr;
     a->next = (pgroupby_list)n;

     return (past)a;
}

// build a table reference list node and return its addr
past newtable_references(int reft, past table_r, past n)
{
     ptable_references a = (ptable_references)malloc(sizeof(struct table_references));

     if(!a)
     {
	  yyerror("out of space");
	  exit(0);
     }

     a->node_type = 'r';
     a->ref_type = reft;
     a->table_ref = table_r;
     a->next = (ptable_references)n;

     return (past)a;
}

// build a table factor node and return its addr
past newtable_factor(int factor_t, past s, past s2, past s3,past l)
{
     ptable_factor a = (ptable_factor)malloc(sizeof(struct table_factor));

     if(!a)
     {
	  yyerror("out of space");
	  exit(0);
     }

     a->node_type = 'f';
     a->factor_type = factor_t;
     a->s = (psymref)s;
     a->s2 = (psymref)s2;
     a->s3 = (psymref)s3;
     a->l = l;

     return (past)a;
}

// build a join condition node and return its addr
past newjoin_condition(int join_t, past expr)
{
     pjoin_condition a = (pjoin_condition)malloc(sizeof(struct join_condition));

     if(!a)
     {
	  yyerror("out of space");
	  exit(0);
     }

     a->node_type = 'c';
     a->con_type = join_t;
     a->l = expr;

     return (past)a;
}

// build a join table node and return its addr
past newjoin_table(int join_type, past table_r, past table_f, past join_c)
{
     pjoin_table a = (pjoin_table)malloc(sizeof(struct join_table));

     if(!a)
     {
	  yyerror("out of space");
	  exit(0);
     }

     a->node_type = 't';
     a->join_type = join_type;
     a->table_ref = table_r;
     a->table_fct = table_f;
     a->join_cond = join_c;

     return (past)a;
}

// build a index list node and return its addr
past newindex_list(past s, past n)
{
     pindex_list a = (pindex_list)malloc(sizeof(struct index_list));

     if(!a)
     {
	  yyerror("out of space");
	  exit(0);
     }

     a->node_type = 'i';
     a->s = (psymref)s;
     a->next = (pindex_list)n;

     return (past)a;
}

// build a select statement node and return its addr
past newselect_stmt(int sel_t, past sel_el, past table_rs, past opt_w, past gpb_l,past opt_h, past odb)
{
     pselect_stmt a = (pselect_stmt)malloc(sizeof(struct select_stmt));

     if(!a)
     {
	  yyerror("out of space");
	  exit(0);
     }

     a->node_type = 'm';
     a->sel_type = sel_t;
     a->sel_expr_list = (pselect_expr_list)sel_el;
     a->table_refs = (ptable_references)table_rs;
     a->opt_where_expr = opt_w;
     a->gpb_list = (pgroupby_list)gpb_l;
     a->opt_having_expr = opt_h;
     a->odb_list = (pgroupby_list)odb;

     return (past)a;
}

/* for user-define function arguments
 * build a new argument list and return its addr
 */
struct symlist *newsymlist(past expr, struct symlist *next)
{
     struct symlist * sl = (struct symlist*)malloc(sizeof(struct symlist));

     if(!sl)
     {
	  yyerror("out of space");
	  exit(0);
     }

     sl->expr = expr;
     sl->next = next;

     return sl;
}

// free a abstract syntax tree node
void free_ast(past a)
{     
     switch(a->node_type)
     {// three subnodes
     case 'W':  
     {
	  // free .. between .. and ...
	  free_ast(a->l);
	  free_ast(a->r);
	  free_ast(a->rr);
	  free(a);
	  break;
     }
     // two subnodes
     case '+':
     case '-':
     case '*':
     case '/':
     case '%':
     case 'D': // NAME.NAME
     case '1': // free <
     case '2': // free >
     case '3': // free !=
     case '4': // free =
     case '5': // free <=
     case '6': // free >=
     case 'A': // free and
     case 'O': // free or
     case 'Q':  // free in
     case 'K': // free like
     {
	  free_ast(a->l);
	  free_ast(a->r);
	  free(a);
	  break;
     }
     case 'B':  // free bool
     case 'E':  // free exists
     case 'U':  // free null
     case 'M':  // free - expr
     case 'T':  // free not
     {
	  // one subnodes
	  free_ast(a->l);
	  free(a);
	  break;
     }
     case 'F':
     {
	  // free funcions
	  free_fncall((pfncall)a);
	  break;
     }
     case 'C':
     {
	  //free user calls
	  free_ufncall((pufncall)a);
	  break;
     }
     case 'I':
     {
	  // free intval
	  free((pintval)a);
	  break;
     }
     case 'L':
     {
	  // free floatval
	  free((pfloatval)a);
	  break;
     }
     case 'S':
     {
	  // free strval
	  pstrval s = (pstrval)a;
	  free(s->str);
	  free(s);
	  break;
     }
     case 'N':
     {
	  //free symref
	  free((psymref)a);
	  break;
     }
     // special unterminal nodes
     case 'v':
     {
	  //free_val_list(a);
	  if(a->r != NULL)
	       free_ast(a->r);
	  free_ast(a->l);
	  free(a);
	  break;
     }
     case 's':
     {
	  free_select_expr_list((pselect_expr_list)a);
	  break;
     }
     case 'g':
     {
	  free_groupby_list((pgroupby_list)a);
	  break;
     }
     case 'r':
     {
	  free_table_references((ptable_references)a);
	  break;
     }
     case 'f':
     {
	  free_table_factor((ptable_factor)a);
	  break;
     }
     case 't':
     {
	  free_join_table((pjoin_table)a);
	  break;
     }
     case 'c':
     {
	  free_join_condition((pjoin_condition)a);
	  break;
     }
     case 'i':
     {
	  free_index_list((pindex_list)a);
	  break;
     }
     case 'm':
     {
	  free_select_stmt((pselect_stmt)a);
	  break;
     }
     }
}


/* free user-define function argument list */
void symlistfree(struct symlist *sl)
{
     struct symlist* nsl;

     if(sl != NULL)
     {
	 nsl = sl->next;
         while(nsl != NULL)
         {
             free_ast(sl->expr);
	     free(sl);
	     sl = nsl;
	     nsl = sl->next;
         }
     	  
         free_ast(sl->expr);
         sl = nsl;
     }
}

// free a select expression list
void free_select_expr_list(pselect_expr_list a)
{
     if(a->next != NULL)
     {
	  free_select_expr_list(a->next);
     }

     free_ast(a->expr);
     free(a);
}

// free a group by expression list
void free_groupby_list(pgroupby_list a)
{
     if(a->next != NULL)
     {
	  free_groupby_list(a->next);
     }

     free_ast(a->expr);
     free(a);
}

// free a table reference list
void free_table_references(ptable_references a)
{
     if(a->next != NULL)
     {
	  free_table_references(a->next);
     }

     free_ast(a->table_ref);
     free(a);
}

// free a table factor node
void free_table_factor(ptable_factor a)
{
     if(a->l != NULL)
	  free_ast(a->l);
     free(a);
}

// free a join table node
void free_join_table(pjoin_table a)
{
     if(a->table_ref != NULL)
	  free_ast(a->table_ref);
     if(a->table_fct != NULL)
	  free_table_factor((ptable_factor)a->table_fct);
     if(a->join_cond != NULL)
	  free_join_condition((pjoin_condition)a->join_cond);

     free(a);
}

// free a join_condition node
void free_join_condition(pjoin_condition a)
{
     if(a->l != NULL)
	  free_ast(a->l);
     free(a);
}

// free a index list
void free_index_list(pindex_list a)
{
     if(a->next != NULL)
	  free_index_list(a->next);
     free(a);
}

// free a select statement
void free_select_stmt(pselect_stmt a)
{
     if(a->sel_expr_list != NULL)
     {
	  free_select_expr_list(a->sel_expr_list);
     }
     if(a->table_refs != NULL)
     {
	  free_table_references(a->table_refs);
     }
     if(a->opt_where_expr != NULL)
     {
	  free_ast(a->opt_where_expr);
     }
     if(a->gpb_list != NULL)
     {
	  free_groupby_list(a->gpb_list);
     }
     if(a->opt_having_expr != NULL)
     {
	  free_ast(a->opt_having_expr);
     }
     if(a->odb_list != NULL)
     {
	  free_groupby_list(a->odb_list);
     }

     free(a);
}

// free a function 
void free_fncall(pfncall a)
{
     if(a->l != NULL)
	  free_ast(a->l);
     free(a);
}

// free a user define function
void free_ufncall(pufncall a)
{
     if(a->l != NULL)
	  free_ast(a->l);
     free(a);
}

// output a [... is null] expression
void emit_null(past pa, const char* app)
{
     emit_expr(pa->l);
     printf(" is %s null ",app);
}

// output a [... is true] expression
void emit_bool(past pa, const char* app)
{
     emit_expr(pa->l);
     printf(" is %s true",app);
}

// output a [... in ...] expression
void emit_in(past pa, const char* app)
{
     emit_expr(pa->l);
     printf(" %s in (",app);
     emit_expr(pa->r);
     printf(")");
}

// output a [... like ...] expression
void emit_like(past pa, const char* app)
{
     emit_expr(pa->l);
     printf(" %s like ",app);
     emit_expr(pa->r);
}

// output a [... COMP ...] expression
void emit_compare(past pa, const char* comp)
{
     emit_expr(pa->l);
     printf(" %s ",comp);
     if(pa->r->node_type == 'm')
     {
          printf(" ( ");
          emit_select_stmt((pselect_stmt)pa->r);
          printf(" ) ");
     }
     else
          emit_expr(pa->r);
}

// output a function
void emit_fncall(pfncall pa)
{
     printf(" count(");

     if(pa->l == NULL)
     {
	  printf("*");
     }
     else
	  emit_expr(pa->l);
     printf(") ");
}

// output a user define function
void emit_ufncall(pufncall pa)
{
     printf(" %s(",pa->s->s->name);
     if(pa->l == NULL)
     {
	  printf("*");
     }
     else
	  emit_expr(pa->l);
     printf(") ");
}

// output a expression
void emit_expr(past pa)
{
     switch(pa->node_type)
     {
     case 'I':
     {
	  printf(" %d ",((pintval)pa)->number);
	  break;
     }
     case 'L':
     {
	  printf(" %.2f ",((pfloatval)pa)->number);
	  break;
     }
     case 'S':
     {
	  printf(" %s ",((pstrval)pa)->str);
	  break;
     }
     case 'N':
     {
	  printf("%s",((psymref)pa)->s->name);
	  break;
     }
     case 'F':
     {
	  // emit function
	  emit_fncall((pfncall)pa);
	  break;
     }
     case 'C':
     {
	  // emit user call
	  emit_ufncall((pufncall)pa);
	  break;
     }
     case '+':
     {
	  emit_expr(pa->l);
	  printf("+");
	  emit_expr(pa->r);
	  break;
     }
     case '-':
     {
	  emit_expr(pa->l);
	  printf("-");
	  emit_expr(pa->r);
	  break;
     }
     case '*':
     {
	  emit_expr(pa->l);
	  printf("*");
	  emit_expr(pa->r);
	  break;
     }
     case '/':
     {
	  emit_expr(pa->l);
	  printf("/");
	  emit_expr(pa->r);
	  break;
     }
     case '%':
     {
	  emit_expr(pa->l);
	  printf("%%");
	  emit_expr(pa->r);
	  break;
     }
     case 'D':
     {
	  if(!only_attr_cmd){
	      emit_expr(pa->l);
	      printf(".");
	  }
	  emit_expr(pa->r);
	  break;
     }
     case 'M':
     {
	  printf(" -");
	  emit_expr(pa->l);
	  break;
     }
     case 'A':
     {
	  emit_expr(pa->l);
	  printf(" and ");
	  emit_expr(pa->r);
	  break;
     }
     case 'O':
     {
	  emit_expr(pa->l);
	  printf(" or ");
	  emit_expr(pa->r);
	  break;
     }
     case 'T':
     {
	  // need to classify and emit separatively.
	  switch(pa->l->node_type)
	  {
	  case 'U':
	       emit_null(pa->l,"not");
	       break;
	  case 'B':
	       emit_bool(pa->l,"not");
	       break;
	  case 'Q':
	       emit_in(pa->l,"not");
	       break;
	  case 'K':
	       emit_like(pa->l,"not");
	       break;
	  default:
	       printf(" not ");
	       emit_expr(pa->l);
	       break;
	  }
	  
      	  break;
     }
     case '1':
     {
	  emit_compare(pa,"<");	  
	  break;
     }
     case '2':
     {
	  emit_compare(pa,">");
	  break;
     }
     case '3':
     {
	  emit_compare(pa,"!=");
	  break;
     }
     case '4':
     {
	  emit_compare(pa,"=");
	  break;
     }
     case '5':
     {
	  emit_compare(pa,"<=");
	  break;
     }
     case '6':
     {
	  emit_compare(pa,">=");
	  break;
     }
     case 'U':
     {
	  emit_null(pa,"");
	  break;
     }
     case 'B':
     {
	  emit_bool(pa,"");
	  break;
     }
     case 'Q':
     {
	  emit_in(pa,"");
	  break;
     }
     case 'K':
     {
	  emit_like(pa,"");
	  break;
     }
     case 'E':
     {
	  printf(" exists (");
	  emit_select_stmt((pselect_stmt)pa->l);
	  printf(") ");
	  break;
     }
     case 'W':
     {
	  emit_expr(pa->l);
	  printf(" between ");
	  emit_expr(pa->r);
	  printf(" and ");
	  emit_expr(pa->rr);
	  break;
     }
     case 'v':
     {
	  emit_expr(pa->l);
	  if(pa->r != NULL)
	  {
	       printf(",");
	       emit_expr(pa->r);
	  }
	  break;
     }
     case 's':
     {
	  emit_select_expr_list((pselect_expr_list)pa);
	  break;
     }
     case 'g':
     {
	  emit_groupby_list((pgroupby_list)pa);
	  break;
     }
     case 'r':
     {
	  emit_table_references((ptable_references)pa);
	  break;
     }
     case 'f':
     {
	  emit_table_factor((ptable_factor)pa);
	  break;
     }
     case 't':
     {
	  emit_join_table((pjoin_table)pa);
	  break;
     }
     case 'c':
     {
	  emit_join_condition((pjoin_condition)pa);
	  break;
     }
     case 'i':
     {
	  emit_index_list((pindex_list)pa);
	  break;
     }
     case 'm':
     {
	  emit_select_stmt((pselect_stmt)pa);
	  break;
     }
     }
}

// output a select expression list
void emit_select_expr_list(pselect_expr_list psel_l)
{
     if(psel_l == NULL)
     {
	  printf(" * ");
	  return;
     }

     if(psel_l->next != NULL)
     {
	  emit_select_expr_list(psel_l->next);
	  printf(", ");
     }
     
     emit_expr(psel_l->expr);
     if(psel_l->as_alias != NULL)
     {
	  printf(" as ");
	  printf(" %s ", psel_l->as_alias->s->name);
     }
}

// output a table factor node
void emit_table_factor(ptable_factor ptf)
{

     switch(ptf->factor_type)
     {
     case 1:
     {
	  printf(" %s ",ptf->s->s->name);
	  if(ptf->s2 != NULL)
	  {
	       printf(" as %s ",ptf->s2->s->name);
	  }
	  if(ptf->l != NULL)
	  {
	       printf(" !!! here is an index_hint !!! ");
	  }
	  break;
     }
     case 2:
     {
	  printf(" %s.%s ",ptf->s->s->name,ptf->s2->s->name);
	  if(ptf->s3 != NULL)
	  {
	       printf(" as %s ",ptf->s3->s->name);
	  }
	  if(ptf->l != NULL)
	  {
	       printf(" !!! here is an index_hint !!! ");
	  }
	  break;
     }
     case 3:
     {
	  printf(" (");
	  emit_select_stmt((pselect_stmt)ptf->l);
	  if(ptf->s != NULL)
	  {
	       printf("  as %s ",ptf->s->s->name);
	  }
	  printf(") ");
	  break;
     }
     case 4:
     {
	  printf(" (");
	  emit_table_references((ptable_references)ptf->l);
	  printf(") ");
	  break;
     }
     }
}

// output a index list
void emit_index_list(pindex_list pil)
{
     printf(" %s ",pil->s->s->name);
     if(pil->next != NULL)
     {
	  printf(",");
	  emit_index_list(pil->next);
     }
}

// output a join condition node
void emit_join_condition(pjoin_condition pjc)
{
     if(pjc->con_type == 1)
     {
	  printf(" on ");
	  emit_expr(pjc->l);
     }
     else if(pjc->con_type == 2)
     {
	  printf(" using {");
	  emit_index_list((pindex_list)pjc->l);
	  printf(") ");
     }
}

// output a join table node base form,
// for the specific form to call it.
void emit_join_table_base(pjoin_table pjt, const char* app)
{
     if(pjt->table_ref->node_type == 'f')
     {
	  emit_table_factor((ptable_factor)pjt->table_ref);
     }
     else if(pjt->table_ref->node_type == 't')
     {
	  emit_join_table((pjoin_table)pjt->table_ref);
     }
     printf(" %s ",app);
     
     if(pjt->table_fct != NULL)
     {
	  emit_table_factor((ptable_factor)pjt->table_fct);
     }
     
     if(pjt->join_cond != NULL)
     {
	  emit_join_condition((pjoin_condition)pjt->join_cond);
     }
}

// output a join table node
void emit_join_table(pjoin_table pjt)
{
     switch(pjt->join_type)
     {
     case 64:
     {
	  // join	  
	  emit_join_table_base(pjt,"join");
      	  break;
     }
     case 65:
     {
	  // inner join
	  emit_join_table_base(pjt,"inner join");	  	  
	  break;
     }
     case 66:
     {
	  // cross join
	  emit_join_table_base(pjt,"cross join");
	  break;
     }
     case 128:
     {
	  // straight join
	  emit_join_table_base(pjt,"straight join");
	  break;
     }
     case 193:
     {
	  // left join
	  emit_join_table_base(pjt,"left join");
	  break;
     }
     case 197:
     {
	  // left outer join
	  emit_join_table_base(pjt,"left outer join");	  
	  break;
     }
     case 194:
     {
	  // right join
	  emit_join_table_base(pjt,"right join");
	  break;
     }
     case 198:
     {
	  // right outer join
	  emit_join_table_base(pjt,"right outer join");
	  break;
     }
     case 257:
     {
	  // natural left join
	  emit_join_table_base(pjt,"natural left join");	  
	  break;
     }
     case 261:
     {
	  //natural left outer join
	  emit_join_table_base(pjt,"natural left outer join");
	  break;
     }
     case 258:
     {
	  // natural right join
	  emit_join_table_base(pjt,"natural right join");
	  break;
     }
     case 262:
     {
	  // natural right outer join
	  emit_join_table_base(pjt,"natural right outer join");
	  break;
     }
     case 256:
     {
	  // natural join
	  emit_join_table_base(pjt,"natural join");
	  break;
     }
     }
}

// output a table reference list
void emit_table_references(ptable_references ptr)
{
     if(ptr->ref_type == 1)
     {
	  // emit table_factor
	  emit_table_factor((ptable_factor)ptr->table_ref);
     }
     else
     {
	  // emit join_table
	  emit_join_table((pjoin_table)ptr->table_ref);
     }

     if(ptr->next != NULL)
     {
	  printf(",");
	  emit_table_references(ptr->next);
     }
     
}

// output a groupby list
void emit_groupby_list(pgroupby_list pgpb_l)
{
     emit_expr(pgpb_l->expr);
     switch(pgpb_l->opt_asc_desc)
     {
     case 0:
	  break;
     case 1:
	  printf(" desc ");
	  break;
     default:
	  break;
     }
     
     if(pgpb_l->next != NULL)
     {
	  printf(",");
	  emit_groupby_list(pgpb_l->next);  
     }
}

// output a select statement
void emit_select_stmt(pselect_stmt stmt)
{
     if(stmt == NULL)
	  return;
     printf("select ");
     switch(stmt->sel_type)
     {
     case 1:
	  printf(" all ");
	  break;
     case 2:
	  printf(" distinct ");
	  break;
     case 3:
	  printf(" distinct all ");
	  break;
     case 4:
	  printf(" distinctrow ");
	  break;
     case 5:
	  printf(" distinctrow all ");
	  break;
     case 6:
	  printf(" distinct distictrow ");
	  break;
     case 7:
	  printf(" distinct distinctrow all ");
	  break;
     default:
	  break;
	  
     }
     
     emit_select_expr_list(stmt->sel_expr_list);
     if(stmt->table_refs != NULL)
     {
	  printf(" from ");
	  emit_table_references(stmt->table_refs);
     }

     if(stmt->opt_where_expr != NULL)
     {
	  printf(" where ");
	  emit_expr(stmt->opt_where_expr);
     }
     if(stmt->gpb_list != NULL)
     {
	  printf(" group by ");
	  emit_groupby_list(stmt->gpb_list);
     }
     if(stmt->opt_having_expr != NULL)
     {
	  printf(" having ");
	  emit_expr(stmt->opt_having_expr);
     }
     
     if(stmt->odb_list != NULL)
     {
	  printf(" order by ");
	  emit_groupby_list(stmt->odb_list);  
     }
}

// table node build according to the create schema
tablelist newtable(char* name)
{
     tablelist ntable = (tablelist)malloc(sizeof(table));
     ntable->name = strdup(name);
     ntable->keys = NULL;
     ntable->attrs = NULL;
     ntable->next = NULL;

     return ntable;
}

// attribute node build according to the create schema
attrlist newattr(char* name)
{
     attrlist pattr = (attrlist)malloc(sizeof(attr));

     pattr->name = strdup(name);
     pattr->next = NULL;

     return pattr;
}

// attribute list build according to the create schema
attrlist build_attrs(FILE* fp, int n)
{
     int i;
     char name[BUFSIZE];
     attrlist al_head,acur,p;

     al_head = newattr("");
     acur = al_head;

     memset(name,0,BUFSIZE);
     for(i = 0; i < n; i++)
     {
	  fscanf(fp,"%s",name);
	  p = newattr(name);
	  acur->next = p;
	  acur = p;
     }

     return al_head;
}

// build a table and its attribute list according to the schema
tablelist build_table(FILE* fp)
{
     tablelist ntable;
     int nk,na;
     char name[BUFSIZE];
     attrlist keys,attrs;

     memset(name,0,BUFSIZE);
     fscanf(fp,"%s",name);
     fscanf(fp,"%d %d",&nk,&na);

     keys = build_attrs(fp,nk);
     attrs = build_attrs(fp,na);
     ntable = newtable(name);
     ntable->keys = keys;
     ntable->attrs = attrs;

     return ntable;
}

// output the tables built according to the schema
void print_tables(tablelist head)
{
     tablelist p;
     attrlist pa;

     p = head->next;
     while(p != NULL)
     {
	  printf("<t> ");
	  printf("%s\n",p->name);
	  pa = p->keys->next;
	  printf("keys:\n");
	  while(pa != NULL)
	  {
	       printf("%s\n",pa->name);
	       pa = pa->next;
	  }

	  pa = p->attrs->next;
	  printf("attrs:\n");
	  while(pa != NULL)
	  {
	       printf("%s\n",pa->name);
	       pa = pa->next;
	  }

	  printf("\n\n");
	  p = p->next;
     }
}

// build all the table with a list according to the schema
tablelist build_tables(const char* filename)
{
     int nt,i;
     FILE* fp = NULL;
     tablelist tl_head,tcur,p;
     
     fp = fopen(filename,"r");
     if(fp == NULL)
     {
	  fprintf(stderr,"can't open file %s\n",filename);
	  exit(1);
     }

     fscanf(fp,"%d",&nt);
     
     tl_head = newtable("");
     tcur = tl_head;
     
     for(i = 0; i < nt; i++)
     {
	  // building each table
	  p = build_table(fp);
	  tcur->next = p;
	  tcur = p;
     }
     
     if(fclose(fp) != 0)
     {
	  fprintf(stderr,"Error in closing file %s\n",filename);
     }

     return tl_head;
}

// free the attribute 
void free_attrs(attrlist head)
{
     attrlist pa = head;

     if(pa->next != NULL)
     {
	  free_attrs(pa->next);
     }

     free(pa->name);
     free(pa);
}

// free the table list
void free_tables(tablelist head)
{
     tablelist p;
     
     p = head;
     if(p->next != NULL)
     {
	  free_tables(p->next);
     }

     free(p->name);
     if(p->keys != NULL)
         free_attrs(p->keys);
     if(p->attrs != NULL)
         free_attrs(p->attrs);
     free(p);
}

// build a translation table from the table name to its alias name
aliaslist build_trans_table(ptable_references tb_refs)
{
     aliaslist tr_table = (aliaslist)malloc(sizeof(struct aliasnode));
     aliaslist cur,pt;
     ptable_references p = tb_refs;
     ptable_factor q;

     tr_table->name = strdup("");
     tr_table->alias = strdup("");
     tr_table->next = NULL;
     cur = tr_table;

     while(p != NULL)
     {
	  if(p->ref_type == 1)
	  {
	       q = (ptable_factor)(p->table_ref);
	       if(q->factor_type == 1 &&  q->s2 != NULL)
	       {
		    pt = (aliaslist)malloc(sizeof(struct aliasnode));
		    pt->next = NULL;
		    pt->name = strdup(q->s->s->name);
		    pt->alias = strdup(q->s2->s->name);

		    cur->next = pt;
		    cur = cur->next;
	       }
	  }

	  p  = p->next;
     }

     return tr_table;
}

// free the table name to alias name translation table
void free_trans_table(aliaslist al)
{
     aliaslist p = al;

     if(p->next != NULL)
     {
	  free_trans_table(p->next);
     }

     free(p->name);
     free(p->alias);
     free(p);
}

/*
 * translate alias-table-name --> table-name
 */
char* translate(char* alias)
{
     aliaslist p;
     p = trans_table->next;
     while(p != NULL)
     {
	  if(strcmp(alias,p->alias) == 0)
	       return p->name;
	  
	  p = p->next;
     }

     return alias;
}

/*
 * anti-translate table-name --> alias-table-name
 */
char* anti_translate(char* tbn)
{
     aliaslist p;
     p = trans_table->next;
     while(p != NULL)
     {
	  if(strcmp(tbn,p->name) == 0)
	       return p->alias;

	  p = p->next;
     }

     return tbn;
}

// check if the colname is the tbname is key attribute
int is_key(char* tbname,char* colname)
{
     tablelist p;
     attrlist pa;
     char* tbn = translate(tbname);

     p = all_tables->next;
     while(p != NULL)
     {
	  if(strcmp(tbn,p->name) == 0)
	  {
	       pa = p->keys->next;
	       while(pa != NULL)
	       {
		    if(strcmp(colname,pa->name) == 0)
		    {
			 return 1;
		    }
		    pa = pa->next;
	       }
	  }
	  
	  p = p->next;
     }

     return 0;
}

// get the key attribute of the table name
char* get_key(const char* tbn)
{
     tablelist p = all_tables->next;
     attrlist pk;
     
     while(p != NULL)
     {
	  if(strcmp(p->name,tbn) == 0)
	  {
	       pk = p->keys->next;
	       if(pk != NULL)
		    return pk->name;
	  }

	  p = p->next;
     }

     return NULL;
}

// classify the KJ, NKJ, SC nodes in the abstract syntax tree
void classify(past expr)
{
     switch(expr->node_type)
     {
     case 'A':
     {
	  signs[signs_len++] = 'a';
	  classify(expr->l);
	  classify(expr->r);
	  break;
     }
     case 'O':
     {
	  signs[signs_len++] = 'o';
	  classify(expr->l);
	  classify(expr->r);
	  break;
     }
     case '4':
     {
	  if(expr->l->node_type == 'D' && expr->r->node_type == 'D')
	  {
	       if(is_key(((psymref)expr->l->l)->s->name,((psymref)expr->l->r)->s->name) && is_key(((psymref)expr->r->l)->s->name,((psymref)expr->r->r)->s->name))
	       {
		    insert_kj_expr(expr);
	       }
	       else
	       {
		    insert_nkj_expr(expr);
	       }

	       signs[--signs_len] = '\0';
	  }
	  else
	  {
	       insert_sc_expr(expr);
	  }
	  break;
     }
     default:
     {
	  insert_sc_expr(expr);
     }
     }
}

/*
 * initialize the 3 expr queues.
 */
void init_expr_lists()
{
     kj_head = (exprlist)malloc(sizeof(struct exprlistnode));
     kj_head->expr = NULL;
     kj_head->next = NULL;
     kj_tail = kj_head;

     nkj_head = (exprlist)malloc(sizeof(struct exprlistnode));
     nkj_head->expr = NULL;
     nkj_head->next = NULL;
     nkj_tail = nkj_head;

     sc_head = (exprlist)malloc(sizeof(struct exprlistnode));
     sc_head->expr = NULL;
     sc_head->next = NULL;
     sc_tail = sc_head;

     memset(signs,0,BUFSIZE);
     signs_len = 0;
}

/*
 * free expr queue
 */
void free_expr_list(exprlist el)
{
     if(el->next != NULL)
	  free_expr_list(el->next);

     free(el);
}

// insert a expression item to the KJ expr list
void insert_kj_expr(past expr)
{
     exprlist cur = (exprlist)malloc(sizeof(struct exprlistnode));
     cur->expr = expr;
     cur->next = NULL;

     kj_tail->next = cur;
     kj_tail = cur;
}

// insert a expression item to the NKJ expr list
void insert_nkj_expr(past expr)
{
     exprlist cur = (exprlist)malloc(sizeof(struct exprlistnode));
     cur->expr = expr;
     cur->next = NULL;

     nkj_tail->next = cur;
     nkj_tail = cur;
}

// insert a expression item to the SC expr list
void insert_sc_expr(past expr)
{
     exprlist cur = (exprlist)malloc(sizeof(struct exprlistnode));
     cur->expr = expr;
     cur->next = NULL;

     sc_tail->next = cur;
     sc_tail = cur;
}

// output the KJ expr list
void emit_kj_exprs()
{
     exprlist p;

     printf("KJ:\n");
     p = kj_head->next;
     while(p != NULL)
     {
	  emit_expr(p->expr);
	  printf(" ");
	  p = p->next;

	  if(p != NULL)
	       printf(" and ");
     }
     printf("\n");
}

// output the NKJ expr list
void emit_nkj_exprs()
{
     exprlist p;
     
     printf("NKJ:\n");
     p = nkj_head->next;
     while(p != NULL)
     {
	  emit_expr(p->expr);
	  printf(" ");
	  p = p->next;

	  if(p != NULL)
	       printf(" and ");
     }
     printf("\n");

}

// output the SC expr list
void emit_sc_exprs()
{
     exprlist p;
     int i = 0;
     
     printf("SC:\n");
     p = sc_head->next;
     while(p != NULL)
     {
	  emit_expr(p->expr);

	  if(i < signs_len )
	  {
	       switch(signs[i])
	       {
	       case 'a':
		    printf(" and ");
		    break;
	       case 'o':
		    printf(" or ");
		    break;
	       default:
		    break;
	       }
	  }
	  
	  p = p->next;
	  i++;
     }
     
     printf("\n");
}

// output the inversed SC  expr
void emit_nsc_expr(past p)
{
     switch(p->node_type)
     {
     case '1':
     {
	  // for <
	  emit_expr(p->l);
	  printf(" >= ");
	  emit_expr(p->r);
	  break;
     }
     case '2':
     {
	  // for >
	  emit_expr(p->l);
	  printf(" <= ");
	  emit_expr(p->r);
	  break;
     }
     case '3':
     {
	  // for !=
	  emit_expr(p->l);
	  printf(" = ");
	  emit_expr(p->r);
	  break;
     }
     case '4':
     {
	  // for =
	  emit_expr(p->l);
	  printf(" != ");
	  emit_expr(p->r);
	  break;
     }
     case '5':
     {
	  // for <=
	  emit_expr(p->l);
	  printf(" > ");
	  emit_expr(p->r);
	  break;
     }
     case '6':
     {
	  // for >=
	  emit_expr(p->l);
	  printf(" < ");
	  emit_expr(p->r);
	  break;
     }
     case 'T':
     {
	  emit_expr(p->l);
	  break;
     }
     case 'W':
     {
	  emit_expr(p->l);
	  printf(" < ");
	  emit_expr(p->r);
	  printf(" and ");
	  emit_expr(p->l);
	  printf(" > ");
	  emit_expr(p->rr);
	  break;
     }
     case 'U':  // for null
     case 'B':  // for bool
     case 'E':  // for exists
     case 'K':  // for like
     case 'Q':  // for in
     {
	  past temp = newast('T',p,NULL,NULL);
	  emit_expr(temp);
	  free(temp);
	  break;
     }
     default:
     {
	  emit_expr(p);
	  break;
     }
     }
}

// output the inversed SC expr list
void emit_nsc_exprs()
{
     //
     int i = 0;

     exprlist p = sc_head->next;
     while(p != NULL)
     {
	  emit_nsc_expr(p->expr);
	  if(i < signs_len )
	  {
	       switch(signs[i])
	       {
	       case 'a':
		    printf(" or ");
		    break;
	       case 'o':
		    printf(" and ");
		    break;
	       default:
		    break;
	       }
	  }
	  
	  p = p->next;
	  i++;
     }
}


/*
 * get a new and initialized join_graph_node
 */
pjoin_graph_node newjoin_graph_node(const char* src_t, const char* src_a, const char* dist_t, const char* dist_a)
{
     pjoin_graph_node pjn = (pjoin_graph_node)malloc(sizeof(struct join_graph_node));
     pjn->dist_t = strdup(dist_t);
     pjn->dist_a = strdup(dist_a);
     pjn->src_t = strdup(src_t);
     pjn->src_a = strdup(src_a);
     pjn->next = NULL;

     return pjn;
}

/*
 * get a new and initialized join_graph_nodelist node
 */
pjoin_graph_nodelist newjoin_graph_nodelist()
{
     pjoin_graph_nodelist pjnl = (pjoin_graph_nodelist)malloc(sizeof(struct join_graph_nodelist_node));
     pjnl->tb_name = NULL;
     pjnl->key_name = NULL;
     pjnl->in_degree = 0;
     pjnl->node = NULL;
     pjnl->next = NULL;

     return pjnl;
}

// build a new left outer join queue node and return its addr
loj_queue newloj_queue_node()
{
     loj_queue p = (loj_queue)malloc(sizeof(struct loj_queue_node));
     p->node = NULL;
     p->next = NULL;

     return p;
}

/*
 * searches whether a table entry has been inserted into the join_graph_nodelist,
 * if so, do nothing and return
 * else, insert an new entry in the nodelist.
 */
void insert_join_graph_nodelist(pjoin_graph_nodelist head,const char* tbn)
{
     char* keyn;
     pjoin_graph_nodelist f = head;
     pjoin_graph_nodelist p = head->next;

     while(p != NULL)
     {
	  if(strcmp(p->tb_name,tbn) == 0)
	       return;

	  f = p;
	  p = p->next;
     }

     p = newjoin_graph_nodelist();
     p->tb_name = strdup(tbn);
     keyn = get_key(tbn);
     p->key_name = keyn;

     f->next = p;
}

// insert into the join graph with src_t,src_a --> dist_t.dist_a join condition
void insert_join_graph_node(pjoin_graph_nodelist jghead,const char* src_t,const char* src_a, const char* dist_t, const char* dist_a)
{
     pjoin_graph_nodelist p = jghead->next;
     pjoin_graph_node f,q;
     while(p != NULL)
     {
	  if(strcmp(p->tb_name,src_t) == 0)
	  {
	       q = p->node;
	       if(q == NULL)
	       {
		    q = newjoin_graph_node(src_t,src_a,dist_t,dist_a);
		    p->node = q;
	       }
	       else
	       {
		    do{
			 f = q;
			 q = q->next;
		    }while(q != NULL);

		    q = newjoin_graph_node(src_t,src_a,dist_t,dist_a);
		    f->next = q;
	       }

	       break;
	  }
	  
	  p = p->next;
     }
}

// increase the table name's references number by 1
void increase_indegree(pjoin_graph_nodelist jghead,const char* tbn)
{
     pjoin_graph_nodelist p = jghead->next;
     while(p != NULL)
     {
	  if(strcmp(p->tb_name,tbn) == 0)
	  {
	       p->in_degree++;
	       break;
	  }
	  
	  p = p->next;
     }
}

// insert into the join graph with relation of nonkey to key join condition
void insert_graph_item(pjoin_graph_nodelist jghead,past key, past nonkey)
{
     char* dist_t = ((psymref)key->l)->s->name;
     char* dist_a = ((psymref)key->r)->s->name;
     char* src_t = ((psymref)nonkey->l)->s->name;
     char* src_a = ((psymref)nonkey->r)->s->name;

     dist_t = translate(dist_t);
     src_t = translate(src_t);

     insert_join_graph_nodelist(jghead,src_t);
     insert_join_graph_nodelist(jghead,dist_t);

     insert_join_graph_node(jghead,src_t,src_a,dist_t,dist_a);
     increase_indegree(jghead,dist_t);
}

/*
 * build up the join graph
 */
pjoin_graph_nodelist build_join_graph()
{
     //
     past key, nonkey;
     pjoin_graph_nodelist jghead = newjoin_graph_nodelist();
     exprlist ep = nkj_head->next;
     past p;

     while(ep != NULL)
     {
	  p = ep->expr;
	  if(is_key(((psymref)p->l->l)->s->name,((psymref)p->l->r)->s->name))
	  {
	       key = p->l;
	       nonkey = p->r;
	  }
	  else
	  {
	       key = p->r;
	       nonkey = p->l;
	  }

	  insert_graph_item(jghead,key,nonkey);
	  ep = ep->next;
     }

     return jghead;
}

// free a join graph reference node
void free_join_graph_nodes(pjoin_graph_node p)
{
     if(p->next != NULL)
     {
	  free(p->next);
     }

     free(p->src_t);
     free(p->src_a);
     free(p->dist_t);
     free(p->dist_a);
     free(p);
}

// free the join graph
void free_join_graph()
{
     pjoin_graph_nodelist f = jg_head;
     pjoin_graph_nodelist p = jg_head->next;
     pjoin_graph_node q;
     
     free(f);
     while(p != NULL)
     {
	  // not done!
	  q = p->node;
	  if(q != NULL)
	  {
	       free_join_graph_nodes(q);
	  }
	  
	  f = p;
	  p = p->next;

	  free(f->tb_name);
	  free(f->key_name);
	  free(f);
     }
}

// output the join graph
void emit_join_graph()
{
     pjoin_graph_nodelist p = jg_head->next;
     pjoin_graph_node q;
     
     while(p != NULL)
     {
	  printf("%s|%s|%d ",p->tb_name,p->key_name,p->in_degree);
	  q = p->node;
	  if(q != NULL)
	  {
	       printf("=> ");
	       do{
		    printf("(%s|%s->%s|%s)",q->src_t,q->src_a,q->dist_t,q->dist_a);
		    printf(" --> ");
		    q = q->next;
	       }while(q != NULL);
	       printf("nil\n");
	  }
	  else
	       printf("\n");
	  
	  p = p->next;
     }
}

/*
 * check the join graph satisfy our defination
 * it must be a tree graph,means the ) <= in_degree <= 1 
 * there is only 1 node with in_degree 0, others are all with in_degree 1
 */
int check_join_graph()
{
     int nz = 0; // the number of nodes with in_degree 0
     int no = 0; // the number of nodes with in_degree over 1

     pjoin_graph_nodelist p = jg_head->next;

     while(p != NULL)
     {
	  if(p->in_degree == 0)
	       nz++;
	  else if(p->in_degree > 1)
	       no++;

	  p = p->next;
     }

     if((nz != 1) || (no > 0))
	  return 0;

     return 1;
}

// get the root table of the join graph
pjoin_graph_nodelist get_join_graph_root()
{
     pjoin_graph_nodelist p = jg_head->next;
     while(p != NULL)
     {
	  if(p->in_degree == 0)
	       return p;
	  
	  p = p->next;
     }

     return NULL;
}

// get the join graph reference list with table name dist_t
pjoin_graph_node get_join_graph_nodes(const char* dist_t)
{
     pjoin_graph_nodelist p = jg_head->next;
     while(p != NULL)
     {
	  if(strcmp(p->tb_name,dist_t) == 0)
	  {
	       return p->node;
	  }

	  p = p->next;
     }

     return NULL;
}

// check if the root table's key attribute is in an expression
int is_key_in_expr(past expr,const char* key)
{
     switch(expr->node_type)
     {
     case 'N':
	  return strcmp(((psymref)expr)->s->name,key) == 0;
     case 'D':
	  return strcmp(((psymref)expr->r)->s->name,key) == 0;
     case 'M':
	  return is_key_in_expr(expr->l,key);
     case '+':
     case '-':
     case '*':
     case '/':
     case '%':
	  return is_key_in_expr(expr->l,key) || is_key_in_expr(expr->r,key);
     default:
	  return 0;
     }
}

// check if the root table's key attribute is in the select expression list
int is_key_in(pselect_expr_list sel_l,const char* key)
{
     int is = 0;
     pselect_expr_list p;

     if(sel_l == NULL)
	  return 0;

     if(is_key_in_expr(sel_l->expr,key))
	  return 1;
     
     p = sel_l->next;
     while(p != NULL)
     {
	  if(is_key_in(p,key))
	       return 1;
	  
	  p = p->next;
     }

     return 0;
}

// output the left outer join queue.
void emit_loj_queue(pjoin_graph_nodelist root)
{
     loj_queue head;
     loj_queue tail;
     loj_queue tmpq;
     loj_queue tmp_loc;
     loj_queue tmp_free;
     char* aliasns;  // alias name of src table
     char* aliasnd;  // alias name or dist table
     pjoin_graph_nodelist pnl;
     pjoin_graph_node pn;

     printf("      ");
     head = newloj_queue_node();
     tail = head;

     pn = root->node;
     while(pn != NULL)
     {
	  tmp_loc = newloj_queue_node();
	  tmp_loc->node = pn;
	  tail->next = tmp_loc;
	  tail = tmp_loc;
	  
	  pn = pn->next;
     }

     while(head != tail)
     {
	  tmpq = head->next;
	  aliasns = anti_translate(tmpq->node->src_t);
	  aliasnd = anti_translate(tmpq->node->dist_t);
	  if(aliasns == tmpq->node->src_t)
	  {
	       // no alias table-name
	       printf("left outer join %s on %s.%s=%s.%s",aliasnd,aliasns,tmpq->node->src_a,aliasnd,tmpq->node->dist_a);
	  }
	  else
	  {
	       printf("left outer join %s %s on %s.%s=%s.%s",tmpq->node->dist_t,aliasnd,aliasns,tmpq->node->src_a,aliasnd,tmpq->node->dist_a);
	  }

	  pn = get_join_graph_nodes(tmpq->node->dist_t);
	  while(pn != NULL)
	  {
	       tmp_loc = newloj_queue_node();
	       tmp_loc->node = pn;
	       tail->next = tmp_loc;
	       tail = tmp_loc;
	       
	       pn = pn->next;
	  }

	  tmp_free = head;
	  head = tmpq;
	  free(tmp_free);
     }

     free(head);
     printf("\n");
}

// emit the rewriting select options according to the original select options
void emit_rewriting_select_opts(int sel_type)
{
     switch(sel_type)
     {
     case 0:
     case 2:
	  printf(" distinct ");
	  break;
     case 1:
     case 3:
	  printf(" distinct all ");
	  break;
     case 4:
     case 6:
	  printf(" distinct distinctrow ");
	  break;
     case 5:
     case 7:
	  printf(" distinct distinctrow all ");
	  break;
     }
}

// output the select expression list without the aggregation node
void emit_select_expr_list_without_aggr(pselect_expr_list psel_l)
{
     pselect_expr_list p;
     int first = 1;
     
     if(psel_l == NULL)
     {
	  printf(" * ");
	  return;
     }

     p = psel_l->next;
     while(p != NULL)
     {
	  if(p->expr->node_type != 'C')
	  {
	       if(!first)
		    printf(",");
	       emit_expr(p->expr);

	       if(p->as_alias != NULL)
               {
	           printf(" as ");
	           printf(" %s ", p->as_alias->s->name);
               }

	       first = 0;
	  }

	  p = p->next;
     }
}

// output the UnFilteredCandidates expression of aggregation rewriting.
void emit_unfiltered_aggr(pselect_expr_list psel_l)
{
     pselect_expr_list p;
     pufncall pc;
     int count = 1;
     int first = 1;
     
     if(psel_l == NULL)
	  return;

     p = psel_l;
     while(p != NULL)
     {
	  if(p->expr->node_type == 'C')
	  {
	       if(!first)
		    printf(",\n");
	       pc = (pufncall)(p->expr);
	       printf("      min(");
	       emit_expr(pc->l);
	       printf(") as minAgg%d,\n",count);
	       printf("      max(");
	       emit_expr(pc->l);
	       printf(") as maxAgg%d\n",count);

	       count++;
	  }
	  
	  p = p->next;
     }
}

// output the FilteredCandidates of the aggregation rewriting.
void emit_filtered_aggr(pselect_expr_list psel_l)
{
     pselect_expr_list p;
     pufncall pc;
     int count = 1;
     int first = 1;
     
     if(psel_l == NULL)
	  return;

     p = psel_l;
     while(p != NULL)
     {
	  if(p->expr->node_type == 'C')
	  {
	       if(!first)
		    printf(",\n");
	       pc = (pufncall)(p->expr);
	       printf("      case when min(");
	       emit_expr(pc->l);
	       printf(") > 0 then 0 else min(");
	       emit_expr(pc->l);
	       printf(") end as minAgg%d,\n",count);
	       printf("      case when max(");
	       emit_expr(pc->l);
	       printf(") > 0 then max(");
	       emit_expr(pc->l);
	       printf(") else 0 end as maxAgg%d",count);

	       count++;
	  }
	  
	  p = p->next;
     }
}

// output the UnionCandidates expression of aggregation rewriting.
void emit_union_aggr(pselect_expr_list psel_l)
{
     pselect_expr_list p;
     pufncall pc;
     int count = 1;
     int first = 1;
     
     if(psel_l == NULL)
	  return;

     p = psel_l;
     while(p != NULL)
     {
	  if(p->expr->node_type == 'C')
	  {
	       if(!first)
		    printf(",\n");
	       pc = (pufncall)(p->expr);
	       printf(" %s(minAgg%d),%s(maxAgg%d)",pc->s->s->name,count,pc->s->s->name,count);

	       count++;
	  }
	  
	  p = p->next;
     }
}

// output the rewrite join algorithm
void rewrite_join(pselect_stmt stmt)
{
     pjoin_graph_nodelist p;
     exprlist epl;
     char* aliasn;
     pjoin_graph_nodelist root = get_join_graph_root();
     printf("with Candidates as( \n");
     printf("    select ");
     emit_rewriting_select_opts(stmt->sel_type);
     
     if(!is_key_in(stmt->sel_expr_list,root->key_name)) 
	  printf("%s.%s,",anti_translate(root->tb_name),root->key_name);
     emit_select_expr_list(stmt->sel_expr_list);
     printf("\n");
     printf("    from ");
     emit_table_references(stmt->table_refs);
     printf("\n");
     printf("    where ");
     emit_expr(stmt->opt_where_expr);
     printf(" ),\n");
     
     printf("Filter as( \n");
     printf("  select %s.%s\n",anti_translate(root->tb_name),root->key_name);
     printf("  from Candidates Cand\n");

     aliasn = anti_translate(root->tb_name);
     if(aliasn == root->tb_name)
     {
	  printf("      join %s on Cand.%s=%s.%s\n",root->tb_name,root->key_name,root->tb_name,root->key_name);
     }
     else
     {
	  printf("      join %s %s on Cand.%s=%s.%s\n",root->tb_name,aliasn,root->key_name,aliasn,root->key_name);
     }

     
     emit_loj_queue(root);
          
     printf("  where ");
     emit_nsc_exprs();
     p = jg_head->next;
     while(p != NULL)
     {
	  if(p->in_degree != 0)
	  {
	       printf(" or ");
	       printf("%s.%s is null ",anti_translate(p->tb_name),p->key_name);
	  }
	  p = p->next;
     }
     
     //printf(" or (Rx is null or ...)");
     epl = kj_head->next;
     if(epl != NULL)
     {
	  printf(" and ");
	  emit_kj_exprs();
     }
     //printf(" and KJ");
     printf("\n");
     
     printf("  union all\n");
     printf("    select %s\n",root->key_name);
     printf("    from Candidates C\n");
     printf("    group by %s\n",root->key_name);
     printf("    having count(*)>1");
     printf(")\n");
     
     printf("select ");
     emit_rewriting_select_opts(stmt->sel_type);
     only_attr_cmd = 1;
     emit_select_expr_list(stmt->sel_expr_list);
     only_attr_cmd = 0;
     printf("\n");
     printf("from Candidates C\n");
     printf("where not exists( select * from Filter F where C.%s = F.%s)\n",root->key_name,root->key_name);
     if(stmt->odb_list != NULL)
     {
	  printf(" order by ");
	  emit_groupby_list(stmt->odb_list);  
     }
}

// output the rewrite aggregation algorithm
void rewrite_aggr(pselect_stmt stmt)
{
     pjoin_graph_nodelist p;
     exprlist epl;
     char* aliasn;
     pjoin_graph_nodelist root = get_join_graph_root();
     
     printf("with Candidates as(\n");
     printf("    select ");
     if(!is_key_in(stmt->sel_expr_list,root->key_name)) 
	  printf("%s,",root->key_name);
     emit_select_expr_list_without_aggr(stmt->sel_expr_list);
     printf("\n    from ");
     emit_table_references(stmt->table_refs);
     printf("\n    where ");
     emit_expr(stmt->opt_where_expr);
     printf("\n),\n");
     printf("Filter as(\n");
     printf("    select %s\n",root->key_name);
     printf("    from ");
     emit_table_references(stmt->table_refs);
     printf("\n    where ");
     emit_nsc_exprs();
     printf("\n),\n");

     printf("QGCons as(\n");
     printf("    select ");
     emit_groupby_list(stmt->gpb_list);
     printf("\n    from Candidates c\n");
     printf("    where not exists( select * from Filter f where c.%s = f.%s)\n",root->key_name,root->key_name);
     printf("    group by ");
     emit_groupby_list(stmt->gpb_list);
     if(stmt->odb_list != NULL)
     {
	  printf(" order by ");
	  emit_groupby_list(stmt->odb_list);  
     }
     
     printf("\n),\n");

     printf("UnFilteredCandidates as(\n");
     printf("    select ");
     if(!is_key_in(stmt->sel_expr_list,root->key_name)) 
	  printf("%s,",root->key_name);
     emit_select_expr_list_without_aggr(stmt->sel_expr_list);
     printf(",\n");
     emit_unfiltered_aggr(stmt->sel_expr_list);
     printf("    from ");
     emit_table_references(stmt->table_refs);
     printf("\n    where ");
     emit_expr(stmt->opt_where_expr);
     printf("\n      and not exists (select * from Filter f where %s.%s=f.%s)\n",root->tb_name,root->key_name,root->key_name);
     printf("    group by %s,",root->key_name);
     emit_groupby_list(stmt->gpb_list);
     printf("\n),\n");

     printf("FilteredCandidates as(\n");
     printf("    select ");
     if(!is_key_in(stmt->sel_expr_list,root->key_name)) 
	  printf("%s,",root->key_name);
     emit_select_expr_list_without_aggr(stmt->sel_expr_list);
     printf(",\n");
     emit_filtered_aggr(stmt->sel_expr_list);
     printf("\n    from ");
     emit_table_references(stmt->table_refs);
     printf("\n    where ");
     emit_expr(stmt->opt_where_expr);
     printf("\n      and exists (select * from Filter f where %s.%s=f.%s)",root->tb_name,root->key_name,root->key_name);
     printf("\n      and exists (select * from QGCons where QGCons.");
     emit_groupby_list(stmt->gpb_list);
     printf("=%s.",root->tb_name);
     emit_groupby_list(stmt->gpb_list);
     printf(")");
     printf("\n    group by %s,",root->key_name);
     emit_groupby_list(stmt->gpb_list);
     
     printf("\n),\n");

     printf("UnionCandidates as(\n");
     printf("    select * from UnFilteredCandidates\n");
     printf("    union all\n");
     printf("    select * from FilteredCandidates\n");
     printf(")\n");
     printf("select ");
     emit_select_expr_list_without_aggr(stmt->sel_expr_list);
     printf(",");
     emit_union_aggr(stmt->sel_expr_list);
     printf("\n");
     printf("from UnionCandidates\n");
     printf("group by ");
     emit_groupby_list(stmt->gpb_list);
     printf("\n");
}

// set up the environment of the rewrite join algorithm
// then clean it.
void on_rewrite_join(past stmt)
{
     init(stmt);

     //emit_join_graph();
     if(! check_join_graph())
     {
	  semantic_error("error: not a tree join graph!");
	  clear(stmt);
	  exit(1);
     }

     rewrite_join((pselect_stmt)stmt);

     clear(stmt);
}

// set up the environment of the rewrite aggregation algorithm
// then clean it.
void on_rewrite_aggr(past stmt)
{
     init(stmt);

     if(! check_join_graph())
     {
	  semantic_error("error: not a tree join graph!");
	  clear(stmt);
	  exit(1);
     }
     
     // to-do list...
     rewrite_aggr((pselect_stmt)stmt);
     clear(stmt);
}

// init the rewriting envrionment
void init(past stmt)
{
     pjoin_graph_nodelist p;
     ptable_factor tb_fct;
     all_tables = build_tables(schema_fname);
     init_expr_lists();

     trans_table = build_trans_table(((pselect_stmt)stmt)->table_refs);
     classify(((pselect_stmt)stmt)->opt_where_expr);
     jg_head = build_join_graph();
     if(jg_head->next == NULL)
     {
	  tb_fct = (ptable_factor)(((pselect_stmt)stmt)->table_refs->table_ref);
	  p = newjoin_graph_nodelist();
	  p->tb_name = strdup(tb_fct->s->s->name);
	  p->key_name = get_key(p->tb_name);
	  p->in_degree = 0;
	  jg_head->next = p;
     }
}

// clear the rewriting environment
void clear(past stmt)
{
     free_join_graph(jg_head);
     free_expr_list(kj_head);
     free_expr_list(nkj_head);
     free_expr_list(sc_head);

     free_tables(all_tables);
     free_trans_table(trans_table);
     free_ast(stmt);
     rewrite_kind = 0;
}

// output the semantic error
void semantic_error(const char* s, ...)
{
     va_list ap;
     va_start(ap,s);

     vfprintf(stderr,s,ap);
     fprintf(stderr,"\n");
}

// output the parser error
void yyerror(const char *s, ...)
{
  va_list ap;
  va_start(ap, s);

  fprintf(stderr, "%d: error: ", yylineno);
  vfprintf(stderr, s, ap);
  fprintf(stderr, "\n");
}

// output something.
void emit(const char *s, ...)
{
  va_list ap;
  va_start(ap, s);

  printf("rpn: ");
  vfprintf(stdout, s, ap);
  printf("\n");
}

