%{
int newline = 0;
int tab = 0;
int character = 0;
int words = 0;
int space = 0;
%}
%%
[\n]           {newline++;}
[\t]           {tab++;}
[A-Za-z]+      {words++;character+=yyleng;}
[ ]            {space++;}
.              {character++;}
%%

int yywrap(){}
int main(){

  //NTS: Look out for yyleng
  //Rule can also be written as
  //[^\n\t ]+
  //.
  
  yylex();
  printf("Number of newline character %d\n",newline);
  printf("Number of tab character %d\n",tab);
  printf("Number of words %d\n",words);
  printf("Number of space %d\n",space);
  printf("Number of characters %d\n",character);
  return 0;
}
