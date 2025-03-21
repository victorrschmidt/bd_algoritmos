// Gerar subconjuntos

/*
Dado um array de interos A, o algoritmo gera todos os subconjuntos de A.
*/

#include <bits/stdc++.h>
using namespace std;

class Conj {
public:
    vector<int> a, temp;
    vector<vector<int>> subsets;

    Conj(vector<int> a) {
        this->a = a;
    }

    void search(int index) {
        this->subsets.push_back(this->temp);

        for (int i = index; i < this->a.size(); i++) {
            this->temp.push_back(this->a[i]);
            this->search(i + 1);
            this->temp.pop_back();
        }
    }

    void find_subsets() {
        this->search(0);
    }
};