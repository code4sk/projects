#include <bits/stdc++.h>

using namespace std;

bool comparator(string a, string b){
    if(a == "$"){
        return 0;
    } else if(b == "$") {
        return 1;
    }
    return a < b;
}

bool new_comparator(pair <string, int> a, pair <string, int> b){
//    if(a.first == "$"){
//        return 0;
//    } else if(b.first == "$") {
//        return 1;
//    }
//    int n = strcmp(a.first.c_str(), b.first.c_str());
//    if(n == 1){
//        return false;
//    } else {
//    return true;}
return a.first < b.first;
}

string burrow_wheeler(string str){
    string ans = "";
    vector <string> v;
    string temp = str.substr(0, str.length());
    v.push_back(temp);
    int n = str.length();
    for(int j=0;j<n-1;j++){
        char ch = temp[0];
        for(int i=0;i<n - 1;i++){
            temp[i] = temp[i+1];
        }
        temp[n - 1] = ch;
        v.push_back(temp);
    }
    sort(v.begin(), v.end(), comparator);
    for(int i=0;i<n;i++){
        ans += v[i][n-1];
    }
    return ans;
}

string inverse(string str){
    string real = "";
    int n = str.length();
    string first = str.substr(0, n);
    vector <pair<string, int>> v;
    for(int i=0;i<n;i++){
        v.push_back({str.substr(i, 1), i});
    }
    sort(v.begin(), v.end());
    int i = 0;
    for(int j=0;j<n;j++){
        real += v[i].first;
        i = v[i].second;
    }
    return real.substr(1, n-1);
}

bool patternMatch(string bwt, string str){
    vector <pair<char, int>> v;
    int first[26] , last[26];
    for(int i=0;i<26;i++){
        first[i] = INT_MAX;
        last[i] = -1;
    }
    int first2[26] , last2[26];
    for(int i=0;i<26;i++){
        first2[i] = INT_MAX;
        last2[i] = -1;
    }
    int n = bwt.length();
    for(int i=0;i<n;i++){
        v.push_back({bwt[i], i});
    }
    sort(v.begin(), v.end());
    for(int i=0;i<n;i++){
        first[v[i].first - 'a'] = min(first[v[i].first - 'a'], i);
        last[v[i].first - 'a'] = max(last[v[i].first - 'a'], i);
    }
    for(int i=0;i<n;i++){
        first2[bwt[i] - 'a'] = min(first2[bwt[i] - 'a'], i);
        last2[bwt[i] - 'a'] = max(last2[bwt[i] - 'a'], i);
    }
    int n1 = str.length();
    int top = 0, bottom = n-1;
    for(int i=n1-1;i>=0;i--){
        cout<<str[i]<<"ok ";
        int index = str[i] - 'a';
        if(first2[index] == -1 || last2[index] == INT_MAX){
            cout<<index<<first2[index]<<last2[index];
            return false;
        }
        if(first2[index] > bottom || last2[index] < top){
            cout<<i<<first2[index]<<last2[index]<<top<<bottom;
            return false;
       }
        top = first[index];
        bottom = last[index];
    }
    return true;
}

int main()
{
    string str;
    cout<<"Enter the string of alphabets\n";
    getline(cin, str);
    for(int i=0;i<str.length();i++){
        if(str[i] == ' '){
            str[i] = '~';
        }
    }
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    string bwt = burrow_wheeler(str + "$");
    cout<<"Its Burrow wheeler transform is\n";
    cout<<bwt<<endl;
    cout<<"Real text is\n";
    cout<<inverse(bwt)<<endl;
    string pattern;
    cout<<"Enter the pattern to match\n";
    cin>>pattern;
    if(patternMatch(bwt, pattern)){
        cout<<"Found\n";
    } else {
        cout<<"Sorry Not Found\n";
    }



    return 0;
}
