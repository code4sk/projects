#include <iostream>
using namespace std;
int find(int arr[],int n,int sum);
int main()
{
    int arr[10]={3,5,7,1,75,2,45,23,64,13},sum;
    cout<<"Enter the value of sum"<<endl;
    cin>>sum;
    if(find(arr,10,sum))
        cout<<"Subset is present with sum="<<sum;
    else
        cout<<"Subset is not present with sum="<<sum;
    return 0;
}
int find(int arr[],int n,int sum)
{
    if(sum==0)
        return 1;
    if(n==0&&sum!=0)
        return 0;
    if(arr[n]>sum)
        return find(arr,n-1,sum);
    else
        return find(arr,n-1,sum)||find(arr,n-1,sum-arr[n]);
}
