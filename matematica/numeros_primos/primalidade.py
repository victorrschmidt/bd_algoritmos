# Primalidade
# O(√N)

# Dado um número inteiro não negativo N, o algoritmo verifica se N é primo.

def primo(n: int) -> bool:
    if n < 2:
        return False

    i = 2
    while i * i <= n:
        if n % i == 0:
            return False
        i += 1

    return True
