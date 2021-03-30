#include <stdio.h>
#include <stdlib.h>

unsigned int x=0;
void b(int n);
void packCharacter(unsigned int x,char a,char b,char c,char d);
void unpacdCharacter(unsigned int x);
int main()
{
    char a,b,c,d;
    printf("Enter four characters\n");
    scanf("%c%c%c%c",&a,&b,&c,&d);
    packCharacter(x,a,b,c,d);
    unpackCharacter(x);
    return 0;
}
void packCharacter(unsigned int x,char a,char b,char c,char d)
{
    x=a;
    x=x<<8;
    x=x|b;
    x=x<<8;
    x=x|c;
    x=x<<8;
    x=x|d;
}
void unpackCharacter(unsigned int x)
{
    unsigned d=4278190080;
    char r='\0',s='\0',t='\0',u='\0';
    r=r|((d&x)>>8);
    printf("%c",r);
    d=16711680;
    s=s|(d&x)>>8;
    printf("%c",s);
    d=65280;
    t=t|(d&x)>>8;
    printf("%c",t);
    d=255;
    u=u|(d&x)>>8;
    printf("%c",u);
}
void b(int n)
{
    int k;
    if(n<=0)
        return;
    k=n%2;
    b(n/2);
    printf("%d",k);
}
