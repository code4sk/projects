#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str[21],alph[21],*ptr,*lptr;
    int num=0;
    gets(str);
    fflush(stdin);
    gets(alph);
    fflush(stdin);
    for(int i=0;str[i]!='\0';i++)
    {
        num++;
    }
    ptr=str;
    lptr=alph;
    ptr=ptr+num;
    for(;*lptr!='\0';lptr++)
    {
        *ptr=*lptr;
        ptr++;
    }

    printf("%s",str);

    return 0;
}
