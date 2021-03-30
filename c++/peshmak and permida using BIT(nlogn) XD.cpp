#include <bits/stdc++.h>
#define SIZE 6000001
#define small_size 2000001
#define ll long long int

using namespace std;


ll update(ll seg[], int start, int end, int index, int pos){
    if(pos > end || pos < start){
        return seg[index];
    }
    if(pos == start && pos == end){
        seg[index] += 1;
        // cout<<"ok";
        return seg[index];
    }
    int mid = (start + end)/2;
    seg[index] = update(seg, start, mid, 2*index+1, pos) + update(seg, mid+1, end, 2*index+2, pos);
    return seg[index];
}


ll findValue(ll seg[], int start, int end, int l, int r, int index){
    if(l > end || r < start){
        return 0;
    }
    if(l <= start && r >= end){
        // cout<<"sk";
        return seg[index];
    }
    int mid = (start + end)/2;
    return findValue(seg, start, mid, l, r, 2*index+1) + findValue(seg, mid + 1, end, l, r, 2*index+2);
}

void traverse(ll seg[], int start, int end, int index){
    printf("%d %d -> %d\n", start, end, seg[index]);
    if(start == end){
        return;
    }
    int mid = (start + end)/2;
    traverse(seg, start, mid, 2*index+1);
    traverse(seg, mid+1, end, 2*index+2);
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[small_size];
    vector<pair<int, int>> v;
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
        v.push_back({arr[i], i});
    }
    ll seg[SIZE] = {0};
    ll count[small_size] = {0};
    int newArr[small_size];
    sort(v.begin(), v.end());
    int ctr = 1;
    newArr[v[0].second] = 1;
    for(int i=1;i<n;i++){
        if(v[i-1].first == v[i].first){
            newArr[v[i].second] = ctr;
        } else {
            newArr[v[i].second] = ++ctr;
        }
    }
    int one[small_size], two[small_size];
    for(int i=0;i<n;i++){ 
        count[newArr[i]]++;
        one[i] = count[newArr[i]];
        
    }
    memset(count, 0, small_size*sizeof(int));
    for(int i=n-1;i>=0;i--){
        count[newArr[i]]++;
        two[i] = count[newArr[i]];
    }
    ll ans = 0;
    for(int i=n-1;i>=1;i--){
        // cout<<"ds"<<two[i]<<endl;
        update(seg, 0, n-1, 0, two[i]);
        // traverse(seg, 0, n-1, 0);
        // cout<<endl;
        ans += findValue(seg, 0, n-1, 0, one[i - 1]-1, 0);
        // cout<<findValue(seg, 0, n-1, 0, one[i - 1]-1, 0)
    }
    // for(int i=0;i<n;i++){
    //     cout<<two[i]<<" ";
    // }
    // traverse(seg, 0, n-1, 0);
    cout<<ans<<endl;
}
