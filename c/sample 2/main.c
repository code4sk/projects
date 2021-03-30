#include <stdio.h>
#include <stdlib.h>

int main()
{
   FILE *ptr;
   int g;
   char j[21];
   ptr=fopen("d:/new1.txt","r+");
   if(ptr!='\0')
   {
       fscanf(ptr,"%c",j);
       //fseek(ptr,0,1);
       //fseek(ptr,8,0);
  /* while((g=getc(ptr))!='m')
   {

   }*/
   //ffffffffffffff;
   fprintf(ptr,"abc");
   puts("success");
   }
    return 0;
}
