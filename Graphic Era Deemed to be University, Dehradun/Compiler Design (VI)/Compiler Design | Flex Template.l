%{
int count = 0;
%}
%%
[0-9] {printf("%s a digit\n",yytext);}
.     {printf("%s not digit\n",yytext);}
%%

int yywrap(){}
int main(){

  //yywrap() - wraps the above rule section
  //yyin - takes the file pointer which contains the input
  //yylex() - this is the main flex funtion which runs the Rule Section
  //yytext is the text in the buffer in which the character/s which is being processed is stored
  //yyleng is the length of overall string which is being processed in the rule

  //Uncomment the lines below to take input from file
  //FILE *fp;
  //char filename[50];
  //printf("Enter the filename: \n");
  //scanf("%s",filename);
  //fp = fopen(filename,"r");
  //yyin = fp;
  yylex();
  return 0;
}
