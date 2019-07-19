/*
DFA: Accepts all the strings either starting with 01 or ending with 11
Author: Parth Trehan
Roll No.: 2010660
*/
%{
%}

%s A B C D E F

%%
<INITIAL>0 BEGIN A;
<INITIAL>1 BEGIN D;
<INITIAL>[^0|\n] BEGIN B;
<INITIAL>\n {BEGIN INITIAL; printf("Not Accepted\n");}
<A>1 BEGIN C;
<A>0 BEGIN F;
<A>[^0|\n] BEGIN B;
<A>\n BEGIN INITIAL; printf("Not Accepted\n");
<C>0 BEGIN C;
<C>1 BEGIN C;
<C>[^0|\n] BEGIN B;
<C>\n {BEGIN INITIAL; printf("Accepted\n");}
<D>1 BEGIN E;
<D>0 BEGIN F;
<D>[^0|\n] BEGIN B;
<D>\n {BEGIN INITIAL; printf("Not Accepted\n");}
<E>0 BEGIN F;
<E>1 BEGIN D;
<E>[^0|\n] BEGIN B;
<E>\n {BEGIN INITIAL; printf("Accepted\n");}
<F>0 BEGIN F;
<F>1 BEGIN D;
<F>[^0|\n] BEGIN B;
<F>\n {BEGIN INITIAL; printf("Not Accepted\n");}
<B>0 BEGIN B;
<B>1 BEGIN B;
<B>[^0|\n] BEGIN B;
<B>\n {BEGIN INITIAL; printf("INVALID\n");}
%%
int yywrap(){}

void main()
{
yylex();
}
