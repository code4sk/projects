#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
    char str[101],alph[101],a,*ptr1,*ptr2;
    FILE *ptr;
    ptr=fopen("d:/alp.txt","r+");
    if(ptr!='\0')
    {
        fgets(str,101,ptr);
        fflush(stdin);
        printf("%s",str);
        for(int m=0;str[m]!='\0';m++)
        {
        alph[m]=str[m];
        }
        ptr1=str;
        ptr2=alph;
        for(int i=0;i<strlen(str);i++)
        {
          ptr2++;
        }
        ptr2--;
        for(int j=0;j<strlen(str);j++)
        {
            *ptr1=*ptr2;
            ptr1++;
            ptr2--;
        }
        fseek(ptr,0,1);
        fprintf(ptr,"\n%s",str);
        puts("\nsuccess");
    }
    else
    {
        puts("error");
    }
    return 0;
}
