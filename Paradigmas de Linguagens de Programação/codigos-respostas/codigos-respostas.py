from functools import reduce
import csv

# Questão 1 - a)
numeros = list(map(lambda x: x * 2, [1, 5, 8, 10]))
print(numeros)

# Questão 1 - b)
numeros = list(filter(lambda x: x % 2 == 0, [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20]))
print(numeros)

# Questão 1 - c)
nomes = list(map( lambda nome: nome.upper(), ["aang","katara","toph","sokka"]))
print(nomes)

# Questão 1 - d)
remover = list(map(lambda string: string.strip(), [" python", " funcional ", "paradigma "]))
print(remover)

# Questão 2 - a)
somar = reduce(lambda x, y: x + y, [1,2,3,4,5,6])
print(somar)

# Questão 2 - b)
produto = reduce(lambda x, y: x * y, [1,2,3,4,5,6])
print(produto)

# Questão 2 - c)
maior = reduce(lambda x, y: x if x > y else y , [1,2,3,4,5,6])
print(maior)

# Questão 2 - d)
filtrar = list(map( lambda x: x * 2, filter(lambda x: x > 5, [1,3,4,6,8,9])))
print(filtrar)

# Questão 3 - a)
ler_csv = lambda caminho: list(csv.DictReader(open(caminho, encoding="utf-8")))
converter_linha = lambda r: (int(r["id"]), float(r["valor"]), int(r["quantidade"]))
carregar_emprestimos = lambda caminho: list(map(converter_linha, ler_csv(caminho)))
com_juros = lambda emprestimo: (emprestimo[0], round(emprestimo[1] * 1.1, 2), emprestimo[2])
acima_de_1000 = lambda emprestimo: emprestimo[1] > 1000
processar = lambda caminho: list(map(com_juros, filter(acima_de_1000, carregar_emprestimos(caminho))))
print(processar("emprestimos.csv"))

# Questão 3 - b)
nomes = list(map( lambda x: (x[0], x), ["Aang", "Katara", "Toph", "Sokka"]))
print(nomes)

# Questão 3 - c)
fibo = lambda x: x if x <= 1 else fibo(x-1) + fibo(x-2)
resultado = list(map(fibo, range(10)))
print(resultado)