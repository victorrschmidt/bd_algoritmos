// Algoritmo de Dijkstra

/*
Dado um grafo valorado, o algoritmo determina o menor caminho entre um vértice
U e todos os outros vértices.

O grafo deve estar no formato de lista de adjacência:

g[u] = {{v, w}, ...}
*/

#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    int V;
    vector<vector<pair<int, int>>> adj;  // g[u] = {{v, w}, ...}
    vector<int> dist;

    Graph(vector<vector<pair<int, int>>> adj) {
        this->V = adj.size();
        this->adj = adj;
        this->dist.resize(this->V);
    }

    void dijkstra(int from) {
        int INF = (int) 1e9;
        fill(this->dist.begin(), this->dist.end(), INF);
        priority_queue<pair<int, int>> pq;  // {w, u}
        vector<bool> vis(this->V);

        this->dist[from] = 0;
        pq.push({0, from});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            if (vis[u]) continue;
            vis[u] = true;

            for (auto [v, w] : this->adj[u]) {
                if (this->dist[v] > this->dist[u] + w) {
                    this->dist[v] = this->dist[u] + w;
                    pq.push({-this->dist[v], v});
                }
            }
        }
    }
};