#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,sum=0;
    puts("enter any number");
    scanf("%d",&n);
    for(int i=1;i<n;++i)     /*in perfect number sum of its factors(excluding itself) is equal to that number*/
    {
      if(n%i==0)
      {
          sum=sum+i;
      }
    }
    if(sum==n)
    {
        puts("given number is a perfect number");
    }
    else
    {
        puts("given number is not a perfect number ");
    }
    return 0;
}
