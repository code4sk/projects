#include <bits/stdc++.h>
#define ll long long int
// #define MOD 1e10 + 7

using namespace std;
ll pow1[200001] = {0};
ll MOD = 1e9+7;

void make_hash(ll hash[], int n, string str){
    ll r = 0, k = 31, m = 1e10 + 7;

    pow1[0] = 1;
    hash[0] = r;
    for(int i=n-1;i>=0;i--){
        hash[i]=((hash[i+1]*k)%MOD+(str[i]-'a'+1))%MOD;
	    pow1[n-i]=(pow1[n-i-1]*k)%MOD;
    }
    pow1[n]=(pow1[n-1]*k)%MOD;
}

ll getHash(ll hash[], int s, int e){
    ll m = 1e10 + 7;
    return (MOD-(hash[e+1]*pow1[e-s+1])%MOD+hash[s])%MOD;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--){
        string str;
        cin>>str;
        cout<<((-3)%8);
        int n = str.length();
        ll count = 0;
        ll hash[200001] = {0};
        make_hash(hash, n, str);
        for(int i=2;i<=n-2;i+=2){
            int l1=0,r1=i/2-1;
            int l2=r1+1,r2=i-1;
            int l3=i,r3=(i+n)/2-1;
            int l4=r3+1,r4=n-1;
            ll a1 = getHash(hash, l1, r1);
            ll a2 = getHash(hash, l2, r2);
            ll b1 = getHash(hash, l3, r3);
            ll b2 = getHash(hash, l4, r4);
            if(a1 == a2 && b1 == b2){
                count++;
            }
        }
        cout<<count<<endl;
    }
}
