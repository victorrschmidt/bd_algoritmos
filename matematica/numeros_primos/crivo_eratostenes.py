# Crivo de Eratóstenes
# O(N * log(log(N)))

# Dado um número inteiro não negativo N, o algoritmo gera
# um array booleano de tamanho N + 1 que indica se
# um número X (0 <= X <= N) é primo (true) ou não (false).

def crivo(n: int) -> list[bool]:
    primes = [True for i in range(n + 1)]
    primes[0] = False
    primes[1] = False

    p = 2
    while p * p <= n:
        if primes[p]:
            for i in range(p * p, n + 1, p):
                primes[i] = False
        p += 1

    return primes
