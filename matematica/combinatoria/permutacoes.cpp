// Gerar permutações

/*
Dado um array de interos A, o algoritmo gera todas as permutações de A.

Obs: O array A deve estar ordenado.
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> permut(vector<int> a) {
    vector<vector<int>> p;

    do {
        p.push_back(a);
    } while (next_permutation(a.begin(), a.end()));

    return p;
}