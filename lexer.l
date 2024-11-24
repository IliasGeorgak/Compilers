%{

  
  #define MAX_MACRO 100 
  #include <math.h>
  #include <string.h>
  #include <stdlib.h>
  #include <stdio.h>
  #include "parser.tab.h"

  int line_num = 1;
  int macro_cnt = 0;
  char* macros[MAX_MACRO][2] ;

  int define_macro(char*,char*);

  char* is_macro(char*);

%}

%x definition

PLUS ("+")
MINUS ("-")
MOD ("%")
DIV ("/")
MULT ("*")
SYMBOLS [:_$!#@&~^,.]
SPACE [ \r\t]
ESCAPE_CHAR ("\n")|("\t")|("\\")|("\"")|("\r")
ID      [a-zA-Z_][0-9a-zA-Z_]*
DIGIT   [0-9]
NUMBER  {DIGIT}{DIGIT}*
DECIMAL ("."{NUMBER})|({NUMBER}("."{NUMBER}?)?)
REAL    {DECIMAL}([eE]{NUMBER})?
BOOL    ("True")|("False")
STRING  ["]({ID}|{SPACE}|{DIGIT}|{SYMBOLS}|{ESCAPE_CHAR}|{PLUS}|{MINUS}|{MULT}|{MOD}|{DIV})*["]
%%

"@defmacro"{SPACE}+ {  BEGIN(definition); }
<definition>{ID} { char* identifier = strdup(yytext);
                   char* value = NULL;
	                 size_t val_len = 0;
	                 char c;

                   FILE* deff = open_memstream(&value, &val_len);

	                 while((c=input())!='\n'){
		                fputc(c, deff);
	                 }
	                 fclose(deff);



	                 if(define_macro(identifier, value) == 1)
		                printf("lexer error: failed to define macro '%s'\n", identifier);
	                 BEGIN(INITIAL);}

integer     return KW_INT;
scalar	    return KW_SCA;
str	    return KW_STR;
bool	    return KW_BOOL;
boolean   return KW_BOOL;
True	    {yylval.str = strdup("1"); return KW_TRUE;}
False	    {yylval.str = strdup("0"); return KW_FALSE;}
const	    return KW_CONST;
if          return KW_IF;
else	    return KW_ELSE;
endif       return KW_ENDIF;
for	    return KW_FOR;
in	    return KW_IN;
endfor	    return KW_ENDFOR;
while	    return KW_WHILE;
endwhile    return KW_ENDWHILE;
break	    return KW_BREAK;
continue   return KW_CONT;
comp       return KW_COMP;
endcomp    return KW_ENDCOMP;
of	   return KW_OF;
def        return KW_DEF;
enddef	   return KW_ENDDEF;
main       return KW_MAIN;
return	    return KW_RET;
and	    return TK_AND;
or	    return TK_OR;
not	    return TK_NOT;



{ID}        { char* identifier = strdup(yytext);
              char* value = is_macro(identifier);
              if(value!=NULL){
                yytext = strdup(value);
                yylval.str = strdup(yytext);
                return TK_STRING;
              }
              yylval.str = strdup(yytext);
              return TK_IDENT;
              
              return TK_IDENT;} 
{NUMBER}    {yylval.str = strdup(yytext); return TK_INT;} 
{REAL}      {yylval.str = strdup(yytext); return TK_REAL;}
{STRING}    {yylval.str = strdup(yytext); return TK_STRING;}

{PLUS}         return '+';
{MINUS}         return '-';
{MULT}        return '*';
{DIV}         return '/';
{MOD}    return TK_MOD; 
"**"	    return TK_POWER;
"("	    return '(';
")"	    return ')';
"->"    return TK_ARROW;
":="    return TK_ARRAY_CR;
"#"     return '#';
"."     return '.';
".#"    return TK_MEMBER;

"="         return '=' ;
"+="        return TK_ASSGN_IN;
"-="	    return TK_ASSGN_DE;
"*="	    return TK_ASSGN_MU;
"/="        return TK_ASSGN_DIV;
"%="        return TK_ASSGN_MOD;

","         return ',';
":"         return ':';
";"       return ';';
"["       return  '[';
"]"       return ']';

"=="	    return TK_COMP;
"!="	    return TK_COMP_NEQ ;
"<"         return TK_COMP_LESS ;
"<="        return TK_COMP_LEQ ;
">"	    return TK_COMP_GR ;
">="        return TK_COMP_GEQ ;

"--"[^\n]*  //printf("Line %d: line comment: %s\n", line_num, yytext);/* eat line comments */

{SPACE}+		/* eat whitespace */

\n 	     {++line_num; /*printf("%d\n",line_num);*/};




<<EOF>> 	return EOF;

.           { printf("Line %d Lexical Error: Unrecognized literal %s\n", line_num, yytext); return EOF;}

%%
int define_macro(char* ident,char* val){
  int i;
  for(i=0;i<macro_cnt;i++){
    if(strcmp(macros[i][0],ident)==0){
      free(macros[i][1]);
      macros[i][1] = val;
      return 0;
      
    }
  }
  if(macro_cnt<MAX_MACRO && i>=macro_cnt){
    macros[macro_cnt][0]=ident;
    macros[macro_cnt][1] = val;
    macro_cnt++;
    return 0;
  }
  else{
    return 1;
  }
}

char* is_macro(char* ident){
  for(int i=0;i<macro_cnt;i++){
    if(strcmp(macros[i][0],ident)==0){
      return macros[i][1];
    }
  }
  return NULL;
}





