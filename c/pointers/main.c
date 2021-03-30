#include <stdio.h>
#include <stdlib.h>

void main()
{
    int num[5]={0,0,0,0,0},nm[5]={0,0,0,0,0};
    for(int i=0;i<5;i++)
    {
        scanf("%d",&num[i]);
    }
        for(int j=0;j<=4;j++)
    {
        for(int n=0;n<=4;n++)
        {
            if(num[j]>num[n])
                nm[j]++;
        }
    }
    for(int e=0;e<=4;e++)
    if(nm[e]==e)
        printf("%d",nm[e]);
}

