# Algoritmo de Kadane (Max subarray sum)

# Dado um array de inteiros A, o algoritmo
# verifica a soma máxima de um subarray de A.

def max_subarray_sum(a: list[int]) -> int:
    cur = a[0]
    mx = a[0]

    for i in range(1, len(a)):
        cur = max(a[i], a[i] + cur)
        mx = max(mx, cur)

    return mx
