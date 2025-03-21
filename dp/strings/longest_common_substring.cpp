// Longest common substring

/*
Dadas duas strings A e B, o algoritmo verifica o tamanho da maior substring
comum a A e B.
*/

#include <bits/stdc++.h>
using namespace std;

int longest_common_substring(string a, string b) {
    int n = a.size();
    int m = b.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    int best = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                best = max(best, dp[i][j]);
            }
        }
    }

    return best;
}