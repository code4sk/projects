#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *ptr;
    char x;
    int end;
    ptr=fopen("d:/new.txt","r");
    if(ptr!=EOF)
    {
    fseek(ptr,5,0);
    while((end=fscanf(ptr,"%c",&x))!=EOF)
    {
        printf("%c",x);
    }
    }
    return 0;
}
