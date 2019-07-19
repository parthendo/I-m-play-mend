/*
DFA: Accepts string starting with a vowel and containing first name as a substring
Note: Program works in lowercase only!
Author: Parth Trehan
Roll No.: 2010660
*/
%{
%}

%s A B C D E F G H

%%
<INITIAL>[a|e|i|o|u] BEGIN A;
<INITIAL>\n {BEGIN INITIAL; printf("Not Accepted\n");}
<INITIAL>[^a|^e|^i|^o|^u] BEGIN G;
<INITIAL>. BEGIN H;
<A>p BEGIN B;
<A>[a-z] BEGIN A;
<A>\n {BEGIN INITIAL; printf("Not Accepted\n");}
<A>. BEGIN H;
<B>a BEGIN C;
<B>[a-z] BEGIN A;
<B>\n {BEGIN INITIAL; printf("Not Accepted\n");}
<B>. BEGIN H;
<C>r BEGIN D;
<C>[a-z] BEGIN A;
<C>\n {BEGIN INITIAL; printf("Not Accepted\n");}
<C>. BEGIN H;
<D>t BEGIN E;
<D>[a-z] BEGIN A;
<D>\n {BEGIN INITIAL; printf("Not Accepted\n");}
<D>. BEGIN H;
<E>h BEGIN F;
<E>[a-z] BEGIN A;
<E>\n {BEGIN INITIAL; printf("Not Accepted\n");}
<E>. BEGIN H;
<F>[a-z] BEGIN F;
<F>\n {BEGIN INITIAL; printf("Accepted\n");}
<F>. BEGIN H;
<G>[a-z] BEGIN G;
<G>\n {BEGIN INITIAL; printf("Not Accepted\n");}
<G>. BEGIN H;
<H>\n {BEGIN INITIAL; printf("INVALID\n");}
<H>. BEGIN H;
%%

int yywrap(){}
int main(){
  yylex();
}
