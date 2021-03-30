#include <stdio.h>
#include <stdlib.h>

int sum(int n);
int main()
{
    int n,ans;
    printf("Enter the number\t");
    scanf("%d",&n);
    ans=sum(n);
    printf("\b=%d",ans);
    return 0;
}
int sum(int n)
{
    int ans,temp,k;
    if(n<1)
    {
        ans=0;
        return ans;
    }
    else
    {
        temp=n%10;
        ans=temp+sum(n/10);
    }
    printf("%d+",temp);
    return ans;
}
