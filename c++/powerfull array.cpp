#include <bits/stdc++.h>
#define ll long long int
#define SIZE 2000001

using namespace std;

struct tri{
    int l, r, index;
};

int B;

bool comparator(tri a, tri b){
    if(a.l/B < b.l/B){
        return true;
    } else if(a.l/B > b.l/B){
        return false;
    }
    if(a.r < b.r){
        return true;
    } else {
        return false;
    }
}

int main() {
    int n, t;
    int arr[SIZE] = {0};
    scanf("%d%d", &n, &t);
    B = sqrt(n);
    for(int i=1;i<=n;i++){
        scanf("%d", &arr[i]);
    }
    vector<tri> Q;
    for(int i=0;i<t;i++){
        int l, r;
        scanf("%d%d", &l, &r);
        Q.push_back({l, r, i});
    }
    sort(Q.begin(), Q.end(), comparator);
    ll ans[SIZE] = {0};
    int start = Q[0].l, end = Q[0].l;
    int count[SIZE] = {0};
    count[arr[start]]++;
    ll val = (ll)count[arr[start]]*count[arr[start]]*arr[start];
    // val += count[arr[end]]*count[arr[end]]*arr[end];
    for(int i=0;i<Q.size();i++){
        int l = Q[i].l, r = Q[i].r;
        while(start != l){
            if(start < l){
                val -= (ll)count[arr[start]]*count[arr[start]]*arr[start];
                count[arr[start]]--;
                val += (ll)count[arr[start]]*count[arr[start]]*arr[start];
                start++;
            } else {
                start--;
                val -= (ll)count[arr[start]]*count[arr[start]]*arr[start];
                count[arr[start]]++;
                val += (ll)count[arr[start]]*count[arr[start]]*arr[start];
            }
        }
        while(end != r){
            if(end < r){
                end++;
                val -= (ll)count[arr[end]]*count[arr[end]]*arr[end];
                count[arr[end]]++;
                val += (ll)count[arr[end]]*count[arr[end]]*arr[end];
            } else {
                val -= (ll)count[arr[end]]*count[arr[end]]*arr[end];
                count[arr[end]]--;
                val += (ll)count[arr[end]]*count[arr[end]]*arr[end];
                end--;
            }
        }
        ans[Q[i].index] = val;
    }
    for(int i=0;i<t;i++){
        cout<<ans[i]<<endl;
    }
}
