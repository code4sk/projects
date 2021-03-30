#include <stdio.h>
#include <stdlib.h>
float exp(float ,int);
int main()
{
    float a,ans;
    int b;
    printf("Enter a and b\t");
    scanf("%f%d",&a,&b);
    ans=exp(a,b);
    printf("a^b=%f",ans);
    return 0;
}
float exp(float a,int b)
{
    float ans;
    if(b==0)
        ans=1;
    else
    ans=a*exp(a,b-1);
    return ans;
}
