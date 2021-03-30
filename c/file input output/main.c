#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c[181];
    FILE *ptr,*ptr1;
    ptr=fopen("G:/input.txt","r");
    ptr1=fopen("G:/output.txt","w");
    if(ptr==NULL)
        puts("Error in opening file");
    else
    {
        while((fgets(c,3,ptr))!=NULL)
         fputs(c,ptr1);
         fseek(ptr,11,0);
         fgets(c,181,ptr);
               printf("%s",c);
    }
    return 0;
}
