// DFS - Componentes conexos

/*
Dado um grafo não valorado, o algoritmo determina a conectividade entre dois
vértices arbitrários, separando-os em grupos e 0 até N. Dois vértices U e V são
conexos se comp[U] = comp[V].

O grafo deve estar no formato de lista de adjacência:

g[u] = {v, ...}
*/

#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    int V, cont;
    vector<vector<int>> adj;  // g[u] = {v, ...}
    vector<int> comp;
    vector<bool> vis;

    Graph(vector<vector<int>> adj) {
        this->V = adj.size();
        this->adj = adj;
        this->comp.resize(this->V);
        this->vis.resize(this->V);
        this->cont = 0;
    }

    void dfs(int u) {
        this->vis[u] = true;
        this->comp[u] = this->cont;

        for (auto v : this->adj[u]) {
            if (!this->vis[v]) {
                this->dfs(v);
            }
        }
    }

    void find_components() {
        for (int i = 0; i < this->V; i++) {
            if (!this->vis[i]) {
                this->dfs(i);
                this->cont++;
            }
        }
    }
};