// Soma de prefixos

/*
Dado um array de inteiros A de tamanho N, o algoritmo gera um array P de
tamanho N + 1, onde o elemento P[i] é a soma de P[i-1] + A[i-1].

Desta forma, é possível calcular a soma de qualquer subarray de A, tal que:

A[l] + A[l+1] + ... + A[r-1] + A[r] = P[r+1] - P[l]
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_sum(vector<int> a) {
    int n = a.size();
    vector<int> pref(n + 1);

    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + a[i - 1];
    }

    return pref;
}