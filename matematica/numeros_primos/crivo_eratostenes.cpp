// Crivo de Eratóstenes

/*
Dado um número inteiro não negativo N, o algoritmo gera um array booleano de
tamanho N + 1 que indica se um número X (0 <= X <= N) é primo (true) ou não (false).
*/

#include <bits/stdc++.h>
using namespace std;

vector<bool> crivo(int n) {
    vector<bool> primes(n + 1, true);

    primes[0] = false;
    primes[1] = false;

    for (int p = 2; p*p <= n; p++) {
        if (!primes[p]) continue;

        for (int i = p*p; i <= n; i += p) {
            primes[i] = false;
        }
    }

    return primes;
}