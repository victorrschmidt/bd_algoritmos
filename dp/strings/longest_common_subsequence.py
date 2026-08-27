# Longest common subsequence
# O(|A| * |B|)

# Dadas duas strings A e B, o algoritmo verifica
# o tamanho da maior subsequência comum a A e B.

def longest_common_subsequence(a: str, b: str) -> int:
    n = len(a)
    m = len(b)

    dp = [[0 for j in range(m)] for i in range(n)]

    for i in range(1, n + 1):
        for j in range(1, m + 1):
            if a[i - 1] == b[j - 1]:
                dp[i][j] = dp[i - 1][j - 1] + 1
            else:
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

    return dp[n][m]
