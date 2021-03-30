#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double log1(double n,double b);
int main()
{
    double n;
    double b=0.001,ans;
    printf("Enter the value of n\t");
    scanf("%lf",&n);
    printf("%lf",log1(n,b));
    return 0;
}
double log1(double n,double b)
{
    if(pow(2,b)>=n)
        return b;
    return log1(n,b+0.001);
}
