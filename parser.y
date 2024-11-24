
%{
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include "cgen.h"
  
  #define MAX_COMP_FUNCS 100

  extern int yylex(void);
  extern int line_num;
  FILE *fptr; //file pointer for the generated c file
  char* comp_funcs[MAX_COMP_FUNCS]; //array to hold all member functions for the composite types in string format 
  char* conn = NULL; //string to hold all composite type declarations
  int comp,arr = 0; //flags to keep track of what composite type member variables/functions need to be declared 
  char* parent = NULL; //string to keep track of what function calls need a self argument passed
  int func_index=0; //index to keep track of how many functions have been declared in a composite type

  //Function to replace a substring with a given constant string used for array comprehension
  char *str_replace(char *orig, char *old, char *new_str) {
    char *result; // the return string
    char *ins;    // the next insert point
    char *tmp;    // varies
    int old_len;  // length of the string to be replaced 
    int new_len; // length of wthe new sub-string
    int len_front; // distance between two instances of the last sub-string
    int cnt;    // number of replacements

    // sanity checks and initialization
    if (!orig || !old || !new_str)
        return NULL;
    old_len = strlen(old);
    new_len = strlen(new_str);
    if (old_len == 0 || new_len == 0)
        return NULL;

    // count the number of replacements needed
    ins = orig;
    for (cnt = 0; (tmp = strstr(ins, old)); ++cnt) {
        ins = tmp + old_len;
    }

    tmp = result = malloc(strlen(orig) + (new_len - old_len) * cnt + 1);

    if (!result)
        return NULL;

    //    tmp points to the end of the result string
    //    ins points to the next occurrence of old in orig
    //    orig points to the remainder of orig after "end of old"
    while (cnt--) {
        ins = strstr(orig, old);
        len_front = ins - orig;
        tmp = strncpy(tmp, orig, len_front) + len_front;
        tmp = strcpy(tmp, new_str) + new_len;
        orig += len_front + old_len; // move to next "end of old"
    }
    strcpy(tmp, orig);
    return result;
}
   
%}

%define parse.error verbose

%union
{
  char* str;
}


%token <str> TK_STRING
%token <str> TK_IDENT 
%token <str> TK_INT 
%token <str> TK_REAL 

%token <str> KW_TRUE 
%token <str> KW_FALSE 

%token KW_IF   
%token KW_ELSE 
%token TK_AND 
%token TK_OR 
%token TK_NOT 
%token TK_MOD 
%token TK_POWER 
%token TK_COMP_GR 
%token TK_COMP_LESS 
%token TK_COMP 
%token TK_COMP_NEQ 
%token TK_COMP_LEQ 
%token TK_COMP_GEQ 
%token TK_ASSGN_IN 
%token TK_ASSGN_DE 
%token TK_ASSGN_MU 
%token TK_ASSGN_DIV 
%token TK_ASSGN_MOD 
%token TK_ARROW
%token TK_ARRAY_CR
%token TK_MEMBER

%token KW_INT 
%token KW_SCA 
%token KW_STR 
%token KW_BOOL 

%token KW_CONST 
%token KW_ENDIF 
%token KW_FOR 
%token KW_IN 
%token KW_ENDFOR 
%token KW_WHILE 
%token KW_ENDWHILE 
%token KW_BREAK 
%token KW_CONT 
%token KW_COMP 
%token KW_ENDCOMP 
%token KW_OF 
%token KW_DEF 
%token KW_ENDDEF 
%token KW_MAIN 
%token KW_RET 


%start program

%type <str> expr mult_identifiers identifiers comp_identifiers ident
%type <str> var_dec const_dec arg_dec func_dec mult_var_dec mult_func_dec mult_const_dec single_arg_dec   
%type <str> array_idx array_type
%type <str>  operations assignment func_call ret_statement comprehension
%type <str> body args mult_args comp_body comp_func_dec
%type <str> data_type composite
%type <str> for_cmd if_cmd while_cmd
%type <str> main_func global_space 
%type <str>  comp_arg_dec comp_var_dec mult_comp

%left TK_OR
%left TK_AND
%right TK_NOT '#'
%left TK_COMP_GEQ TK_COMP_GR TK_COMP_LEQ TK_COMP_LESS TK_COMP_NEQ TK_COMP
%left '+' '-'
%left '*' '/'
%left TK_MOD
%right TK_POWER

%%

program:
global_space {fptr = fopen("interpreted.c","w");fprintf(fptr,"%s\n%s",c_prologue,$1);}
;

