#include <bits/stdc++.h>
#define SIZE 10001

using namespace std;

void sieve(int n, int prime[]){
    for(int i=2;i<=sqrt(n);i++){
        if(prime[i] == 0){
            for(int j=i*i;j<=n;j+=i){
                if(prime[j] == 0)
                prime[j] = i;
            }
        }
    }
}

void findValue(int num, int prime[]){
    if(prime[num] == 0){
        cout<<num<<"\n";
        return;
    }
    cout<<num<<" ";
    findValue(num/prime[num], prime);
}

int main()
{
    int n = 10000;
    int prime[SIZE] = {0};
    sieve(n, prime);
    cout<<"ok"<<prime[12]<<endl;
    findValue(24, prime);
    return 0;
}
