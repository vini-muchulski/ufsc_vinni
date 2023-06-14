#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool is_prime(int n){
    int divisores = 0;
    if (n<2){
        return false;
    }
    for(int i=1;i<=n;i++){
        if(n%i==0){
            divisores++;
        }
    }

    if(divisores == 2){
        return true;
    }
    else{
        return false;
    }
}

int main(){

int maior_primo = 2;

vector<int> lista_numeros;
lista_numeros.push_back(2);
lista_numeros.push_back(3);
lista_numeros.push_back(5);
lista_numeros.push_back(7);
lista_numeros.push_back(11);
lista_numeros.push_back(15);

for(size_t i =0;i<lista_numeros.size();i++){
    if(is_prime(lista_numeros[i])){
        if(lista_numeros[i]>maior_primo){
            maior_primo = lista_numeros[i];
        }
    }

}

cout << "Maior numero primo na lista eh = " << maior_primo << endl;

return 0;

}