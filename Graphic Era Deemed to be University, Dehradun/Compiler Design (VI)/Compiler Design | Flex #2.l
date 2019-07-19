/*
Problem Statement: Write a program to print the number of digit tokens
*/
%%
[0-9] {printf("A digit\n");}
.     {printf("Not a digit\n");}
%%

int yywrap(){}

int main(){

  yylex();
  return 0;
}
