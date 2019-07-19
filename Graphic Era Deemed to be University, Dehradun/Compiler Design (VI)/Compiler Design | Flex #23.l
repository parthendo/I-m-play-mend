/*
DFA: Accepts string containing a valid C language identifier
Author: Parth Trehan
Roll No.: 2010660
*/
%{
%}

%s q0 q1 q2

%%
<INITIAL>[$|_|a-z|A-Z] BEGIN q0;
<INITIAL>\n {BEGIN INITIAL; printf("Not Accepted\n");}
<INITIAL>. BEGIN q1;
<q0>[$|0-9|a-z|A-Z|_] BEGIN q0;
<q0>\n {BEGIN INITIAL; printf("Accepted\n");}
<q0>. BEGIN q1;
<q1>\n {BEGIN INITIAL; printf("Not Accepted\n");}
<q1>. BEGIN q1;
%%

int yywrap(){}
int main(){
  yylex();
}
