# Gerar subconjuntos
# O(2^N)

# Dado um array de interos A, o algoritmo gera todos os subconjuntos de A.

def subsets(arr: list[int]) -> list[int]:
    subs = []
    cur = []

    def search(index: int) -> None:
        subs.append([*cur])

        for i in range(index, len(arr)):
            cur.append(arr[i])
            search(i + 1)
            cur.pop()

    search(0)

    return subs
