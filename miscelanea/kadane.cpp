// Algoritmo de Kadane (Max subarray sum)
// O(N)

// Dado um array de inteiros A, o algoritmo
// verifica a soma máxima de um subarray de A.

int max_subarray_sum(const vector<int>& a) {
    int cur = a[0];
    int mx = a[0];

    for (int i = 1; i < a.size(); i++) {
        cur = max(a[i], a[i] + cur);
        mx = max(mx, cur);
    }

    return mx;
}
