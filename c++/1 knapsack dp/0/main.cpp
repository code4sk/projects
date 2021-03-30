#include <iostream>

using namespace std;

int weight[] = {0, 1, 2, 3}, value[] = {0, 60, 100, 120}, w = 5, n = 3, arr[10][10]={0};

int main()
{
    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++){
            if(weight[i]>j){
                arr[i][j] = arr[i-1][j];
            }
            else{
                arr[i][j] = max(value[i] + arr[i-1][j - weight[i]], arr[i-1][j]);
            }
        }
    }
    //cout<<arr[n-1][w-1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=w;j++){
            cout<<arr[i][j]<<"\t";
        }
        cout<<endl;
    }
    return 0;
}