global_space:
mult_comp mult_const_dec mult_var_dec mult_func_dec main_func {$$ = template("%s\n%s\n%s\n%s\n%s\n",$1,$2,$3,$4,$5);}
| mult_comp mult_const_dec mult_var_dec main_func  {$$ = template("%s\n%s\n%s\n%s\n",$1,$2,$3,$4);}
| mult_comp mult_var_dec main_func           {$$ = template("%s\n%s\n%s\n",$1,$2,$3);}
| mult_comp mult_const_dec main_func           {$$ = template("%s\n%s\n%s\n",$1,$2,$3);}
| mult_comp mult_const_dec mult_func_dec main_func  {$$ = template("%s\n%s\n%s\n%s\n",$1,$2,$3,$4);}
| mult_comp mult_func_dec  main_func             {$$ = template("%s\n%s\n%s\n",$1,$2,$3);}
| mult_comp mult_var_dec mult_func_dec main_func  {$$ = template("%s\n%s\n%s\n%s\n",$1,$2,$3,$4);}
| mult_comp main_func                             {$$ = template("%s\n%s\n",$1,$2);}
| mult_const_dec mult_var_dec mult_func_dec main_func {$$ = template("%s\n%s\n%s\n%s\n",$1,$2,$3,$4);}
|  mult_const_dec mult_var_dec main_func  {$$ = template("%s\n%s\n%s\n",$1,$2,$3);}
|  mult_var_dec main_func           {$$ = template("%s\n%s\n",$1,$2);}
|  mult_const_dec main_func           {$$ = template("%s\n%s\n",$1,$2);}
|  mult_const_dec mult_func_dec main_func  {$$ = template("%s\n%s\n%s\n",$1,$2,$3);}
| mult_func_dec  main_func             {$$ = template("%s\n%s\n",$1,$2);}
| mult_var_dec mult_func_dec main_func  {$$ = template("%s\n%s\n%s\n",$1,$2,$3);}
| main_func                             {$$ = template("%s\n",$1);}
;

main_func:  KW_DEF KW_MAIN '(' ')' ':' body KW_ENDDEF ';' {$$ = template("void main(){\t%s\n}\n",$6);}
;

mult_comp:
  mult_comp composite ';' {$$ = template("%s\n%s\n",$1,$2);}
| composite    ';'          {$$ = template("%s\n",$1);} 
;

mult_func_dec:
    mult_func_dec func_dec ';' {$$ = template("%s\n%s\n",$1,$2);}
|   func_dec     ';'          {$$ = template("%s\n",$1);} 
;

func_dec:
KW_DEF TK_IDENT '(' arg_dec ')'TK_ARROW data_type ':' body KW_ENDDEF {$$ = template("%s %s(%s){%s};",$7,$2,$4,$9);}
| KW_DEF TK_IDENT '(' arg_dec ')' ':' body KW_ENDDEF {$$ = template("void %s(%s){%s};",$2,$4,$7);}
;

composite:
KW_COMP TK_IDENT ':' comp_body KW_ENDCOMP { char* total; //The final composite type declaration
                                               total = template("#define SELF struct %s *self\ntypedef struct %s{%s} %s;\n\n",$2,$2,$4,$2);
                                               for(int i=0;i<func_index;i++){
                                                  total = template("%s\n%s\n",total,comp_funcs[i]);//add each function with its body after the struct declartion
                                                  free(comp_funcs[i]);//free each string used
                                               }
                                               func_index = 0; // reset the function index after each use
                                               total = template("%s\nconst %s ctor_%s = {%s};",total,$2,$2,conn); //connect function declarations with definitions
                                               conn = NULL; 
                                               total = template("%s\n#undef SELF\n",total);
                                               $$ = total;
}
;

comp_identifiers:
'#' ident {$$ = $2;}
| comp_identifiers ',' '#' ident {$$ = template("%s , %s",$1,$4);}
;

comp_var_dec:   
comp_identifiers ':' data_type  {   if(comp == 1){ 
                                      if(conn != NULL)
                                        conn = template("%s, .%s=ctor_%s",conn,$1,$3);
                                      else
                                        conn = template(".%s=ctor_%s",$1,$3);//solution for checking if this the first assignment 
                                      comp = 0;
                                    }
                                    $$ = template("%s %s",$3,$1);}
;

comp_body:
%empty   {$$ = "";}
| comp_body comp_var_dec ';' {$$ = template("%s\n%s;\n",$1,$2);}
| comp_body comp_func_dec ';' {$$ = template("%s\n%s;\n",$1,$2);}
;

