#include <stdio.h>
#include <stdlib.h>
int prime(int n,int p);
int main()
{
    int a,b,k;
    printf("Enter two number\n");
    scanf("%d%d",&a,&b);
    k=prime(a,b);
    printf("%d",k);
    return 0;
}
int prime(int a,int b)
{
    if(b==0)
        return a;
    return prime(b,a%b);

}
