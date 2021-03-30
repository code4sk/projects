#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str = "aabaa";
    string pattern = "a";
    int prefix[1000] = {0};
    int border = 0;
    string temp = pattern + "$" + str;
    for(int i=1;i<temp.length();i++){
        while(temp[i] != temp[border] && border > 0){
            border = prefix[border-1];
        }
        if(temp[i] == temp[border]){
            border++;
            prefix[i] = border;
        } else {
            border = 0;
            prefix[i] = 0;
        }
    }
//    for(int i=0;i<str.length();i++){
//        cout<<prefix[i]<<" ";
//    }

    int ans = 0;
    for(int i=0;i<temp.length();i++){
        if(prefix[i] == pattern.length()){
            ans++;
            cout<<"ok"<<i<<endl;
        }
    }
    cout<<ans;
    return 0;
}
