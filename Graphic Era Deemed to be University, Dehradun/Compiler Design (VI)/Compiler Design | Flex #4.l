/*
Problem Statement: Write a lex code to count the number of vowels in the given input.
*/
%{
int vowels = 0;
%}
%%
[AEIOUaeiou] {vowels++;}
.
%%

int yywrap(){}
int main(){

  yylex();
  printf("Number of vowels character %d\n",vowels);
  return 0;
}
