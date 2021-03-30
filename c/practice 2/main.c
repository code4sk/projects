#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pow1(int a,int n);
int main()
{
    int a,n;
    printf("Enter the value of a\n");
    scanf("%d",&a);
    printf("Enter the value of n\n");
    scanf("%d",&n);
    printf("%d",pow1(a,n));
    return 0;
}
int pow1(int a,int n)
{
    if(n==0)
        return 1;
    if(n%2==0)
        return pow1(a*a,n/2);
    else
        return a*pow1(a*a,(n-1)/2);
}
