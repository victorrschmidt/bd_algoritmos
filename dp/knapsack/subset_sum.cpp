// Subset sum

/*
Dado um conjunto C e um inteiro W, o algoritmo verifica se existe algum
subconjunto S de C tal que o somatório dos elementos de S é igual a W.
*/

#include <bits/stdc++.h>
using namespace std;

bool subset_sum(vector<int> a, int w) {
    vector<bool> dp(w + 1);
    dp[0] = true;

    for (auto n : a) {
        for (int x = w; x >= 0; x--) {
            if (dp[x] && x + n <= w) dp[x + n] = true;
        }
    }

    return dp[w];
}