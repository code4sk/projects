#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m,z,n;
    scanf("%d%d",&m,&n);
    power(&m,&n);
    z=power(&m,&n);
    printf("answer is %d",z);
    return 0;
}
int power(int *p,int *q)
{
    int ans=1;
    for(int i=0;i<*q;i++)
    {
        ans=ans*(*p);
    }
    return ans;
}

