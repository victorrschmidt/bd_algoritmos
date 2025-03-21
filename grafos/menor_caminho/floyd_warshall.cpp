// Algoritmo de Floyd-Warshall

/*
Dado um grafo valorado, o algoritmo determina o menor caminho entre todos os
pares de vértices.

O grafo deve estar no formato de matriz de adjacência:

g[u][v] = w
*/

#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    int V;
    vector<vector<int>> adj, fw;  // g[u][v] = w

    Graph(vector<vector<int>> adj) {
        this->V = adj.size();
        this->adj = adj;
        this->fw = adj;
    }

    void floyd_warshall() {
        // Obs: se não existe uma aresta entre U e V, o valor
        // de g[u][v] deve ser igual ao valor definido para INF
        int INF = (int) 1e9;

        for (int k = 0; k < this->V; k++) {
            for (int i = 0; i < this->V; i++) {
                for (int j = 0; j < this->V; j++) {
                    if (this->fw[i][k] != INF &&
                        this->fw[k][j] != INF &&
                        this->fw[i][j] > this->fw[i][k] + this->fw[k][j]
                    ) {
                        this->fw[i][j] = this->fw[i][k] + this->fw[k][j];
                    }
                }
            }
        }
    }
};