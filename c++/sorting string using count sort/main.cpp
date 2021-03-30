#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str = "lkjhadfjkldfsajkl";
    int count[26] = {0};
    int n = str.length();
    for(int i=0;i<n;i++){
        count[str[i] - 'a']++;
    }
    for(int i=1;i<26;i++){
        count[i+1] += count[i];
    }
    char output[2000];
    for(int i=)
    return 0;
}
