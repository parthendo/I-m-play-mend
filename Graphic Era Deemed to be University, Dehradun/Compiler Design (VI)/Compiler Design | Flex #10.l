%{
int newline = 0;
int tab = 0;
int character = 0;
%}
%%
[\n] {printf("A newline character is encountered\n"); newline++;}
[\t] {printf("A tab metacharacter is encountered\n"); tab++;}
.    {printf("%s is a character\n",yytext); character++;}
%%

int yywrap(){}
int main(){

  //yywrap() - wraps the above rule section
  //yyin - takes the file pointer which contains the input
  //yylex() - this is the main flex funtion which runs the Rule Section
  //yytext is the text in the buffer

  //Uncomment the lines below to take input from file
  //FILE *fp;
  //char filename[50];
  //printf("Enter the filename: \n");
  //scanf("%s",filename);
  //fp = fopen(filename,"r");
  //yyin = fp;
  yylex();
  printf("Number of newline character %d\n",newline);
  printf("Number of tab character %d\n",tab);
  printf("Number of other character %d\n",character);
  return 0;
}
