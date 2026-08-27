# Edit distance

# Dadas duas strings A e B, o algoritmo verifica
# a menor distância de edição entre A e B, isto é:

# Considerando as operações de inserção, remoção e substituição
# de caracteres, o algoritmo determina o número mínimo de operações
# a serem aplicadas em A para que A = B.

def edit_distance(a: str, b: str) -> int:
    n = len(a)
    m = len(b)

    dp = [[0 for j in range(m)] for i in range(n)]

    for i in range(1, n + 1):
        dp[i][0] = i
    for i in range(1, m + 1):
        dp[0][i] = i

    for i in range(1, n + 1):
        for j in range(1, m + 1):
            dp[i][j] = min(
                dp[i - 1][j] + 1,
                dp[i][j - 1] + 1,
                dp[i - 1][j - 1] + int(a[i - 1] != b[j - 1])
            )

    return dp[n][m]
