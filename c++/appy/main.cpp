#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void rshift(vector <int> v,int n);
int check(vector <int> v,int n,int k);
int main()
{
    int n,q,k,x;
    vector <int> v{0};
    char y;
    scanf("%d%d%d",&n,&q,&k);
    for(int i=1;i<=n;i++)
    scanf("%d",&v[i]);
    y=getchar();
    for(int i=1;i<=q;i++)
    {
        y=getchar();
        switch(y)
        {
            case '!' : rshift(v,n);
                       cout<<endl;
                       for(int i=1;i<=n;i++)
                       cout<<v[i]<<ends<<ends;
            break;
            case '?' : printf("%d\n",check(v,n,k));
            break;
        }
    }
    return 0;
}
void rshift(vector <int> v,int n)
{
    int a,k;
    a=v[n];
    for(int i=n-1;i>=1;i--)
    v[i+1]=v[i];
    v[1]=a;
}
int check(vector <int> v,int n,int k)
{
    int l=0,m=0;
    for(int i=1;i<=n;i++)
    {
        if(v[i]==1)
        {
            if(l<k)
            l++;
            else
            return k;
        }
        else
        {
            if(m<l)
            m=l;
            l=0;
        }
    }
    if(m>l)
    l=m;
    return l;
}
