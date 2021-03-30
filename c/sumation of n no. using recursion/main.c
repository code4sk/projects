#include <stdio.h>
#include <stdlib.h>
int sum(int n);
int main()
{
    int n,ans;
    printf("Enter the value of n\t");
    scanf("%d",&n);
    ans=sum(n);
    printf("\nsummation of n=%d",ans);
    return 0;
}
int sum(int n)
{
    int ans;
    if(n==0)
        ans=0;
    else
    ans=n+sum(n-1);
    return ans;
}
