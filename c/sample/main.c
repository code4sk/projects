#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
FILE *ptr,*ptr1,*ptr2;
int roll;
char a,b,c,d,e,f,g,h;
char str[21],alph[21],name[51],class[41],schl[41];
ptr=fopen("d:/goku.txt","r+");
if(ptr!=NULL)
{
    fseek(ptr,5,0);
    fprintf(ptr,"x");
    puts("success");
}
else
{
    puts("error");
}
    return 0;
}
