// ============================================================================
// Breadth-first search - Menor caminho
// O(V + E)
// ============================================================================

/*

Dado um grafo não valorado, o algoritmo determina
o menor caminho entre um vértice U e todos os outros vértices.

O grafo deve estar no formato de lista de adjacência:
g[u] = {v, ...}

*/

vector<int> bfs(vector<vector<int>>& adj, int from) {
    int V = adj.size();
    vector<int> dist(V, -1);
    vector<bool> vis(V);
    queue<int> q;

    dist[from] = 0;
    vis[from] = true;
    q.push(from);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto v : adj[u]) {
            if (!vis[v]) {
                vis[v] = true;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    return dist;
}
