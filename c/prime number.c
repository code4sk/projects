#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
void main()
{
int base,i,ans=0;
scanf("%d",&base);
fflush(stdin);
for(i=1;i<=base;++i)
{
    ans=base+ans;
}
printf("%d",ans);
}

