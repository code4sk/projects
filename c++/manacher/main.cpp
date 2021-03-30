#include <iostream>
#include <set>
using namespace std;

set <string> st;

void insertIntoHashMap(string str, int pos, int value){
    string tempStr = "";
    int start = (pos - value)/2, end = start + value - 1;
    for(int i=start;i<=end;i++){
        tempStr += str[i];
    }
    // if(pos%2 == 0){
    //     cout<<pos<<" "<<value<<tempStr<<"\t";
    // }
    st.insert(tempStr);
}

int main() {
    int t;
	cin>>t;
	while(t--){
	    st.clear();
	    string str;
	    cin>>str;
        int n = str.size(), maxPos = 1, maxValue = 1;
        if(n == 1){
            cout<<1<<endl;
            continue;
        }
        n = 2*n + 1;
        int L[10000] = {0};
        L[0] = 0;
        insertIntoHashMap(str, 1, 1);
        L[1] = 1;
        int C=1, iMirror=L[1], edge = 2, diff, expand = 0;
        for(int i=2;i<n;i++){
            iMirror = 2*C - i;
            diff = edge - i;
            if(diff > 0){
                if(L[iMirror] < diff){
                    L[i] = L[iMirror];
                } else if(L[iMirror] == diff && i == n-1){
                    L[i] = L[iMirror];
                } else if(L[iMirror] == diff && i < n-1){
                    L[i] = L[iMirror];
                    expand = 1;
                } else if(L[iMirror] > diff){
                    L[i] = diff;
                    expand = 1;
                }
            }
            else{
                expand = 1;
            }
            if(expand == 1){
                while(((i + L[i]) < n && (i - L[i]) > 0) &&
            ( ((i + L[i] + 1) % 2 == 0) ||
            (str[(i + L[i] + 1)/2] == str[(i - L[i] - 1)/2] ))){
                    L[i]++;
                    if(i%2 != 0 && L[i] %2 == 0)
                    continue;
                    if(i%2 == 0 && L[i] %2 != 0)
                    continue;
                    insertIntoHashMap(str, i, L[i]);
                }
            }
            if(i + L[i] > edge){
                C = i;
                edge = i + L[i];
            }
            if(L[i] > maxValue){
                maxValue = L[i];
                maxPos = i;
            }
            if(L[i]>0){
                insertIntoHashMap(str, i, L[i]);
            }
        }

    //     for(int j=0;j<n;j++){
    //     cout<<L[j]<<ends;
    // }
    //      for (auto itr = st.begin(); itr != st.end(); ++itr)
    // {
    //     cout << '\t' << *itr;
    // }
        cout<<maxValue;
        cout<<endl;
	}
	return 0;
}
