%{
#include<stdio.h>
int v=0,op=0,id=0,flag=0;
%}
%%
[a-zA-Z]+[0-9A-Za-z]* {id++;printf("\n Identifier:");ECHO;}
[\+\-\*\/\=] {op++;printf("\n Operartor:");ECHO;}
"(" {v++;}
")" {v--;}
";" {flag=1;}
.|\n {;}
%%
main()
{
printf("\n Enter the expression \n");
yylex();
if((op+1)==id&&v==0&&flag==0)
printf("\n Expression is Valid\n");
else
printf("\n Expression is Invalid\n");
printf("\n The number of identifiers are: %d \n",id);
printf("\n The number ofoperators are: %d \n",op);
int yywrap()
{
return 1;
}
}
