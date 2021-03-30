#include <stdio.h>
#include <stdlib.h>
void swap(char *,char *);
void per(char str[21],char *);
int main()
{
    char str[21];
    printf("Enter the string\t");
    gets(str);
    per(str,str);
    return 0;
}
void per(char str[],char *p)
{
    char *ptr;
    if(*(p+1)==NULL)
    {
        printf("%s\t",str);
    }
    else
    {
        for(ptr=p;*ptr!=NULL;ptr++)
        {
            swap(p,ptr);
            per(str,p+1);
            swap(p,ptr);
        }
    }
}
void swap(char *p,char *ptr)
{
    char temp;
    temp=*p;
    *p=*ptr;
    *ptr=temp;
}
