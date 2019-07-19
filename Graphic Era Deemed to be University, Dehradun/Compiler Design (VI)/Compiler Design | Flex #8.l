%{
  int flag = 0;
  int word = 0;
%}

%%
[ \n\t] {flag = 0;}
[pP][a-zA-Z]*[tT][ \n\t] {if(flag == 0) word++; flag = 0;}
.       {flag = 1;}
%%

int yywrap(){}

int main(){

  yylex();
  printf("Number of words passing such contraints are %d\n",word);
  return 0;
}
