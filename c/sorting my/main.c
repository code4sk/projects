#include <stdio.h>
#include <stdlib.h>

void main()
{
    int number[5]={0,0,0,0,0},temp=0;
    for(int i=0;i<5;i++)
        scanf("%d",&number[i]);
    for(int e=0;e<5;e++)
    {
        for(int j=e+1;j<5;j++)
        {
            if(number[e]>number[j])
            {
                temp=number[e];
                number[e]=number[j];
                number[j]=temp;
            }

        }
    }
    for(int n=0;n<5;n++)
    printf("%d\n",number[n]);
}
