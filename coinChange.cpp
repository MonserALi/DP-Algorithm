#include<bits/stdc++.h>
using namespace std;
vector<int> coinsUsed(100);
void findWhichAreTaken(int M, vector<int>& C, vector<long long>& dp) {

    for(int i=0;i<C.size();i++){
        coinsUsed[i] = 0;
    }

    int curr = M; // current amount

    while (curr > 0) {
        for (int i = 0; i < C.size(); i++) {
            if (curr>= C[i] && dp[curr - C[i]] + 1 == dp[curr]) {
                coinsUsed[i]++;
                curr -= C[i];
                break;
            }
        }
    }



}
int minCoins(int M, vector<int>& C) {
    vector<long long> dp(M + 1, INT_MAX);

    dp[0] = 0;

    for (int i = 1; i <= M; i++) {
        for (auto coin : C) {
            if (coin <= i && dp[i - coin]+1 < dp[i]) {
                dp[i] = dp[i - coin] + 1;
            }
        }
    }


    if(dp[M]!=INT_MAX){
        findWhichAreTaken(M,C,dp);
    }

    return dp[M];


}

int main() {
    int d;
    cout<<"Enter the types of coins: ";
    cin>>d;

    vector<int> coins(d);
    cout<<"Enter the denomination of each coins: ";
    for(int i=0;i<d;i++){
        cin>>coins[i];
    }

    cout<<"Enter the amount you want to Change: ";
    int M;
    cin>>M;



    int result = minCoins(M, coins);

    if (result != INT_MAX) {
        cout << "Minimum number of coins to make " << M << " cents = " << result << endl;
         for(int i=0;i<coins.size();i++){
        if(coinsUsed[i]>0){
            cout << "Coin " << coins[i]<< " used " << coinsUsed[i] << " times." << endl;
        }
    }
    } else {
        cout << "It's not possible to make change for " << M << " cents with the given coin types." << endl;
    }

    return 0;
}
