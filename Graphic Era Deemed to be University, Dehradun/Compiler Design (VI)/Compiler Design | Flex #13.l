%{
int count = 0;
int flag = 0;
%}
%%
[ \n\t]+[ \n\t]*  {flag = 0;}
[+-][0-9]+[ \n\t] {if(flag == 0)count++; flag = 0;}
[0-9]+[\n\t ]     {if(flag == 0)count++; flag = 0;}
.                 {flag = 1;}
%%

int yywrap(){}
int main(){

  yylex();
  printf("Number of valid integers %d\n",count);
  return 0;
}
