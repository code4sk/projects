#include <stdio.h>
#include <stdlib.h>

int n1;
void tri(int n);
int main()
{
    printf("Enter the value of n\t");
    scanf("%d",&n1);
    tri(n1);
    return 0;
}
void tri(int n)
{
    if(n==0)
    {
      n=n1;
      return;
    }
    else
    {
    tri(n-1);
    printf("*");
    }
}
