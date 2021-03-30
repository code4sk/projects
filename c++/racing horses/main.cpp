#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
int diff(int horse[]);
int N;
int main()
{
    int T,horse[2000];
    cin>>T;
    while(T--)
    {
        cin>>N;
        for(int i=0;i<N;i++)
            cin>>horse[i];
        cout<<diff(horse)<<endl;
    }
    return 0;
}
int diff(int horse[])
{
    int min1=-1,min2=-1;
    for(int i=0;i<N;i++)
    {
        if(horse[i]<min1||min1==-1)
            min1=horse[i];
        else if(horse[i]<min2||min2==-1)
            min2=horse[i];
    }
    return (min2-min1);
}
