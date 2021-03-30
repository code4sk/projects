#include <stdio.h>
#include <stdlib.h>

main()
{
    FILE *ptr,*ptr1;
    char str[21];
    char str1[21];
    ptr=fopen("d:/new.txt","r");
    ptr1=fopen("G:/new1.txt","w");
    if(ptr==NULL)
    {
        printf("error");
    }
    else
    {
    fgets(str,21,stdin);
    fflush(stdin);
    fprintf(ptr1,"%s",str);
    }

}
