#include <bits/stdc++.h>

using namespace std;

struct duo{
    int index;

    int first;
    int second;
};

bool compare(duo a, duo b){
    if(a.first < b.first){
        return true;
    } else if(a.first != b.first){
        return false;
    } else {
        if(a.second < b.second){
            return true;
        } else {
            return false;
        }
    }
}

void countSort(duo * suffix, int s, int e){
    int count[1000] = {0};
    for(int i=s;i<=e;i++){
        count[suffix[i].second]++;
    }
    for(int i=1;i<300;i++){
        count[i] = count[i] + count[i-1];
    }
    int output[1000];
//    for(int i=s;i<=e;i++){
//        output[count[] =
//    }
}

bool equalToPrev(vector<duo> suffix, int i){
    int a = suffix[i].first;
    int b = suffix[i].second;
    int c = suffix[i-1].first;
    int d = suffix[i-1].second;
    if(a == c && b == d){
        return true;
    }
    return false;
}

int main()
{
    string str = "$banana";
    int n = str.length()-1;
    vector <duo> suffix;
    suffix.push_back({100, -50, -60});
    for(int i=1;i<=n;i++){
        suffix.push_back({i, str[i] - 'a', i});
    }
    for(int i=1;i<=n;i++){
        suffix[i].second = (i + 1 <= n)?suffix[i+1].first:-1;
    }

    sort(suffix.begin() + 1, suffix.end(), compare);
    int status[1000] = {0};
    int rank[1000] = {0};
    for(int k=4;k<=n;k *= 2){
        int prev = 0;

        for(int i=1;i<=n;i++){
            status[suffix[i].index] = i;
        }
        for(int i=2;i<=n;i++){
            if(equalToPrev(suffix, i) || i == 1){
                rank[i] = prev;
            } else {
                rank[i] = ++prev;
            }
        }
        for(int i=1;i<=n;i++){
            suffix[i].first = rank[i];
        }
        for(int i=1;i<=n;i++){
            int ind = suffix[i].index;
            suffix[i].second = (ind + k - 1 <= n)?suffix[status[ind+k - 1]].first:-1;
        }
        sort(suffix.begin()+1, suffix.end(), compare);
    }
    for(int i=1;i<=n;i++){
        cout<<suffix[i].index<<" ";
    }
    return 0;
}
