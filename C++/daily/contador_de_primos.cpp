#include <iostream>
#include <cstdlib>
#include <ctime>
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

vector <int> numeros;
int num;
int qnt_primos=0;

 srand(time(0)); // semente para o gerador de números aleatórios
for(int i=0;i<10;i++){
    // inicializa o gerador de números aleatórios
     num = rand() % 100 + 1; // gera um número aleatório de 1 a 100
    cout << num << " ";
    if(is_prime(num)){
        qnt_primos++;
        numeros.push_back(num);
    }
    
}

cout << endl;
cout << "Quantidade de primos: " << qnt_primos << endl;
for (size_t i = 0; i < numeros.size(); i++)
{
    cout << numeros[i] << " ";
}



    




    return 0;
}