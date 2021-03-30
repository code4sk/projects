#include <stdio.h>
#include <stdlib.h>
void prime(int n);
int main()
{
    int n;
    printf("Enter the number\n");
    scanf("%d",&n);
    prime(n);
    printf("\b=%d",n);
    return 0;
}
void prime(int n)
{
    int i=2;
    if(n==1)
        return;
    while(n%i!=0)
        i++;
    printf("%d*",i);
    prime(n/i);
    return;
}
