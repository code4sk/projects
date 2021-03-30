#include <iostream>
#include<cstring>
#include <string.h>
using namespace std;
class fact
{
public:
    char *info;
public:
    fact (){}
    fact(char *arr)
    {
            info=arr;
    }
     friend fact operator+(fact a,fact b);
};
fact operator+(fact a,fact b)
     {
         fact c ;
         c.info=new char[30];
         strcpy(c.info,a.info);
         strcat(c.info," ");
         strcat(c.info,b.info);
         return c;
     }
int main()
{
    char *p="SHUBHAM",*q="KAPOOR";
    fact a(p),b(q),c;
    c=a+b;
    cout<<a.info<<" + "<<b.info<<" = "<<c.info;
    return 0;
}
