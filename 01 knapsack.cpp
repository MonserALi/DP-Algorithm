#include <bits/stdc++.h>

using namespace std;

int knapSack(int capacity, const vector<int>& weights, const vector<int>& values, int n, vector<int>& selectedItems) {
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= capacity; w++) {
            if (weights[i - 1] <= w) { //item i is included
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    int res = dp[n][capacity];
    int w = capacity;

    for (int i = n; i > 0 && res > 0; i--) {
        if (res != dp[i - 1][w]) {
            selectedItems.push_back(i - 1);
            res -= values[i - 1];
            w -= weights[i - 1];
        }
    }

    return dp[n][capacity];
}

int main() {
    vector<int> values = {20, 9, 12, 7};
    vector<int> weights = {4, 3, 2, 1};

    int capacity = 5;
    int n = values.size();
    vector<int> selectedItems;

    int maxValue = knapSack(capacity, weights, values, n, selectedItems);

    cout << "Maximum value in knapsack: " << maxValue << endl;
    cout << "Items included: ";
    for (int i = selectedItems.size() - 1; i >= 0; i--) {
        cout << selectedItems[i]+1 << " ";
    }
    cout << endl;



    return 0;
}




