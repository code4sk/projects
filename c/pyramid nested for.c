#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j;
    scanf("%d",&n);
       fflush(stdin);
    for(i=1;i<=n;++i)
    {
        puts("");
        for(j=1;j<=i;++j)
        {
            printf("%d",i);
        }

    }
    return 0;
}
