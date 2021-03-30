#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
void main()
{
char name[41];
int num=0;
gets(name);
for(int i=0;name[i]!='\0';i++)
{
    ++num;

}
 printf("%d",num);

}

