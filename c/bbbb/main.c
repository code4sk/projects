#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b;
    cin>>a>>b;
    try
    {
        if(b!=0)
            cout<<float(a)/b;
        else
            throw 0;
    }
    catch
    {
        cout<<"Exception is caught:DIVIDE BY 0";
    }
    return 0;
}
