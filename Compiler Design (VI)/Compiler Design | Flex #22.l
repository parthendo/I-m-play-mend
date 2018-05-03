/*
DFA: Accepts string starting with alphabet x and ends with alphabet y and contains alphabets only.
Note: Program works in lowercase only!
Author: Parth Trehan
Roll No.: 2010660
*/
%{
%}

%s q0 q1 q2 q3

%%
<INITIAL>x BEGIN q0;
<INITIAL>[a-z] BEGIN q2;
<INITIAL>\n {BEGIN INITIAL; printf("Not Accepted\n");}
<INITIAL>. BEGIN q3;
<q0>y BEGIN q1;
<q0>[a-z] BEGIN q0;
<q0>\n {BEGIN INITIAL; printf("Not Accepted\n");}
<q0>. BEGIN q3;
<q1>y BEGIN q1;
<q1>[a-z] BEGIN q0;
<q1>\n {BEGIN INITIAL; printf("Accepted\n");}
<q1>. BEGIN q3;
<q2>[a-z] BEGIN q2;
<q2>\n {BEGIN INITIAL; printf("Not Accepted\n");}
<q2>. BEGIN q3;
<q3>\n {BEGIN INITIAL; printf("INVALID\n");}
<q3>. BEGIN q3;
%%

int yywrap(){}
int main(){
  yylex();
}
