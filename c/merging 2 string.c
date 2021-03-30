#include <stdio.h>
#include <stdlib.h>

void main()
{
    char alph[21];
    char str[21];
    char string[42];
    int num=0;
    gets(alph);
    fflush(stdin);
    gets(str);
    fflush(stdin);
    for(int i=0,j=0;alph[j]!='\0';++i)
    {
        string[i]=alph[j];
        ++j;
        string[i+1]='\0';
        num++;
    }
    string[num]='\0';
    for(int m=num+1,n=0;str[n]!='\0';++m)
    {
        string[m]=str[n];
        ++n;
        string[m]='\0';
    }
    printf("%s",string);
}

