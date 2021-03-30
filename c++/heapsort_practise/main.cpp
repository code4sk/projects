#include <iostream>

using namespace std;

void display(int arr[], int n);

void heapify(int arr[], int n);

void unheapify(int arr[], int n);

void restore_up(int i, int arr[], int n);

void restore_down(int i, int arr[], int n);


int main()
{
    //int arr[] = {9999999, 234, 64, 652, 123, 264, 23, 8, 43}, n = 8;
    int arr[] = {9999999,1,2,3,4,5,6,7,8}, n = 8;
    heapify(arr, n);
    unheapify(arr, n);
    display(arr, n);
    return 0;
}

void heapify(int arr[], int n){
    for(int i=n;i>=1;i--){
        restore_up(i, arr, n);
    }
}

void unheapify(int arr[], int n){
    int temp;
    for(int i=n;i>2;i--){
        temp = arr[1];
        arr[1] = arr[i];
        arr[i] = temp;
        restore_down(1, arr, i-1);
    }
    temp = arr[1];
    arr[1] = arr[2];
    arr[2] = temp;
}

void restore_up(int i, int arr[], int n){
    int k = i/2, temp;
    while(arr[k]<arr[i]){
        temp = arr[k];
        arr[k] = arr[i];
        arr[i] = temp;
        i = k;
        k = k/2;
    }
}

void restore_down(int i, int arr[], int n){
    int k = i*2, temp;
    if(k + 1 > n)
        return;
    while(arr[i] < arr[k] || arr[i] < arr[k+1]){
        if(arr[i] < arr[k] && arr[k] >= arr[k+1]){
            temp = arr[i];
            arr[i] = arr[k];
            arr[k] = temp;
            i = k;
            k = k*2;
        }
        else if(arr[i] < arr[k + 1]){
            temp = arr[i];
            arr[i] = arr[k + 1];
            arr[k + 1] = temp;
            i = k + 1;
            k = (k + 1)*2;
        }
        if(k >= n )
            break;
    }
}

void display(int arr[], int n){
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<"\t";
    }
}
