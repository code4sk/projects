#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b;
    FILE *ptr,*ptr1;
    char inp[181];
    int z;
    ptr=fopen("d:/new.txt","r");
    ptr1=fopen("d:/new1.txt","a");
    if(a!=NULL)
    {
        puts("files opened");
    while((fgets(inp,181,ptr))!=NULL)
          {
             fputs(inp,ptr1);
              printf("%s",inp);
          }
    }
    else
    {
     puts("file cannot open");
    }
    fclose(ptr);
    fclose(ptr1);
    return 0;
}
