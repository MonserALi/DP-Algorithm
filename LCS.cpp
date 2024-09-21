#include <bits/stdc++.h>


using namespace std;

int lcs(string &S1, string &S2, string &lcsStr) {
    int m = S1.size();
    int n = S2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (S1[i - 1] == S2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (S1[i - 1] == S2[j - 1]) {
            lcsStr.push_back(S1[i - 1]);
            i--; j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    reverse(lcsStr.begin(), lcsStr.end());
    return dp[m][n];
}

int main() {
    string S1,S2;
    cin>>S1>>S2;
    string lcsStr;

    int length = lcs(S1, S2, lcsStr);
    cout << "Length of LCS is " << length << endl;
    cout << "LCS is " << lcsStr << endl;

    return 0;
}
