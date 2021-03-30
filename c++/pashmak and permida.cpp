#include <bits/stdc++.h>
#define SIZE 6000001
#define small_size 2000001

using namespace std;


struct tri{
    int a, b, c;
};

struct node{
    vector<tri> v;

    void reset(){
        this->v.clear();
    }
};


node build(node seg[], int start, int end, int index, int arr[]){
    if(start == end){
        seg[index].v.push_back({arr[start], 1, 0});
        return seg[index];
    }

    int mid = (start + end)/2;
    node val1 = build(seg, start, mid, 2*index, arr);
    node val2 = build(seg, mid+1, end, 2*index+1, arr);
    int i=0, j=0;
    while(i < val1.v.size() && j < val2.v.size()){
        if(val1.v[i].a < val2.v[j].a){
            seg[index].v.push_back({val1.v[i].a, val1.v[i].b, 0});
            i++;
        }
        else if(val1.v[i].a > val2.v[j].a){
            seg[index].v.push_back({val2.v[j].a, val2.v[j].b, 0});
            j++;
        }
        else if(val1.v[i].a == val2.v[j].a){
            seg[index].v.push_back({val1.v[i].a, val1.v[i].b + val2.v[j].b, 0});
            i++;
            j++;
        }
    }
    while(i < val1.v.size()){
        seg[index].v.push_back({val1.v[i].a, val1.v[i].b, 0});
        i++;
    }
    while(j < val2.v.size()){
        seg[index].v.push_back({val2.v[j].a, val2.v[j].b, 0});
        j++;
    }
    return seg[index];
}


node build2(node seg[], int start, int end, int index, int arr[]){
    if(start == end){
        seg[index].v.push_back({arr[start], 1, 1});
        return seg[index];
    }

    int mid = (start + end)/2;
    node val1 = build2(seg, start, mid, 2*index, arr);
    node val2 = build2(seg, mid+1, end, 2*index+1, arr);
    int i=0, j=0;
    int curr = 0;
    while(i < val1.v.size() && j < val2.v.size()){
        if(val1.v[i].a < val2.v[j].a){
            curr += val1.v[i].b;
            seg[index].v.push_back({val1.v[i].a, val1.v[i].b, curr});
            i++;
        }
        else if(val1.v[i].a > val2.v[j].a){
            curr += val2.v[j].b;
            seg[index].v.push_back({val2.v[j].a, val2.v[j].b, curr});
            j++;
        }
        else if(val1.v[i].a == val2.v[j].a){
            curr += val1.v[i].b + val2.v[j].b;
            seg[index].v.push_back({val1.v[i].a, val1.v[i].b + val2.v[j].b, curr});
            i++;
            j++;
        }
    }
    while(i < val1.v.size()){
        curr += val1.v[i].b;
        seg[index].v.push_back({val1.v[i].a, val1.v[i].b, curr});
        i++;
    }
    while(j < val2.v.size()){
        curr += val2.v[j].b;
        seg[index].v.push_back({val2.v[j].a, val2.v[j].b, curr});
        j++;
    }
    return seg[index];
}


void print(vector<tri> &v){
    for(int i=0;i<v.size();i++){
        printf("%d(%d) ", v[i].a, v[i].c);
    }
    cout<<endl;
}

void traverse(node seg[], int start, int end, int index){
    printf("%d %d -> ", start, end);
    print(seg[index].v);
    if(start == end){
        return;
    }
    int mid = (start + end)/2;
    traverse(seg, start, mid, 2*index);
    traverse(seg, mid+1, end, 2*index+1);
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
    findValue(seg, start, mid, l, r, 2*index, elect);
    findValue(seg, mid + 1, end, l, r, 2*index+1, elect);
}

int binarySearch(int start, int end, vector<tri> &v, int x){
    if(start > end){
        return end;
    }
    int mid = (start + end)/2;
    if(v[mid].a  == x){
        return mid;
    }

    if(v[mid].a > x){
        return binarySearch(start, mid - 1, v, x);
    } else {
        return binarySearch(mid+1, end, v, x);
    }
}

int findAns(vector <node> &elect, int x){
    int ans = 0;
    for(int i=0;i<elect.size();i++){
        int index =  binarySearch(0, elect[i].v.size()-1, elect[i].v, x);
        if(elect[i].v[index].a == x){
            ans += elect[i].v[index].b;
        }
    }
    return ans;
}

long long int finalAns(vector <node> &elect, int x){
     long long int ans = 0;
    for(int i=0;i<elect.size();i++){
        int index =  binarySearch(0, elect[i].v.size()-1, elect[i].v, x);
        if(index != 0 && index != -1){
            if(elect[i].v[index].a == x){
                ans += elect[i].v[index - 1].c;
            } else {
                ans += elect[i].v[index].c;
            } 
        } else if(elect[i].v[index].a != x && index >= 0){
            ans += elect[i].v[index].c;
        }
        
    }
    return ans;
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[small_size];
    for(int i=1;i<=n;i++){
        scanf("%d", &arr[i]);
    }
    node seg[SIZE];
    build(seg, 1, n, 1, arr);
    // traverse(seg, 1, n, 1);
    int one[small_size], two[small_size];
    for(int i=1;i<=n;i++){
        vector <node> elect;
        findValue(seg, 1, n, 1, i, 1, elect);
        one[i] = findAns(elect, arr[i]);
    }
    for(int i=n;i>=1;i--){
        vector <node> elect;
        findValue(seg, 1, n, i, n, 1, elect);
        two[i] = findAns(elect, arr[i]);
    }

    for(int i=0;i<SIZE;i++){
        seg[i].reset();
    }
    build2(seg, 1, n, 1, two);
    // traverse(seg, 1, n, 1);
    long long int ans = 0;
    for(int i=1;i<n;i++){
        vector <node> elect;
        findValue(seg, 1, n, i+1, n, 1, elect);
        ans +=finalAns(elect, one[i]);
    }
    cout<<ans<<endl;
}
