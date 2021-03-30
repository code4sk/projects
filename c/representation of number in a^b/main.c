#include <stdio.h>
#include <stdlib.h>

int rep(int n);
int prime(int n);
int main()
{
    int n;
    printf("Enter the number\t");
    scanf("%d",&n);
    printf("%d",rep(n));
    return 0;
}
int rep(int n)
{
    int i=0,ans=1;
    for(int j=2;j<n-1;j++)
    {
        ans=1;
       for(int k=0;k<n-1;k++)
       {
           ans=ans*j;
           if(ans==n)
            return 1;
            if(ans>n)
                break;
       }
    }
    return 0;
}
