#include <iostream>

using namespace std;

int verifica_se_eh_primo(int numero){
    int i;
    int divisores = 0;
    

    for(i=1;i<=numero;i++){
        
        
        
        if( numero % i == 0){
            divisores++;
        }

    }
    cout << "divisores " << divisores << endl;

    return divisores;
}

int main(){


    int numero;
    int resposta;

    cout << "Digite um numero: " << endl;
    cin >> numero;

    resposta = verifica_se_eh_primo(numero);

   
    

    return 0;
}