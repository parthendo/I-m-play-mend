/*
Design a lex code that takes input in a file and replaces your name with your best
friend’s name
Author: Parth Trehan
Roll No.: 2010660
*/
%{
%}
%%
[Pp][Aa][Rr][Th][Hh] fprintf(yyout,"Markus");
. fprintf(yyout,"%s",yytext);
%%
int yywrap(){}
int main()
{
extern FILE *yyin, *yyout;
yyin = fopen("Input.txt","r");
yyout = fopen("Output.txt","w");
yylex();
return 0;
}
