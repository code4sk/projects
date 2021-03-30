#include <stdio.h>
#include <stdlib.h>

void tofh(n,a,b,c);
int main()
{
    int n;
    printf("Enter the value of n\n");
    scanf("%d",&n);
    tofh(n,'a','b','c');
    return 0;
}
void tofh(n,a,b,c)
{
    if(n==1)
    {
        printf("%c->%c\n",a,c);
        return;
    }
    tofh(n-1,a,c,b);
    printf("%c->%c\n",a,c);
    tofh(n-1,b,a,c);
}
