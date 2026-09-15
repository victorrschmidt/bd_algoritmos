// ============================================================================
// Algoritmo de Floyd-Warshall
// O(V^3)
// ============================================================================

/*

Dado um grafo valorado, o algoritmo determina
o menor caminho entre todos os pares de vértices.

O grafo deve estar no formato de matriz de adjacência:
g[u][v] = w

*/

vector<vector<int>> floydWarshall(vector<vector<int>>& adj) {
    int INF = (int) 1e9;
    int V = adj.size();
    vector<vector<int>> fw = adj;

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (fw[i][k] != INF &&
                    fw[k][j] != INF &&
                    fw[i][j] > fw[i][k] + fw[k][j])
                {
                    fw[i][j] = fw[i][k] + fw[k][j];
                }
            }
        }
    }

    return fw;
}
