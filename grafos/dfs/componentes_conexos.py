# Depth-first search - Componentes conexos

# Dado um grafo não valorado, o algoritmo determina
# a conectividade entre dois vértices arbitrários,
# separando-os em grupos e 0 até N. Dois vértices U e V são
# conexos se comp[U] = comp[V].

# O grafo deve estar no formato de lista de adjacência:
# g[u] = {v, ...}

def connected_components(adj: list[list[int]]) -> list[int]:
    V = len(adj)
    vis = [False for i in range(V)]
    comp = [-1 for i in range(V)]
    cnt = 0

    def dfs(u: int) -> None:
        vis[u] = True
        comp[u] = cnt

        for v in adj[u]:
            if not vis[v]:
                dfs(v)

    for i in range(len(adj)):
        if not vis[i]:
            dfs(i)
            cnt += 1

    return comp
