#include <bits/stdc++.h>
#define ll long long int
#define SIZE 30001

using namespace std;

struct node{
    int value = 0;
    int prefix = 0;
    int suffix = 0;
    int flag = 0;
};

node newNull;


node constructSegTree(node seg[], int start, int end, int index, int B[]){
    if(start == end){
        seg[index].value = B[start];
        seg[index].prefix = B[start];
        seg[index].suffix = B[start];
        seg[index].flag = B[start];
        return seg[index];
    }
    int mid = (start + end)/2;
    node val1 = constructSegTree(seg, start, mid, 2*index+1, B);
    node val2 = constructSegTree(seg, mid+1, end, 2*index+2, B);
    seg[index].value = max({val1.value, val2.value, val1.suffix + val2.prefix});
    seg[index].suffix = val2.suffix;
    seg[index].prefix = val1.prefix;
    if(val1.flag == 1 && val2.flag == 1){
        seg[index].suffix = seg[index].value;
        seg[index].prefix = seg[index].value;
        seg[index].flag = 1;
    } else if(val1.flag == 1 && val2.flag == 0){
        seg[index].prefix = val1.prefix + val2.prefix;
    } else if(val1.flag == 0 && val2.flag == 1){
        seg[index].suffix = val1.suffix + val2.suffix;
    }
    return seg[index];
}

node findValue(node seg[], int start, int end, int l, int r, int index, int *ans){
    if(l > end || r < start){
        return newNull;
    }
    if(l >= start && r <= end){
        return seg[index];
    }
    int mid = (start + end)/2;
    node val1 = findValue(seg, start, mid, l, r, 2*index+1, ans);
    node val2 = findValue(seg, mid+1, end, l, r, 2*index+2, ans);
    if(val1.value == -1){
        *ans = max(*ans, val2.value);
        return val2;
    } else if(val2.value == -1){
        *ans = max(*ans, val1.value);
        return val1;
    }
    *ans =  max({*ans, val1.value, val2.value, val1.suffix + val2.prefix});
    return seg[index];
}

int main() {
    newNull.value = -1;
    int n, q, k;
    scanf("%d%d%d", &n, &q, &k);
    int arr[SIZE]={0};
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    int B[SIZE];
    for(int i=0;i<2*n;i++){
        B[i] = arr[i%n];
    }
    node seg[SIZE];
    constructSegTree(seg, 0, n-1, 0, B);
    vector <pair<int, int>> v;
    for(int i=0;i<n;i++){
        v.push_back({i, i + n-1});
    }
    int z = 0;
    while(q--){
        char ch;
        cin>>ch;
        if(ch == '!'){
            z = (z+1)%n;
        } else {
            int val = 0;
            findValue(seg, 0, n-1, v[z].first, v[z].second, 0, &val);
            cout<<min(val, k)<<endl;
        }
    }
}
