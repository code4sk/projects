#include <bits/stdc++.h>

using namespace std;

void kmp(string &str, string &pattern, vector<pair<int, int>>&ans){
    string temp = pattern + "$" + str;
    int n = temp.length();
    int border = 0;
    vector<int> prefix(n, 0);
    for(int i=1;i<n;i++){

        while(border > 0 && temp[i] != temp[border]){
            border = prefix[border-1];
        }

        if(temp[i] == temp[border]){

            border++;
            prefix[i] = border;
        } else {
            border = 0;
        }
    }
    for(int i=pattern.length();i<n;i++){
        if(prefix[i] == pattern.length()){
            ans.push_back({i-2*pattern.length(), i - pattern.length()-1});
        }
    }
}

int main()
{
    string str = "coronavirus disease (COVID-19) is an infectious disease caused by a newly discovered coronavirus. Most people infected with the COVID-19 virus will experience mild to moderate respiratory illness and recover without requiring special treatment. Older people, and those with underlying medical problems like cardiovascular disease, diabetes, chronic respiratory disease, and cancer are more likely to develop serious illness. The best way to prevent and slow down transmission is be well informed about the COVID-19 virus, the disease it causes and how it spreads. Protect yourself and others from infection by washing your hands or using an alcohol based rub frequently and not touching your face. The COVID-19 virus spreads primarily through droplets of saliva or discharge from the nose when an infected person coughs or sneezes, so it’s important that you also practice respiratory etiquette (for example, by coughing into a flexed elbow). At this time, there are no specific vaccines or treatments for COVID-19. However, there are many ongoing clinical trials evaluating potential treatments. WHO will continue to provide updated information as soon as clinical findings become available.";
    string pattern = "disease";
    cout<<"Paragraph to be searched is:\n"<<str<<endl;
    cout<<"\nPattern is :\n"<<pattern<<endl;
    vector<pair<int, int>> ans;
    kmp(str, pattern, ans);
    cout<<"\nStarting and ending indices of our match are:\n";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
    return 0;
}
