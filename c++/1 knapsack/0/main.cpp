#include <iostream>

using namespace std;

void knapsack(int i, int currSum, int currWeight, int maxPossible);

int weight[] = {10, 20, 30}, value[] = {60, 100, 120}, w = 50, n = 3, maxSum = 0;

int main()
{
    knapsack(0, 0, 0, 280);
    cout<<maxSum;
    return 0;
}

void knapsack(int i, int currSum, int currWeight,int maxPossible){
    if(i >= n){
        return;
    }
    if(currWeight + weight[i] <= w && maxPossible + currSum > maxSum){
        cout<<i<<"\t";
        maxSum = max(maxSum, currSum + value[i]);
        knapsack(i + 1, currSum + value[i], currWeight + weight[i], maxPossible - value[i]);
    }
    if(maxPossible + currSum > maxSum){
        knapsack(i + 1, currSum, currWeight, maxPossible - value[i]);
        cout<<i<<"\t";
    }
}
