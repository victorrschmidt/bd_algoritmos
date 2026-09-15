// ============================================================================
// Binary lifting (K-th ancestor)
// O((N + Q) * log(N))
// ============================================================================

/*

Dada uma árvore, o algoritmo cria uma tabela que computa
os ancestrais de cada vértice em potências de 2.

A árvore deve estar no formato de parent array, tal que:
parent[v] = pai do vértice v

*/

class BinaryLifting {
    vector<vector<int>> up;
    int LOG;

public:
    BinaryLifting(int n, vector<int>& parent) {
        LOG = 0;

        while ((1 << LOG) <= n) {
            LOG++;
        }

        up = vector<vector<int>>(n, vector<int>(LOG));

        for (int v = 0; v < n; v++) {
            up[v][0] = parent[v];

            for (int i = 1; i < LOG; i++) {
                up[v][i] = up[up[v][i - 1]][i - 1];
            }
        }
    }

    int kthAncestor(int v, int k) {
        for (int i = 0; i < LOG; i++) {
            if (k & (1 << i)) {
                v = up[v][i];
            }
        }
        return v;
    }
};
