# Algoritmo de Prim (Minimum spanning tree)
# O((E + V) * log(V))

# Dado um grafo conexo e valorado, o algoritmo gera
# uma sub-árvore com menor somatório de pesos de arestas.

# O grafo deve estar no formato de lista de adjacência:
# g[u] = {{v, w}, ...}

from heapq import heappush, heappop

def prim(adj: list[list[tuple[int, int]]]) -> list[list[tuple[int, int]]]:
    V = len(adj)

    mst = [[] for i in range(V)]
    vis = [False for i in range(V)]
    pq = []
    heappush(pq, (0, 0, 0))

    while pq:
        w, u, v = heappop(pq)

        if vis[u]:
            continue

        vis[u] = True

        if u != v:
            mst[u].append((v, w))
            mst[v].append((u, w))

        for v, w in adj[u]:
            if not vis[v]:
                heappush(pq, (w, v, u))

    return mst
