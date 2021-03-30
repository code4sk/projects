#include <stdio.h>
#include <stdlib.h>
int pow1(int a,int b);
int ans;
int main()
{
    int a,b;
    printf("Enter the value of a and b\t");
    scanf("%d%d",&a,&b);
    ans=1;
    ans=pow1(a,b);
    printf("%d",ans);
    return 0;
}
int pow1(int a,int b)
{
        if(b==0)
            return 1;
    if(b%2==0)
    {
    return pow1(a*a,b/2);
    }
    if(b%2!=0)
    {
        return a*pow1(a*a,(b-1)/2);

    }
}
