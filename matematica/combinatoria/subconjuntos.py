# Gerar subconjuntos
# O(2^N)

# Dado um array de interos A, o algoritmo gera todos os subconjuntos de A.

a = [1, 2, 3]

subsets = []
cur = []

def search(index: int) -> None:
    subsets.append([*cur])

    for i in range(index, len(a)):
        cur.append(a[i])
        search(i + 1)
        cur.pop()

search(0)