comp_func_dec:
KW_DEF TK_IDENT '(' comp_arg_dec ')'TK_ARROW data_type ':' body KW_ENDDEF {comp_funcs[func_index] = template("%s %s(SELF%s){\n%s\n}\n",$7,$2,$4,$9); //Add the function definition to the array in order to place under the struct declaration
                                                                          if(conn != NULL) //same as before
                                                                            conn = template("%s, .%s=%s",conn,$2,$2);
                                                                          else
                                                                            conn = template(".%s=%s",$2,$2);
                                                                          func_index++;
                                                                          $$ = template("%s (*%s)(SELF %s)",$7,$2,$4);
} 
| KW_DEF TK_IDENT '(' comp_arg_dec ')' ':' body KW_ENDDEF {comp_funcs[func_index] = template("void %s(SELF%s){\n%s\n}\n",$2,$4,$7);
                                                                      if(conn != NULL)
                                                                            conn = template("%s, .%s=%s",conn,$2,$2);
                                                                      else
                                                                            conn = template(".%s=%s",$2,$2);
                                                                      func_index++;
                                                                      $$ = template("void (*%s)(SELF%s)",$2,$4);
} 
;

comp_arg_dec:
%empty {$$ = "";}
| single_arg_dec {$$ = template(",%s",$1);}
|arg_dec ',' single_arg_dec {$$ = template(",%s,%s",$1,$3);}
;

body: 
%empty {$$ = " ";}
| body const_dec ';' {$$ = template("%s\n%s;",$1,$2);}
| body var_dec ';'  {$$ = template("%s\n%s;",$1,$2);}
| body assignment ';' {$$ = template("%s\n%s;",$1,$2);}
| body if_cmd    ';' {$$ = template("%s\n%s",$1,$2);}
| body for_cmd ';'    {$$ = template("%s\n%s",$1,$2);}
| body while_cmd ';'    {$$ = template("%s\n%s",$1,$2);}
| body func_call  ';'  {$$ = template("%s\n%s;",$1,$2);}
| body KW_BREAK ';'    {$$ = template("%s\nbreak;",$1);}
| body KW_CONT ';'    {$$ = template("%s\ncontinue;",$1);}
| body ret_statement ';'    {$$ = template("%s\n%s;",$1,$2);}
| body comprehension ';'   {$$= template("%s\n%s;",$1,$2);}
;

mult_identifiers:
identifiers {$$ = $1;}
| mult_identifiers ',' identifiers {$$ = template("%s , %s",$1,$3);}
;

ret_statement:
KW_RET {$$ = template("return");}
| KW_RET operations {$$ = template("return %s",$2);}
;

single_arg_dec:
identifiers ':' data_type {$$ = template("%s %s",$3,$1);}
| array_type ':' data_type {$$ = template("%s %s",$3,$1);}
;

arg_dec:
%empty {$$ = "";}
|single_arg_dec {$$ = $1;}
|arg_dec ',' single_arg_dec {$$ = template("%s,%s",$1,$3);}
;

ident:
TK_IDENT {$$ = $1;}
| array_idx {$$ = $1;}
;

identifiers:
ident     {$$ = $1;}
| '#' ident {$$ = template("self->%s",$2);} 
| identifiers '.' ident {parent = $1;$$ = template("%s.%s",$1,$3);}
| identifiers TK_MEMBER ident {$$ = template("%s.%s",$1,$3);}
;

var_dec:
mult_identifiers ':' data_type  {
  if(comp == 1){
    $$ = template("%s %s = ctor_%s",$3,$1,$3);
    comp = 0;
  }
  else
  $$ = template("%s %s",$3,$1);}
;

mult_var_dec:
var_dec ';' {$$ = template("%s;",$1);}
| mult_var_dec var_dec ';' {$$ = template("%s\n%s;",$1,$2);}
;

mult_args:
mult_args ',' args  {$$ = template("%s , %s",$1,$3);}
| args              {$$ = $1;}

args:
%empty      {$$="";}
| array_type {$$ = $1;}
| operations {$$ = $1;}
;

mult_const_dec:
mult_const_dec const_dec ';' {$$ = template("%s , %s",$1,$2);}
|const_dec ';'              {$$ = template("%s",$1);}
;

const_dec:
KW_CONST TK_IDENT '=' expr ':' data_type  {$$ = template("const %s %s = %s;",$6,$2,$4);}
;

array_idx:
TK_IDENT '[' operations ']' {$$ = template("%s[%s]",$1,$3);}
;

array_type:
TK_IDENT '[' ']' {$$ = template("%s[]",$1);}
;

for_cmd:
KW_FOR TK_IDENT KW_IN '[' operations ':' operations ':' operations ']' ':' body KW_ENDFOR{$$ = template("for(int %s=%s;%s<%s;%s+=%s){\t%s\n}\n",$2,$5,$2,$7,$2,$9,$12);}
|KW_FOR TK_IDENT KW_IN '[' operations ':' operations']' ':' body KW_ENDFOR {$$ = template("for(int %s=%s;%s<%s;%s++){\t%s\n}\n",$2,$5,$2,$7,$2,$10);}
;

