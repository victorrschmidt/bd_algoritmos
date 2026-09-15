// ============================================================================
// Algoritmo de Prim (Minimum spanning tree)
// O((E + V) * log(V))
// ============================================================================

/*

Dado um grafo conexo e valorado, o algoritmo gera
uma sub-árvore com menor somatório de pesos de arestas.

O grafo deve estar no formato de lista de adjacência:
g[u] = {{v, w}, ...}

*/

vector<vector<pair<int, int>>> prim(vector<vector<pair<int, int>>>& adj) {
    int V = adj.size();
    vector<vector<pair<int, int>>> mst(V);
    priority_queue<vector<int>> pq;
    vector<bool> vis(V);
    pq.push({0, 0, 0});

    while (!pq.empty()) {
        int w = -pq.top()[0];
        int u = pq.top()[1];
        int v = pq.top()[2];
        pq.pop();

        if (vis[u]) continue;
        vis[u] = true;

        if (u != v) {
            mst[u].push_back({v, w});
            mst[v].push_back({u, w});
        }

        for (auto [v, w] : adj[u]) {
            if (!vis[v]) {
                pq.push({-w, v, u});
            }
        }
    }

    return mst;
}
