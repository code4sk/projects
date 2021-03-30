#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
string str;
unsigned int x=0;
void b(int n);
void packCharacter(unsigned int x,char a,char b,char c,char d);
void displayBits(unsigned int n);
//void unpacdCharacter(unsigned int x);
int main()
{
    char a,b,c,d;
    printf("Enter four characters\n");
    a=getchar();
    b=getchar();
    c=getchar();
    d=getchar();
    packCharacter(x,a,b,c,d);
    displayBits(a);
    reverse(str.begin(),str.end());
    cout<<str;
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
void displayBits(unsigned int n)
{
    unsigned int mask=1<<31;
        str=' ';
        int i=1;
        while(i<=32)
        {
            if(n&mask)
                str=str+'1';
                else
                    str=str+'0';
                n<<=1;
                i++;
        }
}
