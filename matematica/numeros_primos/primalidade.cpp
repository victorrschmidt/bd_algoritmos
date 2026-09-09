// Primalidade
// O(√N)

// Dado um número inteiro não negativo N, o algoritmo verifica se N é primo.

bool primo(int n) {
    if (n < 2) {
        return false;
    }

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}
