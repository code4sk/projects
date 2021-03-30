#include <stdio.h>
#include <stdlib.h>

main()
{
    int num[5]={0,0,0,0,0},total[5]={0,0,0,0,0};
    for(int i=0;i<=4;i++)
    scanf("%d",&num[i]);
    for(int j=0;j<=4;j++)
    {
        for(int n=0;n<=4;n++)
        {
            if(num[j]>num[n])
                total[j]++;
        }
    }
    //printf("%d%d%d%d%d",total[0],total[1],total[2],total[3],total[4]);
    puts("");
    for(int e=0;e<=4;e++)
    {
        if(total[e]==4)
            printf("%d\n",total[e]);
    }
    for(int m=0;m<=4;m++)
    {
        if(total[m]==3)
            printf("%d\n",total[m]);
    }
    for(int k=0;k<=4;k++)
    {
        if(total[k]==2)
            printf("%d\n",total[k]);
    }
    for(int h=0;h<=4;h++)
    {
        if(total[h]==1)
            printf("%d\n",total[h]);
    }
    for(int y=0;y<=4;y++)
    {
        if(total[y]==0)
            printf("%d\n",total[y]);
    }
}
