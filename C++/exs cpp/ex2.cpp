/*A famosa conjetura de Goldbach diz que todo inteiro par maior que 2 é a soma de dois números primos. 
Testes extensivos foram feitos sem, contudo, ser encontrado um contra-exemplo. 
Escreva um programa mostrando que a afirmação é verdadeira para todo número par entre 700 e 1100. 
O programa deve imprimir cada número e os seus correspondentes primos. */


#include <iostream>
#include <vector>
#include <string>


#include <cstdlib>

using namespace std;

int verifica_primo(int numero);

int main(){



int i,a;

for(i=700;i<=1100;i+=2){
    for (int j= 1; j<i;j++){
        a = i - j;
        if(verifica_primo(j) == 1 && verifica_primo(a) == 1){
            cout << j << " + " << a << " = " << i << endl;
            break;
        }
    }

}

/*int teste = verifica_primo(8);

if(teste == 1){
    cout << "EH PRIMO" << endl;
}
else{
    cout << "NAO EH PRIMO" << endl;
}*/




    return 0;
}


// recebe um inteiro positivo e, se este número for primo, retorne 1, caso contrário retorne 0.

int verifica_primo(int numero){
    int i;
    int divisores =0;

    for (i=1;i<=numero;i++){
        if(numero%i == 0){
            divisores++;
        }
    }

    if(divisores == 2){
        return 1;
    }
    else{
        return 0;
    }
}