/*
Problem Statement: Flex Code to count the number of digit tokens encountered in the given input.
*/
%{
int count = 0;
%}
%%
[0-9] {count++;printf("%s\n",yytext);}
.
%%

int yywrap(){}
int main(){

  yylex();
  printf("Number of digits encountered %d\n",count);
  return 0;
}
