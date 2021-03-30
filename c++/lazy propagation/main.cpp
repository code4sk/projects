#include <bits/stdc++.h>
#define ll long long int
#define SIZE 10001

using namespace std;

int constructSegTree(int seg[], int start, int end, int index, int arr[]){
    if(start == end){
        seg[index] = arr[start];
        return seg[index];
    }
    int mid = (start + end)/2;
    int val1 = constructSegTree(seg, start, mid, 2*index+1, arr),
     val2 = constructSegTree(seg, mid+1, end, 2*index+2, arr);
    seg[index] = val1 + val2;
    return seg[index];
}

void traverse(int seg[], int start, int end, int index){
    printf("%d %d (%d)\n", start, end, seg[index]);
    if(start == end){
        return;
    }
    int mid = (start + end)/2;
    traverse(seg, start, mid, 2*index+1);
    traverse(seg, mid+1, end, 2*index+2);
}

int update(int seg[], int start, int end, int l, int r, int index, int lazy[], int inc){
    if(lazy[index] != 0){
        seg[index] += lazy[index];
        lazy[2*index+1] += lazy[index];
        lazy[2*index+2] += lazy[index];
        lazy[index] = 0;
    }
    if(l > end || r < start){
        return seg[index];
    }
    if(l <= start && r >= end){
        seg[index] += inc;
        lazy[2*index+1] += inc;
        lazy[2*index+2] += inc;
        return seg[index];
    }
    int mid = (start + end)/2;
    int val1 = update(seg, start, mid, l, r, 2*index+1, lazy, inc),
     val2 = update(seg, mid+1, end, l, r, 2*index+2, lazy, inc);
    seg[index] = val1 + val2;
    return seg[index];
}

int main()
{
    int arr[] = {1, 5, 23, 6 ,3, 6, 10};
    int n = sizeof(arr)/sizeof(int);
    int seg[SIZE] = {0}, lazy[SIZE] = {0};
    constructSegTree(seg, 0, n-1, 0, arr);
    update(seg, 0, n-1, 1, 3, 0, lazy, 2);
    traverse(seg, 0, n-1, 0);
    update(seg, 0, n-1, 3, 3, 0, lazy, 2);
    cout<<endl;
    traverse(seg, 0, n-1, 0);
    cout<<endl;
    traverse(lazy, 0, n-1, 0);
    return 0;
}
