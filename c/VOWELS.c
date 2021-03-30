#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
void main()
{
char chc;
puts("MENU");
puts("1 : CREATE A DIRECTORY");
puts("2 : DELETE A DIRECTORY");
puts("3 : SHOW A DIRECTORY");
puts("4 : EXIT");
puts("ENTER YOUR CHOICE");
scanf("%f",&chc);
switch(chc)
{
case'1':puts("YOU CHOSE CREATE A DIRECTORY");
break;
case'2':puts("YOU CHOSE DELETE A DIRECTORY");
break;
case'3':puts("YOU CHOSE SHOW A DIRECTORY");
break;
case'4':puts("YOU CHOSE EXIT");
break;
default:puts("INVALID CHOICE");
}
}
