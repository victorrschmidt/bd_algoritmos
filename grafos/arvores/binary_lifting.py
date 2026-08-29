# Binary lifting (K-th ancestor)
# O((N + Q) * log(N))

# Dada uma árvore, o algoritmo cria uma tabela que computa
# os ancestrais de cada vértice em potências de 2.

# A árvore deve estar no formato de parent array, tal que:
# parent[v] = pai do vértice v

class BinaryLifting:
    def __init__(self, parent: list[int]):
        n = len(parent)
        self.LOG = 0

        while (1 << self.LOG) <= n:
            self.LOG += 1

        self.up = [[0 for j in range(self.LOG)] for i in range(n)]

        for v in range(n):
            self.up[v][0] = parent[v]

            for i in range(1, self.LOG):
                self.up[v][i] = self.up[self.up[v][i - 1]][i - 1]

    def kth_ancestor(self, v: int, k: int) -> int:
        for i in range(self.LOG):
            if k & (1 << i):
                v = self.up[v][i]
        return v
