#include <stdio.h>
#include <stdlib.h>
int ans=0;
void mul(int a,int b);
int main()
{
    int a,b;
    printf("Enter two number a and b\t");
    scanf("%d%d",&a,&b);
    mul(a,b);
    printf("%d",ans);
    return 0;
}
void mul(int a,int b)
{
    if(a==1)
    {
        ans=ans+b;
        return;
    }
    mul(a/2,b*2);
    if(a%2!=0)
        ans=ans+b;
}
