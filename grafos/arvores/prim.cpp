// Algoritmo de Prim

/*
Dado um grafo conexo e valorado, o algoritmo gera uma sub-árvore com menor
somatório de pesos de arestas (minimum spanning tree).

O grafo deve estar no formato de lista de adjacência:

g[u] = {{v, w}, ...}
*/

#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    int V;
    vector<vector<pair<int, int>>> adj, mst;  // g[u] = {{v, w}, ...}

    Graph(vector<vector<pair<int, int>>> adj) {
        this->V = adj.size();
        this->adj = adj;
        this->mst.resize(this->V);
    }

    void prim() {
        vector<bool> vis(this->V);
        priority_queue<vector<int>> pq;  // {w, u, v}
        pq.push({0, 0, 0});

        while (!pq.empty()) {
            int w = -pq.top()[0];
            int u = pq.top()[1];
            int v = pq.top()[2];
            pq.pop();

            if (vis[u]) continue;
            vis[u] = true;

            if (u != v) {
                this->mst[u].push_back({v, w});
                this->mst[v].push_back({u, w});
            }

            for (auto [v, w] : adj[u]) {
                if (!vis[v]) {
                    pq.push({-w, v, u});
                }
            }
        }
    }
};