#include <iostream>

using namespace std;

int n = 4;

int nQueen(int arr[][4], int col);

int isQueenSafe(int arr[][4], int i, int col);

int main()
{
    int arr[4][4];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            arr[i][j] = 0;
        }
    }
    if(nQueen(arr, 0)){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else{
        cout<<"Solution not found\n";
    }
    return 0;
}

int nQueen(int arr[4][4], int col){
    if(col>=n)
        return 1;
    for(int i=0;i<n;i++){
        if(isQueenSafe(arr, i, col)){
                arr[i][col] = 1;
            if(nQueen(arr, col+1))
                return 1;
        }
        arr[i][col] = 0;
    }
    return 0;
}

int isQueenSafe(int arr[4][4], int i, int col){
    for(int l=0;l<col;l++){
        if(arr[i][l] == 1)
            return 0;
    }
    for(int l=i, j=col; l>=0 && j>=0; l--, j--){
        if(arr[l][j] == 1)
            return 0;
    }
    for(int l=i, j=col;l<n && j>=0;l++, j--){
        if(arr[l][j] == 1)
            return 0;
    }
    return 1;
}
