#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
void main()
{
char str[21],alph[21];
int num=0;
puts("enter the string");
gets(str);
fflush(stdin);
for(int i=0;str[i]!='\0';i++)
    num++;
    num--;
for(int j=0;j<=num;++j)
{
    alph[j]=str[num-j];
    alph[j+1]='\0';
}
printf("%s",alph);
}
