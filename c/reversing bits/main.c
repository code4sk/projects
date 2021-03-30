#include <stdio.h>
#include <stdlib.h>

void b(int n);
void breverse(int n);
int main()
{
    int n;
    printf("Enter the number\t");
    scanf("%d",&n);
    printf("\tBinary value of %d\t",n);
    b(n);
    printf("\n\nReverse of Binary value of %d\t",n);
    breverse(n);
    return 0;
}
void b(int n)
{
    int k;
    if(n<=0)
        return;
    k=n%2;
    breverse(n/2);
    printf("%d",k);
}
void breverse(int n)
{
    int k;
    if(n<=0)
        return;
    k=n%2;
    printf("%d",k);
    breverse(n/2);
}
