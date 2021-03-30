#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
void main()
{
int base,i,ans=1,power;
scanf("%d%d",&base,&power);
fflush(stdin);
for(i=1;i<=power;++i)
{
    ans=base*ans;
}
printf("%d",ans);
}

