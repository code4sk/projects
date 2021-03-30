#include <iostream>
#include <vector>
using namespace std;

struct tri
{
    int a,b,c;
};
int main()
{
    int n,count=0,x;
    cin>>n;
    vector <tri> v;
    //int arr[100][100]={0};
    v.push_back({n,n,0});
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>x;
            if(x!=0)
                v.push_back({j,i,x});
        }
    }
    /*int **str,k=0;
    str=new int*[count+1];
    for(int i=0;i<count+1;i++)
        str[i]= new int[3];
    str[k][0]=n;
    str[k][1]=n;
    str[k][2]=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i][j]!=0)
               {
                   str[++k][2]=arr[i][j];
                   str[k][0]=i;
                   str[k][1]=j;
               }
        }
    }
    for(int i=0;i<count+1;i++)
    {
        cout<<str[i][0]<<ends<<str[i][1]<<ends<<str[i][2]<<endl;
    }*/
    int l=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if((i==v[l].b)&&(j==v[l].a))
               cout<<v[l++].c<<" ";
            else
                cout<<0<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i=0;i<v.size();i++)
        cout<<v[i].a<<ends<<v[i].b<<ends<<v[i].c<<endl;
    return 0;
}
