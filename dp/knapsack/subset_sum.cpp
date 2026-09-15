// ============================================================================
// Subset sum
// O(N * W)
// ============================================================================

/*

Dado um conjunto A e um inteiro W, o algoritmo verifica se existe algum
subconjunto S de A tal que o somatório dos elementos de S é igual a W.

*/

bool subsetSum(vector<int>& a, int w) {
    vector<bool> dp(w + 1);
    dp[0] = true;

    for (auto n : a) {
        for (int x = w - n; x >= 0; x--) {
            if (dp[x]) {
                dp[x + n] = true;
            }
        }
    }

    return dp[w];
}

/*

A seguinte função tem o mesmo objetivo, mas tem como
funcionalidade adicional reconstruir o subconjunto.

*/

vector<int> subsetSumFind(vector<int>& a, int w) {
    vector<int> dp(w + 1, -1);
    vector<int> prev(w + 1, -1);
    dp[0] = -2;

    for (int i = 0; i < a.size(); i++) {
        int n = a[i];

        for (int x = w - n; x >= 0; x--) {
            if (dp[x] != -1 && dp[x + n] == -1) {
                dp[x + n] = i;
                prev[x + n] = x;
            }
        }
    }

    if (dp[w] == -1) {
        return {};
    }

    vector<int> subset;
    int cur = w;

    while (cur) {
        int i = dp[cur];
        subset.push_back(a[i]);
        cur = prev[cur];
    }

    return subset;
}
