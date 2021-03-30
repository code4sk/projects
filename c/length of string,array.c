#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
void main()
{
    char alph[21],str[21];
    int num1=0,num2=0;
    gets(alph);
    fflush(stdin);
    gets(str);
    fflush(stdin);
    for(int i=0;alph[i]!='\0';++i)
        num1++;
    for(int j=0;str[j]!='\0';++j)
        num2++;
    if(num1>num2)
        printf("string 1");
    if(num2>num1)
        printf("string 2");
    if(num1==num2)
        printf("both are equal");
}


