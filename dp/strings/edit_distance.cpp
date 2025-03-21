// Edit distance

/*
Dadas duas strings A e B, o algoritmo verifica a menor distância de edição
entre A e B, isto é:

Considerando as operações de inserção, remoção e substituição de caracteres,
o algoritmo determina o número mínimo de operações a serem aplicadas em A para
que A = B.
*/

#include <bits/stdc++.h>
using namespace std;

int edit_distance(string a, string b) {
	int n = a.size();
	int m = b.size();

	vector<vector<int>> dp(n + 1, vector<int>(m + 1));

	for (int i = 1; i <= n; i++) dp[i][0] = i;
	for (int i = 1; i <= m; i++) dp[0][i] = i;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = min({
                dp[i - 1][j] + 1,
                dp[i][j - 1] + 1,
                dp[i - 1][j - 1] + (a[i - 1] != b[j - 1])
            });
		}
	}

	return dp[n][m];
}