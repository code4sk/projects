#include <bits/stdc++.h>
#define ll long long int
#define SIZE 1065398

using namespace std;

struct node{
    vector<int> v;
};

node constructSegTree(node seg[], int start, int end, int index, vector<int> arr){
    if(start == end){
        seg[index].v.push_back(arr[start]);
        return seg[index];
    }

    int mid = (start + end)/2;
    node val1 = constructSegTree(seg, start, mid, 2*index+1, arr);
    node val2 = constructSegTree(seg, mid+1, end, 2*index+2, arr);
    int i=0, j=0;
    while(i < val1.v.size() && j < val2.v.size()){
        if(val1.v[i] < val2.v[j]){
            seg[index].v.push_back(val1.v[i]);
            i++;
        } else {
            seg[index].v.push_back(val2.v[j]);
            j++;
        }
    }
    while(i < val1.v.size()){
        seg[index].v.push_back(val1.v[i]);
        i++;
    }
    while(j < val2.v.size()){
        seg[index].v.push_back(val2.v[j]);
        j++;
    }
    return seg[index];
}

void findValue(node seg[], int start, int end, int l, int r, int index, vector <node> &elect){
    if(l > end || r < start){
        return;
    }
    if(l <= start && r >= end){
        elect.push_back(seg[index]);
        return;
    }
    int mid = (start + end)/2;
    findValue(seg, start, mid, l, r, 2*index+1, elect);
    findValue(seg, mid+1, end, l, r, 2*index+2, elect);
}

int binarySearch(vector<int> arr, int start, int end, int k, int n, int flag){
    if(start > end){
        if(flag == 0){
            return end;
        } else {
            return end;
        }
        if(start == -1){
            return end;
        } 
        if(end == n){
            return start;
        }
        if(arr[start] < k && flag == 0){
            return start;
        } else if(flag == 0){
            return end;
        }
        if(arr[start] > k && flag == 1){
            return start;
        } else if(flag == 0){
            return end;
        }
        return start;
    }
    int mid = (start + end)/2;
    if(arr[mid] == k){
        return mid;
    }
    if(arr[mid] < k){
        return binarySearch(arr, mid+1, end, k, n, flag);
    } else {
        return binarySearch(arr, start, mid - 1, k, n, flag);
    }
}

int findAnsGreater(vector <node> elect, int k){
    ll ans = 0;
    int flag = 0;
    for(int m=0;m<elect.size();m++){
       ans += elect[m].v.size() - binarySearch(elect[m].v, 0, elect[m].v.size() - 1, k, elect[m].v.size(), 0) - 1;
    }
    return ans;
}

int findAnsLess(vector <node> elect, int k){
    ll ans = 0;
    int flag = 0;
    for(int m=0;m<elect.size();m++){
       ans += binarySearch(elect[m].v, 0, elect[m].v.size() - 1, k, elect[m].v.size(), 1) + 1;
    }
    return ans;
}

int main() {
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    ll ans = 0;
    node seg[SIZE];
    constructSegTree(seg, 0, n-1, 0, arr);
    for(int i=1;i<n-1;i++){
        vector <node> elect;
        findValue(seg, 0, n-1, 0, i-1, 0, elect);
        int one = findAnsGreater(elect, arr[i]);
        elect.clear();
        findValue(seg, 0, n-1, i+1, n-1, 0, elect);
        int two = findAnsLess(elect, arr[i]);
        // cout<<i<<" "<<one<<" "<<two<<endl;
        ans += one*two;
    }
    cout<<ans<<endl;
}
