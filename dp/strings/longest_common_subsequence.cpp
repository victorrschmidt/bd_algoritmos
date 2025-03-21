// Longest common subsequence

/*
Dadas duas strings A e B, o algoritmo verifica o tamanho da maior subsequência
comum a A e B.
*/

#include <bits/stdc++.h>
using namespace std;

int longest_common_subsequence(string a, string b) {
    int n = a.size();
    int m = b.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][m];
}