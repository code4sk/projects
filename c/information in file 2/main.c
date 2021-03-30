#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *ptr,*ptr1;
    char a,str[21]={"shubham kapoor"};
    ptr=fopen("d:/new.txt","r+");
    if(ptr!=NULL)
    {

        /*while((a=fgetc(ptr))!=EOF)
        {
            fprintf(ptr1,"%c",a);
        }*/

        fseek(ptr,5,0);
        fprintf(ptr,"%s",str);
        puts("success");
    }
    else
    {
        puts("error");
    }
    return 0;
}
