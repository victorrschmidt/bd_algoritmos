# Algoritmo de Floyd-Warshall

# Dado um grafo valorado, o algoritmo determina
# o menor caminho entre todos os pares de vértices.

# O grafo deve estar no formato de matriz de adjacência:
# g[u][v] = w

def floyd_warshall(adj: list[list[int]]) -> list[list[int]]:
    INF = int(1e9)
    V = len(adj)
    fw = [[adj[i][j] for j in range(V)] for i in range(V)]

    for k in range(V):
        for i in range(V):
            for j in range(V):
                if (fw[i][k] != INF and
                    fw[k][j] != INF and
                    fw[i][j] > fw[i][k] + fw[k][j]
                ):
                    fw[i][j] = fw[i][k] + fw[k][j]

    return fw
