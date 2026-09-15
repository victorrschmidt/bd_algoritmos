// ============================================================================
// Algoritmo de Dijkstra
// O(E + V * log(V))
// ============================================================================

/*

Dado um grafo valorado, o algoritmo determina
o menor caminho entre um vértice U e todos os outros vértices.

O grafo deve estar no formato de lista de adjacência:
g[u] = {{v, w}, ...}

*/

vector<int> dijkstra(vector<vector<pair<int, int>>>& adj, int from) {
    int V = adj.size();
    vector<int> dist(V, (int) 1e9);
    vector<bool> vis(V);
    priority_queue<pair<int, int>> pq;

    dist[from] = 0;
    pq.push({0, from});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (vis[u]) continue;
        vis[u] = true;

        for (auto [v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({-dist[v], v});
            }
        }
    }

    return dist;
}
