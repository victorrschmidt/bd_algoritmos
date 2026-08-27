# Algoritmo de Dijkstra

# Dado um grafo valorado, o algoritmo determina
# o menor caminho entre um vértice U e todos os outros vértices.

# O grafo deve estar no formato de lista de adjacência:
# g[u] = {{v, w}, ...}

from heapq import heappush, heappop

def dijkstra(adj: list[list[tuple[int, int]]], orig: int) -> list[int]:
    V = len(adj)
    dist = [int(1e9) for i in range(V)]
    vis = [False for i in range(V)]
    pq = []

    dist[orig] = 0
    heappush(pq, (0, orig))

    while pq:
        u = heappop(pq)[1]

        if vis[u]:
            continue

        vis[u] = True

        for v, w in adj[u]:
            if dist[v] > dist[u] + w:
                dist[v] = dist[u] + w
                heappush(pq, (dist[v], v))

    return dist
