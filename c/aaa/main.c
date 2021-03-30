#include <stdio.h>
#include <stdlib.h>

int pow(int a,int b);
int count=100;
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d",pow(a,b));
    return 0;
}
int pow(int a,int b)
{
    if(b==0)
        return 1;
    if(b%2==0)
        return pow(a*a,b/2);
    if(b%2!=0)
        return a*pow(a*a,(b-1)/2);
}
