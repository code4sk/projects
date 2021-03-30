#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    char str[21];
    int a,b,c;
    puts("enter the cofficient of x^2");
    scanf("%d",&a);
    puts("enter the cofficient of x");
    scanf("%d",&b);
    puts("enter the constant");
    scanf("%d",&c);
    calc(a,b,c);
    return 0;
}
calc(int a,int b,int c)
{
    double ans1,ans2,k,l,m,n,o;
    int d;
    if((b*b-4*a*c)>0){
            n=2*a;
    d=(b*b-4*a*c);
    m=sqrt(d);
    l=(-b+m);
    ans1=l/n;
       o=(-b-m);
    ans2=o/n;
    printf("\nroots are %lf %lf",ans1,ans2);
        }
        else
        {
            puts("no real roots");
        }
}
