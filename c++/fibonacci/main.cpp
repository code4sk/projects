#include <iostream>

int i=0;
int sum=0;
using namespace std;
void fib(int n,int a,int b);
int main()
{
    int n;
    cin>>n;
    fib(n,1,1);
    cout<<endl<<sum;
    return 0;
}
void fib(int n,int a,int b)
{
   if(i==n)
    return;
    cout<<a<<ends;
    sum+=a;
    i++;
   fib(n,b,a+b);
}
