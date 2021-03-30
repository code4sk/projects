#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num=0;
    for(int i=0;i<5;i++)
    {
        for(int j=i;j<5;j++)
        {
            printf(" ");
           num++;
        }
        if(num==5)
        {
            printf("/|\n");
            //printf("%d",num);
            num=0;
            continue;
        }
            if(num==4)
            {
                printf("/*|");
                printf("\n");
               // printf("%d",num);
                num=0;
                continue;
            }
            if(num==3)
            {
                printf("/**|");
                printf("\n");
                //printf("%d",num);
                num=0;
                continue;
            }
            if(num==2)
            {
                printf("/***|");
                printf("\n");
                num=0;
                continue;
            }
            if(num==1)
            {
                printf("/****|");
                printf("\n");
                num=0;
                continue;
            }
             if(num==0)
            {
                printf("/*****|");
                printf("\n");
                num=0;
                continue;
            }
    }
    printf("/_____|");
    return 0;
}
