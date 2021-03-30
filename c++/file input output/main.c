#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c;
    FILE *ptr,*ptr1;
    ptr=fopen("input.txt","r");
    if(ptr==NULL)
        puts("Error in opening file");
    else
    {
        while((c=fgetc(ptr))!=EOF)
            printf("%c",c);
    }
    return 0;
}
