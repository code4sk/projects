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
        num1=num1+alph[i];
    for(int j=0;str[j]!='\0';++j)
        num2=num2+str[j];
    if(num1==num2)
        printf("equal");
        if(num1>num2)
         printf("string1");
    if(num2>num1)
     printf("string2");

}


