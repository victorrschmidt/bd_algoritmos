# Longest common substring
# O(|A| * |B|)

# Dadas duas strings A e B, o algoritmo verifica
# o tamanho da maior substring comum a A e B.

def longest_common_substring(a: str, b: str) -> int:
    n = len(a)
    m = len(m)

    dp = [[0 for j in range(m)] for i in range(n)]
    mx = 0

    for i in range(1, n + 1):
        for j in range(1, m + 1):
            if a[i - 1] == b[j - 1]:
                dp[i][j] = dp[i - 1][j - 1] + 1
                mx = max(mx, dp[i][j])

    return mx
