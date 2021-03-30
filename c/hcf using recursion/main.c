#include <stdio.h>
#include <stdlib.h>

int hcf(int a,int b);
int main()
{
    int a,b;
    printf("Enter two number a and b\t");
    scanf("%d%d",&a,&b);
    printf("hcf=%d",hcf(a,b));
    return 0;
}
int hcf(int a,int b)
{
    if(b==0)
        return a;

        return hcf(b,a%b);
}
