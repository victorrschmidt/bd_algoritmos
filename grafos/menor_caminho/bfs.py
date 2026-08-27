# Breadth-first search - Menor caminho

# Dado um grafo não valorado, o algoritmo determina
# o menor caminho entre um vértice U e todos os outros vértices.

# O grafo deve estar no formato de lista de adjacência:
# g[u] = {v, ...}

from collections import deque

def bfs(adj: list[list[int]], orig: int) -> list[int]:
    V = len(adj)
    dist = [-1 for i in range(V)]
    vis = [False for i in range(V)]
    q = deque()

    dist[orig] = 0
    vis[orig] = True
    q.append(orig)

    while q:
        u = q.popleft()

        for v in adj[u]:
            if not vis[v]:
                vis[v] = True
                dist[v] = dist[u] + 1
                q.append(v)

    return dist
