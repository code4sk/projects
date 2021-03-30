#include <stdio.h>
#include <stdlib.h>

int fac(int n);
int tfac(int n,int result);
int main()
{
    int n,ans;
    printf("Enter value of n\t");
    scanf("%d",&n);
    ans=tfac(n,1);
    printf("%d!=%d",n,ans);
    return 0;
}
int fac(int n)
{
    if(n==0)
        return 1;
        return n*fac(n-1);
}
int tfac(int n,int result)
{
    if(n==0)
    return result;
    return tfac(n-1,n*result);
}
