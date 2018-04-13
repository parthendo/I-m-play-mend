%%
[pP][aA][rR][tT][hH] {printf("ChachaChaudhary");}
. {printf("%s",yytext);}
%%

int yywrap(){}

int main(){

  yylex();
  return 0;
}
