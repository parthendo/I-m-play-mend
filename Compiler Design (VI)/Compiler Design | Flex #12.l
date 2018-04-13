%{
int x = 0;
%}
%%
[^abc]    {printf("this\n"); x++;}
.         {printf("thisnot\n"); }
%%

int yywrap(){}
int main(){

  yylex();
  printf("%d\n",x);
  return 0;
}
