/*
Design a lex code to take input from a file and remove all spaces, newline and tab
characters replace new line, spaces and tab with single space.
Author: Parth Trehan
Roll No.: 2010660
*/

%{
%}
%%
[ \n\t]+ fprintf(yyout," ");
. fprintf(yyout,"%s",yytext);
%%
int yywrap(){}
int main()
{
extern FILE *yyin,*yyout;
yyin=fopen("Input.txt","r");
yyout=fopen("Output.txt","w");
yylex();
return 0;
}
