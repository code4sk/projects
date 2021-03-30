#include <bits/stdc++.h>

using namespace std;

struct block{
    int value = 0;
    int prefix = 0;
    int suffix = 0;
};

void traverse(int BLOCK[], int BLOCK_SIZE){
    for(int i=1;i<=BLOCK_SIZE;i++){
        cout<<BLOCK[i]<<"\t";
    }
    cout<<endl;
}

int main()
{
    int arr[] = {-1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1};
    int n = sizeof(arr)/sizeof(int) - 1;
    int BLOCK[2000];
    int BLOCK_SIZE = sqrt(n);
    int bptr = 1;
    for(int i=1;i<=n;i++){
        BLOCK[bptr] += arr[i];
        if(i%BLOCK_SIZE == 0){
            bptr++;
        }
    }
    traverse(BLOCK, BLOCK_SIZE);
    int l = 2, r =  6;
    int ans = 0;
    int lb = (l/BLOCK_SIZE), rb = (r/BLOCK_SIZE);
    int a = lb + 1, b = rb - 1;
    while(a <= b){
        ans += BLOCK[a];
        a++;
    }
    if(lb != rb){
        for(int i=l;i<lb*BLOCK_SIZE;i++){
            ans += arr[i];
        }
        for(int i=(rb-1)*BLOCK_SIZE;i<=r;i++){
            ans += arr[i];
        }
    } else {
        for(int i=l;i<=r;i++){
            ans += arr[i];
        }
    }
    cout<<ans<<endl;
    return 0;
}
