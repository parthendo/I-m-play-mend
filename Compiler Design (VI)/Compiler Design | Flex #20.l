/*
DFA: Accepts all the strings either stating from 111 or ending with 000
Author: Parth Trehan
Roll No.: 2010660
*/
%{
%}

%s A B C D E F G H

%%
<INITIAL>0 BEGIN D;
<INITIAL>1 BEGIN A;
<INITIAL>[^0|1|\n] BEGIN H;
<INITIAL>\n {BEGIN INITIAL; printf("Not Accepted\n");}
<A>0 BEGIN D;
<A>1 BEGIN B;
<A>[^0|1|\n] BEGIN H;
<A>\n {BEGIN INITIAL; printf("Not Accepted\n");}
<B>0 BEGIN D;
<B>1 BEGIN C;
<B>[^0|1|\n] BEGIN H;
<B>\n {BEGIN INITIAL; printf("Not Accepted\n");}
<C>0 BEGIN C;
<C>1 BEGIN C;
<C>[^0|1|\n] BEGIN H;
<C>\n {BEGIN INITIAL; printf("Accepted\n");}
<D>0 BEGIN F;
<D>1 BEGIN E;
<D>[^0|1|\n] BEGIN H;
<D>\n {BEGIN INITIAL; printf("Not Accepted\n");}
<E>0 BEGIN D;
<E>1 BEGIN E;
<E>[^0|1|\n] BEGIN H;
<E>\n {BEGIN INITIAL; printf("Not Accepted\n");}
<F>0 BEGIN G;
<F>1 BEGIN E;
<F>[^0|1|\n] BEGIN H;
<F>\n {BEGIN INITIAL; printf("Not Accepted\n");}
<G>0 BEGIN G;
<G>1 BEGIN E;
<G>[^0|1|\n] BEGIN H;
<G>\n {BEGIN INITIAL; printf("Accepted\n");}
<H>0 BEGIN H;
<H>1 BEGIN H;
<H>[^0|1|\n] BEGIN H;
<H>\n {BEGIN INITIAL; printf("INVALID\n");}
%%

int yywrap(){}
int main(){

  yylex();
}