if_cmd:
KW_IF '(' operations ')' ':' body KW_ENDIF  {$$ = template("if(%s){\t%s\n}\n",$3,$6);}
|KW_IF '(' operations ')' ':' body KW_ELSE ':' body KW_ENDIF  {$$ = template("if(%s){%s}\nelse\n{\t%s\n}\n",$3,$6,$9);}
;

while_cmd:
KW_WHILE '(' operations ')' ':' body KW_ENDWHILE {$$ = template("while(%s){\t%s\n}\n",$3,$6);}
;

func_call:
identifiers '(' mult_args ')' {
  if(parent!=NULL){ //is this is call refers to a composite member function pass the self argument
      if($3 == ""){
        $$ = template("%s(&%s)",$1,parent,$3); //No other arguments
      }
      else
        $$ = template("%s(&%s,%s)",$1,parent,$3); //Multiple arguments
    parent = NULL;
  }
  else
    $$ = template("%s(%s)",$1,$3);}
;

comprehension:
TK_IDENT TK_ARRAY_CR '[' operations KW_FOR TK_IDENT ':' TK_INT ']' ':' data_type  {$$ = template("%s* %s = (%s*)malloc(%s * sizeof(%s));\nfor(int %s=0;%s<%s;++%s)\n\t%s[%s]=%s",$11,$1,$11,$8,$11,$6,$6,$8,$6,$1,$6,$4);}
|TK_IDENT TK_ARRAY_CR '[' operations KW_FOR TK_IDENT ':' data_type KW_IN TK_IDENT KW_OF TK_INT ']' ':' data_type  {
  char* rep= strdup($10); //Get a copy of the original string
  char* op = $4;
  char* elm = $6;
  strcat(rep,"[array_i]"); //In this case we need to replace the variable used in the expression with each array index 
  $$ = template("%s* %s = (%s*)malloc(%s * sizeof(%s));\nfor(int array_i=0;array_i<%s;++array_i)\n\t%s[array_i]=%s",$15,$1,$15,$12,$15,$12,$1,str_replace(op,elm,rep));

}
;

assignment: 
 identifiers '=' operations {$$ = template("%s = %s",$1,$3);}
| identifiers TK_ASSGN_IN operations {$$ = template("%s += %s",$1,$3);}
| identifiers TK_ASSGN_DE operations {$$ = template("%s -= %s",$1,$3);}
| identifiers TK_ASSGN_MU operations {$$ = template("%s *= %s",$1,$3);}
| identifiers TK_ASSGN_DIV operations {$$ = template("%s /= %s",$1,$3);}
| identifiers TK_ASSGN_MOD operations {$$ = template("%s %%= %s",$1,$3);}
;

operations:
  expr {$$ = $1;}
| operations TK_MOD operations {$$ = template("%s %% %s",$1,$3);}
| operations TK_POWER operations {$$ = template("pow(%s,%s)",$1,$3);}
| operations '+' operations {$$ = template("%s + %s",$1,$3);}
| operations '-' operations {$$ = template("%s - %s",$1,$3);}
| operations '/' operations {$$ = template("%s / %s",$1,$3);}
| operations '*' operations {$$ = template("%s * %s",$1,$3);}
| '-' operations {$$ = template("-%s",$2);}
| '+' operations {$$ = template("+%s",$2);}
| '(' operations ')' {$$ = template("(%s)",$2);}
| TK_NOT operations {$$ = template("!%s",$2);}
| operations TK_AND operations {$$ = template("%s && %s",$1,$3);}
| operations TK_OR operations {$$ = template("%s || %s",$1,$3);}
| operations TK_COMP operations {$$ = template("%s == %s",$1,$3);}
| operations TK_COMP_GEQ operations {$$ = template("%s >= %s",$1,$3);}
| operations TK_COMP_GR operations {$$ = template("%s > %s",$1,$3);}
| operations TK_COMP_LEQ operations {$$ = template("%s <= %s",$1,$3);}
| operations TK_COMP_LESS operations {$$ = template("%s < %s",$1,$3);}
| operations TK_COMP_NEQ operations {$$ = template("%s != %s",$1,$3);}
;


expr:
  identifiers {$$ = $1;}
| func_call {$$ = $1;}
| TK_INT {$$ = $1;}
| TK_REAL {$$ = $1;}
| TK_STRING {$$ = $1;}
| KW_TRUE {$$ = $1;}
| KW_FALSE {$$ = $1;}
;

data_type:
KW_INT {comp=0;$$ = "int";}
| KW_BOOL {comp=0;$$ = "int";}
| KW_SCA  {comp=0;$$ = "float";}
| KW_STR  {comp=0;$$ = "char*";}
| TK_IDENT {comp=1;$$ = $1;}
;

%%
int main () {
  
  if ( yyparse() == 0 )
    printf("Accepted!\n");
  else
    printf("Rejected!\n");

  fclose(fptr);
}
