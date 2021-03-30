#include <stdio.h>
#include <stdlib.h>
int n;
int ans=1;
int i=0;
int fib(int a,int b);
int main()
{
    int a=1,b=1;
    printf("Enter the value of n\t");
    scanf("%d",&n);
    printf("%d\t%d",ans,fib(a,b));
    return 0;
}
int fib(int a,int b)
{
    ans=ans+b;
    if(i<n-2)
    {
        i++;
        return fib(b,a+b);
    }
    else
        return b;

}
