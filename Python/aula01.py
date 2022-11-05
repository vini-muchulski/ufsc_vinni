print("Agora são %d e %d da manhã"%(9,30))

print("Ola, sou o vini! tenho 19 anos! Ad Astra!")

"""Vamos criar uma calculadora? Armazene dois números inteiros em variáveis e imprima as respostas das seguintes operações:

Soma dos dois números;
Multiplicação dos dois números;
Divisão dos dois números;
Subtração dos dois números."""

x = 5 
y =2

print(f"Soma de {x} e {y} = {x+y} ")
print(f"Multiplicação de {x} e {y} = {x*y} ")
print(f"Divisao de {x} e {y} = {x/y} ")
print(f"Subtração de {x} e {y} = {x-y} ")


a = 1 
b = 3
if (a>b):
    print("A é maior que B")
else:
    print("B é maior que A")



for i in range(5):
    print("Vinni")



base =2
expoente = 3
resultado = 1
contador = 1

while(contador <=expoente):
    resultado = resultado * base
    contador +=1
    
print(f"{base}**{expoente} = {resultado}")


print("*"*30)


def soma(a,b):
    return a+b

def subtrai(a,b):
    return a-b

def multiplica(a,b):
    return a*b

def divide(a,b):
    return a/b

print((soma(a,b)))

