# Subset sum

# Dado um conjunto A e um inteiro W, o algoritmo verifica se existe algum
# subconjunto S de A tal que o somatório dos elementos de S é igual a W.
# O(|A| * W)
def subset_sum(arr: list[int], w: int) -> bool:
    dp = [False for i in range(w + 1)]
    dp[0] = True

    for n in arr:
        for x in range(w - n, -1, -1):
            if dp[x]:
                dp[x + n] = True

    return dp[w]

# A seguinte função tem o mesmo objetivo, mas tem como
# funcionalidade adicional reconstruir o subconjunto.
def subset_sum_find(arr: list[int], w: int) -> list[int]:
    dp = [-1 for i in range(w + 1)]
    dp[0] = -2
    prev = [-1 for i in range(w + 1)]

    for i, n in enumerate(arr):
        for x in range(w - n, -1, -1):
            if dp[x] != -1 and dp[x + n] == -1:
                dp[x + n] = i
                prev[x + n] = x

    if dp[w] == -1:
        return None

    subset = []
    cur = w

    while cur != 0:
        i = dp[cur]
        subset.append(arr[i])
        cur = prev[cur]

    return subset
