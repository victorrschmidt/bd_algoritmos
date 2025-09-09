// Struct sorting

/*
Ordenar um array de structs com base em critérios de prioridade.
*/

#include <bits/stdc++.h>
using namespace std;

typedef struct {
    string name;
    int salary;
} Person;

bool comp(Person a, Person b) {
    /*
        Ordenar pessoas:
        1. Em ordem crescente de salário
        2. Em ordem lexicográfica
    */

    if (a.salary != b.salary) return a.salary < b.salary;
    return a.name.compare(b.name) < 0;
}

int main() {
    vector<Person> a{
        {"Carlos", 1800},
        {"Pedro",  3200},
        {"Jorge",  3200},
        {"Lucas",  1380},
        {"Maria",  2000},
        {"Ana",    2500}
    };

    sort(a.begin(), a.end(), comp);

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