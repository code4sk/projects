#include <iostream>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while(t--){
	    int dp[1001][1001] = {0};
	    int n, m;
	    scanf("%d%d", &n, &m);
	    string a, b;
	    cin>>a>>b;
	    a = '!' + a;
	    b = '!' + b;
	    for(int i=1;i<=n;i++){
	        for(int j=1;j<=m;j++){
	            int c = a[i] == b[j];
	            int one = max(dp[i][j-1], dp[i-1][j]);
	            int two = dp[i-1][j-1] + c;
	            dp[i][j] = max(one, two);
	        }
	    }
	    cout<<dp[n][m]<<endl;
	}
	return 0;
}
