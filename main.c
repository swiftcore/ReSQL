/*
 * resql compiler main entry
 */
#include "resql.h"

int main(int ac, char** av)
{
     // set the output of select_expr_list to be of all contents
     only_attr_cmd = 0;
     // set the rewrite kind to rewrite join sql
     rewrite_kind = 0;
     // give the schema file name
     schema_fname = "schema.txt";
     // parse source sql file and try to rewrite it
     sparse(ac,av);

     return 0;
}
