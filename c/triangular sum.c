#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
void main()
{
int num,i;
char sk='y';
scanf("%d",&num);
fflush(stdin);
for(i=2;i<num;++i)
{
    if(num%i==0)
    {
        sk='n';
       // puts("composite number");
        break;
    }
    if(sk='y')
    {
        puts("prime number");
    }

}

}

