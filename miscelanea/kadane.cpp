// Algoritmo de Kadane

/*
Dado um array de inteiros A, o algoritmo verifica a soma máxima de um subarray
(max subarray sum) de A.
*/

#include <bits/stdc++.h>
using namespace std;

int max_subarray_sum(vector<int> a) {
    int cur = a[0];
    int best = a[0];

    for (int i = 1; i < a.size(); i++) {
        cur = max(a[i], a[i] + cur);
        best = max(best, cur);
    }

    return best;
}