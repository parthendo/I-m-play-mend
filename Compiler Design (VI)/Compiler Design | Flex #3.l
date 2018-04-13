/*
Problem Statement: Write a flex code to count the number of digit tokens
*/

%{
int counter = 0;
%}
%%
[0-9] {counter++;}
.
%%

int yywrap(){}

int main(){

  yylex();
  printf("Total number of digits in the input are %d\n",counter);
  return 0;
}
