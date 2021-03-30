#include <iostream>
#include <cmath>

using namespace std;

int metaBinarySearch(int arr[], int n, int key){
    int pos = 0;
    int lg = log2(n-1) + 1;
    for(int i=lg;i>=0;i--){
        int index = pos^(1<<i);
        if(arr[index] == key){
            pos = index;
            break;
        }
        if(arr[index] < key){
            pos = index;
        } else {

        }
    }

    return (arr[pos] == key)?pos:-1;
}

int main()
{
    int arr[] = {3, 5, 7, 8, 20, 32, 33, 55, 70};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<metaBinarySearch(arr, n, 0);
    return 0;
}
