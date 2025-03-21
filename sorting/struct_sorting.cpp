// Struct sorting

/*
Ordenar um array de structs com base em critérios de prioridade.
*/

#include <bits/stdc++.h>
using namespace std;

struct pessoa {
    string nome;
    int salario;
};

bool comp(pessoa a, pessoa b) {
    /*
        Ordenar pessoas:
        1. Em ordem crescente de salário
        2. Em ordem lexicográfica
    */

    if (a.salario != b.salario) return a.salario < b.salario;
    return a.nome.compare(b.nome) < 0;
}

int main() {
    vector<pessoa> v{
        {"Carlos", 1800},
        {"Pedro",  3200},
        {"Jorge",  3200},
        {"Lucas",  1380},
        {"Maria",  2000},
        {"Ana",    2500}
    };

    sort(v.begin(), v.end(), comp);

    /*
        Lucas  1380
        Carlos 1800
        Maria  2000
        Ana    2500
        Jorge  3200
        Pedro  3200
    */

    return 0;
}