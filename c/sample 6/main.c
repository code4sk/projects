#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
 char arr[17];
 int num=0;
     gets(arr);
     fflush(stdin);
     for(int i=0;i<16;i++)
     {

         if(i!=4&&i!=8&&i!=12&&i!=16)
         {
            printf("%c",arr[i]);
        }
        else
        {
            printf("-%c",arr[i]);
        }
     }
}
