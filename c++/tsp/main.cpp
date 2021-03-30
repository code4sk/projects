#include <iostream>

using namespace std;

int tsp(int mask, int i);
int minSum = INT_MAX;

int tsp_backtrack(int pos, int curr, int path);

int tsp_backtrack_dp(int pos, int curr);

int n = 4;
int s = 0;
int arr[4][4] = { { 0, 10, 15, 20 },
                    { 10, 0, 35, 25 },
                    { 15, 35, 0, 30 },
                    { 20, 25, 30, 0 } };
int status[4] = {0};
int VISITED_ALL = (1<<n) - 1;
int dp[50][50];
int main()
{
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            dp[i][j] = -1;
        }
    }
    // cout<<tsp(1, 0);
    int path[4] = {0};
    for(int i=0;i<n;i++){
        path[i] = -1;
    }
    path[0] = 0;
    // tsp_backtrack(0, 1, 0);
    cout<<tsp_backtrack_dp(0, 1);
    return 0;
}

int tsp_backtrack(int pos, int curr, int currMinSum){
    if(curr == n){
        minSum = min(minSum, currMinSum + arr[pos][0]);
        return arr[pos][0];
    }
    for(int i=0;i<n;i++){
        if(arr[pos][i] > 0 && status[i] == 0){
            status[pos] = 1;
            tsp_backtrack(i, curr + 1, currMinSum + arr[pos][i]);
            status[i] = 0;
        }
    }
    return minSum;
}

int tsp_backtrack_dp(int pos, int curr){
    if(curr == n){
        return arr[pos][0];
    }
    int ans = INT_MAX;
    for(int i=0;i<n;i++){
        if(arr[pos][i] > 0 && status[i] == 0){
            status[pos] = 1;
            int newAns = arr[pos][i] + tsp_backtrack_dp(i, curr + 1);
            ans = min(ans, newAns);
            status[i] = 0;
        }
    }
    return ans;
}

int tsp(int mask, int pos){
    if(mask == VISITED_ALL){
        return arr[pos][s];
    }
    if(dp[mask][pos] != -1)
        return dp[mask][pos];
    int ans = INT_MAX;
    for(int i=0;i<n;i++){
        if((mask & (1<<i)) == 0){
            int newAns = arr[pos][i] + tsp(mask|(1<<i), i);
            ans = min(newAns, ans);
        }
    }
    return dp[mask][pos] = ans;
}
