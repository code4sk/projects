#include <iostream>
#include <queue>

using namespace std;

int value[] = {60, 100, 120}, n = 3, maxSum = 0;
float weight[] = {10, 20, 30}, w = 50;
// int value[] = {100, 40, 95, 50, 30}, n = 5, maxSum = 0;
// float weight[] = {1.98, 2, 5, 3.14, 3}, w = 10;

struct Node {
    int level, bound, currentProfit;
    float weight;
};
void knapsack_bfs(Node dummy);
void knapsack_dfs(int i, Node prev);

int bound(Node node){
    if(node.weight>=w)
        return 0;
    int maxProfit = node.currentProfit;
    float sumWeight = node.weight;
    int i=node.level;
    for(;i<n;i++){
        if(sumWeight + weight[i] <= w){
            sumWeight += weight[i];
            maxProfit += value[i];
        }
        else{
            break;
        }
    }
    if(i<n){
        maxProfit += int((value[i]/float(weight[i]))*(w-sumWeight));
    }
    return maxProfit;
}

int main()
{
    Node dummy;
    dummy.level = -1;
    dummy.currentProfit = 0;
    dummy.weight = 0;
    // knapsack_dfs(0, dummy);
    knapsack_bfs(dummy);
    cout<<maxSum;
    return 0;
}

void knapsack_dfs(int i, Node prev){
    if(i>=n){
        return;
    }
    Node node;
    node.level = i;
    node.weight = prev.weight + weight[i];
    node.currentProfit = prev.currentProfit + value[i];
    node.bound = bound(node);
    if(node.bound > maxSum, node.weight <= w){
        maxSum = max(maxSum, node.currentProfit);
        // cout<<i<<"inc\n";
        knapsack_dfs(i+1, node);
    }
    node.weight = prev.weight;
    node.currentProfit = prev.currentProfit;
    node.bound = bound(node);
    if(node.bound > maxSum){
        // cout<<i<<"not inc\n";
        knapsack_dfs(i+1, node);
    }
}

void knapsack_bfs(Node dummy){
    queue <Node> q;
    Node u, v;
    q.push(dummy);
    while(!q.empty()){
        u = q.front();
        q.pop();
        int i = u.level;
        if(u.level == n-1)
            continue;
        v.level = u.level + 1;
        v.weight = u.weight + weight[i+1];
        v.currentProfit = u.currentProfit + value[i+1];
        v.bound = bound(v);
        if(v.weight <= w)
             maxSum = max(v.currentProfit, maxSum);
        if(v.bound > maxSum && v.weight <= w){
            maxSum = max(v.currentProfit, maxSum);
            // cout<<v.level<<"inc\n";
            q.push(v);
        }
        v.weight = u.weight;
        v.currentProfit = u.currentProfit;
        v.bound = bound(v);
        // cout<<v.bound<<"--"<<maxSum<<"\t";
        if(v.bound > maxSum){
            // cout<<i<<"not inc\n";
            q.push(v);
        }
    }
}
