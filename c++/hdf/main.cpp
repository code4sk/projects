#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int arr[60002]={0},maax=10000,c=0,p=0,a=0;
    int n=30000;
    //cout<<6*n<<endl;
    p=6*n;
    for(int i=2;i*i<=(p);i++)
	    {
	        if(arr[i]==0)
	        {
	            int j=(i*i);
	            for(;j <= p;j += i)
	            arr[j]=1;
	        }
	    }
    for(int i=2;i<=p;i++)
	    {
	        if(arr[i]==0)
            {
                c++;
                if(c==maax)
                {
                    a=i;
                    break;
                }
            }
	    }
    cout<<maax<<ends<<c<<ends<<a<<endl;
    return 0;
}
