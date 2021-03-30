#include <bits/stdc++.h>
#define SIZE 50001

using namespace std;

struct info{
    int l, r, index;
};

bool comparator(info a, info b){
    return a.r < b.r;
}

int update(int seg[], int start, int end, int index, int pos, int value){
    if(pos > end || pos < start){
        return seg[index];
    }
    if(pos == start && pos == end){
        seg[index] = value;
        return seg[index];
    }
    int mid = (start + end)/2;
    seg[index] = update(seg, start, mid, 2*index, pos, value) + update(seg, mid+1, end, 2*index+1, pos, value);
    return seg[index];
}

int findValue(int seg[], int start, int end, int l, int r, int index){
    if(l > end || r < start){
        return 0;
    }
    if(l <= start && r >= end){
        return seg[index];
    }
    int mid = (start + end)/2;
    return findValue(seg, start, mid, l, r, 2*index) + findValue(seg, mid+1, end, l, r, 2*index+1);
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[SIZE];
    int seg[SIZE] = {0};
    for(int i=1;i<=n;i++){
        scanf("%d", &arr[i]);
    }
    int q;
    scanf("%d", &q);
    vector<info> Q;
    Q.push_back({-1, -1, -1});
    for(int i=1;i<=q;i++){
        int l, r;
        scanf("%d%d", &l, &r);
        Q.push_back({l, r, i});
    }
    sort(Q.begin(), Q.end(), comparator);
    int ans[SIZE];
    int count[1000001] = {0};
    int qindex = 1;
    int flag = 0;
    for(int i=1;i<=n;i++){
        int val = count[arr[i]];
        if(val != 0){
            update(seg, 1, n, 1, val, 0);
        }
        update(seg, 1, n, 1, i, 1);
        count[arr[i]] = i;
        while(Q[qindex].r == i){
            ans[Q[qindex].index] = findValue(seg, 1, n, Q[qindex].l, Q[qindex].r, 1);
            qindex++;
            if(qindex == Q.size()){
                flag = 1;
                break;
            }
        }
        if(flag){
                break;
            }
    }
    for(int i=1;i<=q;i++){
        cout<<ans[i]<<endl;
    }
}
