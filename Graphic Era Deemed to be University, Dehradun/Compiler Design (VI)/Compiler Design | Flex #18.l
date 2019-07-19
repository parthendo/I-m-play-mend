/*
Mod-5 machine: Accepts binary numbers divisible by 5
Author: Parth Trehan
*/
%{
%}
%s A B C D E F

%%
<INITIAL>0 BEGIN A;
<INITIAL>1 BEGIN B;
<INITIAL>[^0|\n] BEGIN F;
<INITIAL>\n {BEGIN INITIAL; printf("Not Accepted\n");}
<A>0 BEGIN A;
<A>1 BEGIN D;
<A>[^0|\n] BEGIN F;
<A>\n {BEGIN INITIAL; printf("Accepted\n");}
<B>0 BEGIN C;
<B>1 BEGIN D;
<B>[^0|\n] BEGIN F;
<B>\n {BEGIN INITIAL; printf("Not Accepted\n");}
<C>0 BEGIN E;
<C>1 BEGIN A;
<C>[^0|\n] BEGIN F;
<C>\n {BEGIN INITIAL; printf("Not Accepted\n");}
<D>0 BEGIN B;
<D>1 BEGIN C;
<D>[^0|\n] BEGIN F;
<D>\n {BEGIN INITIAL; printf("Not Accepted\n");}
<E>0 BEGIN D;
<E>1 BEGIN E;
<E>[^0|\n] BEGIN F;
<E>\n {BEGIN INITIAL; printf("Not Accepted\n");}
<F>0 BEGIN F;
<F>1 BEGIN F;
<F>[^0|\n] BEGIN F;
<F>\n {BEGIN INITIAL; printf("INVALID\n");}
%%
int yywrap(){}

void main()
{
yylex();
}
