lista = list()

for i in range (0,5):
    numero = int(input(f"Digite o {i}° valor: "))
    lista.append(numero)

lista.sort(reverse=True)

maior = lista[0]

lista.sort()

menor = lista[0]
print(f"O maior foi {maior} e o menor {menor}")