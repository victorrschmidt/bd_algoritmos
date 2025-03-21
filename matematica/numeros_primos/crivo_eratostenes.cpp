// Crivo de Eratóstenes

/*
Dado um número inteiro não negativo N, o algoritmo gera um array booleano de
tamanho N + 1 que indica se um número X (0 <= X <= N) é primo (true) ou não
(false).
*/

#include <bits/stdc++.h>
using namespace std;

vector<bool> crivo(int n) {
    vector<bool> primos(n + 1, true);

    primos[0] = primos[1] = false;

    for (int p = 2; p*p <= n; p++) {
        if (!primos[p]) continue;

        for (int i = p*p; i <= n; i += p) {
            primos[i] = false;
        }
    }

    return primos;
}