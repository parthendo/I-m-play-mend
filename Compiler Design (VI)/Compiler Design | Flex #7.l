%{
int consonants = 0;
int vowels = 0;
%}
%%
[AEIOUaeiou] {vowels++;}
[A-Za-z] {consonants++;}
.
%%

int yywrap(){}

int main(){

  yylex();
  printf("Number of consonants character %d\n",consonants);
  printf("Number of vowels character %d\n",vowels);
  return 0;
}
