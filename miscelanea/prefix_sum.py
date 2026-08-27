# Soma de prefixos
# O(N)

# Dado um array de inteiros A de tamanho N, o algoritmo gera
# um array P de tamanho N + 1, onde P[i] é definido pela recorrência:

# P[0] = 0
# P[i] = P[i-1] + A[i-1]

# Desta forma, é possível calcular a soma de qualquer subarray de A, tal que:

# A[l] + A[l+1] + ... + A[r-1] + A[r] = P[r+1] - P[l]

def prefix_sum(a: list[int]) -> list[int]:
    n = len(a)
    pref = [0 for i in range(n + 1)]

    for i in range(1, n + 1):
        pref[i] = pref[i - 1] + a[i - 1]

    return pref
