// BFS - Menor caminho

/*
Dado um grafo não valorado, o algoritmo determina o menor caminho entre um
vértice U e todos os outros vértices.

O grafo deve estar no formato de lista de adjacência:

g[u] = {v, ...}
*/

#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    int V;
    vector<vector<int>> adj;  // g[u] = {v, ...}
    vector<int> dist;

    Graph(vector<vector<int>> adj) {
        this->V = adj.size();
        this->adj = adj;
        this->dist.resize(this->V);
    }

    void bfs(int from) {
        vector<bool> vis(this->V);
        queue<int> q;

        this->dist[from] = 0;
        vis[from] = true;
        q.push(from);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (auto v : this->adj[u]) {
                if (!vis[v]) {
                    vis[v] = true;
                    this->dist[v] = this->dist[u] + 1;
                    q.push(v);
                }
            }
        }
    }
};