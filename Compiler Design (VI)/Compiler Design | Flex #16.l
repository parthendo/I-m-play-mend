%{
int count = 0;
int positive = 0,negative = 0;
int flag = 0;
%}
%%
[ \n\t]+[ \n\t]*      	    {flag = 0;}
[-][0-9]+[.][0-9]+[ \n\t]   {if(flag == 0){count++;negative++;} flag = 0;}
[+]*[0-9]+[.][0-9]+[ \n\t]  {if(flag == 0){count++;positive++;} flag = 0;}
.                           {flag = 1;}
%%

int yywrap(){}
int main(){

  yylex();
  printf("Count of valid floating point numbers %d\n",count);
  printf("Count of positive floating point numbers %d\n",positive);
  printf("Count of negative floating point numbers %d\n",negative);
  return 0;
}
