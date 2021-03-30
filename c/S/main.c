#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num,i,total=0,pos=0,neg=0,sum=0;
    for(i=1;i<=10;i++)
    {
        scanf("%d",&num);
        fflush(stdin);
        if(num==0)
            break;
        ++total;
        if(num>0)
            {++pos;
            sum=sum+num;}
        else
            ++neg;
    }
    printf("total number of entry are %d\n",total);
    printf("total number of positive entry:%d and negative entry:%d and sum of positive entries are %d \n",pos,neg,sum);
    return 0;
}
