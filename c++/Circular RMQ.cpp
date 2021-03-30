#include <bits/stdc++.h>
#define ll long long int
#define SIZE 505001

using namespace std;

struct node{
    ll value = 0;
};

node constructSegTree(node seg[], int start, int end, int index, vector<ll> &arr){
    if(start == end){
        seg[index].value = arr[start];
        return seg[index];
    }
    int mid = (start + end)/2;
    node val1 = constructSegTree(seg, start, mid, 2*index+1, arr);
    node val2 = constructSegTree(seg, mid+1, end, 2*index+2, arr);
    seg[index].value = min(val1.value, val2.value);
    return seg[index];
}

ll findValue(node seg[], int start, int end, int l, int r, int index, node lazy[]){
    if(lazy[index].value != 0){
        seg[index].value += lazy[index].value;
        if(end != start){
            lazy[2*index+1].value += lazy[index].value;
            lazy[2*index+2].value += lazy[index].value;
        }
        lazy[index].value = 0;
    }
    if(l > end || r < start){
        return INT_MAX;
    }
    if(l <= start && r >= end){
        return seg[index].value;
    }
    int mid = (start + end)/2;
    return min(findValue(seg, start, mid, l, r, 2*index+1, lazy), findValue(seg, mid+1, end, l, r, 2*index+2, lazy));
}

ll update(node seg[], int start, int end, int l, int r, int index, node lazy[], int v){
    if(lazy[index].value != 0){
        seg[index].value += lazy[index].value;
        if(end != start){
            lazy[2*index+1].value += lazy[index].value;
            lazy[2*index+2].value += lazy[index].value;
        }
        lazy[index].value = 0;
    }
    if(l > end || r < start){
        return seg[index].value;
    }
    if(l <= start && r >= end){
        seg[index].value += v;
        if(end != start){
            lazy[2*index+1].value += v;
            lazy[2*index+2].value += v;
        }
        return seg[index].value;
    }
    int mid = (start + end)/2;
    seg[index].value = min(update(seg, start, mid, l, r, 2*index+1, lazy, v), update(seg, mid+1, end, l, r, 2*index+2, lazy, v));
    return seg[index].value;
}

int takeInput(int *l, int *r, int *v){
    string str;
    getline(cin, str);
    int space = 0;
    for(int j=0;j<str.length();j++){
        if(str[j] == ' '){
            space++;
        }
    }
    
    if(space == 1){
        auto pos = str.find(' ');
        *l = atoi(str.substr(0, pos).c_str());
        *r = atoi(str.substr(pos+1, str.length()).c_str());
        // cout<<" "<<*l<<" "<<*r<<endl;
    } else {
        auto pos = str.find(' ');
        *l = atoi(str.substr(0, pos).c_str());
        string temp = str.substr(pos+1, str.length());
        auto newPos = temp.find(' ');
        *r = atoi(temp.substr(0, newPos).c_str());
        *v = atoi(temp.substr(newPos+1, temp.length()).c_str());
        // cout<<" "<<*l<<" "<<*r<<" "<<*v<<endl;
    }
    return space;
}

void buildMinSegTree(vector <int> arr, node seg[], int n)
{
    int i;
	for(i=n;i<2*n;i++)
	seg[i].value=arr[i-n];
	for(i=n-1;i>=0;i--)
	seg[i].value=min(seg[2*i+1].value,seg[2*i+2].value);
}

int main() {
    int n;
    scanf("%d", &n);
    vector<ll> arr;
    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        arr.push_back(x);
    }
    node seg[SIZE];
    node lazy[SIZE];
    constructSegTree(seg, 0, n-1, 0, arr);
    // buildMinSegTree(arr, seg, n);
    int m;
    scanf("%d", &m);
    getchar();
    for(int i=0;i<m;i++){
        int l, r, v;
        if(takeInput(&l, &r, &v) == 1){
            ll ans;
            if(l > r){
                ans = min(findValue(seg, 0, n-1, 0, r, 0, lazy), findValue(seg, 0, n-1, l, n-1, 0, lazy));
            } else {
                ans = findValue(seg, 0, n-1, l, r, 0, lazy);
            }
            cout<<ans<<endl;
        } else {
            if(l > r){
                update(seg, 0, n-1, 0, r, 0, lazy, v);
                update(seg, 0, n-1, l, n-1, 0, lazy, v);
            } else {
                update(seg, 0, n-1, l, r, 0, lazy, v);
            }
        }
    }
}
