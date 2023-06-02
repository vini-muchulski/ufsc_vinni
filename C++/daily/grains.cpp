
#include <iostream>
#include <vector>
#include <string>


//Calcule o número de grãos de trigo em um tabuleiro de xadrez, dado que o número em cada quadrado dobra.

using namespace std;

int main(){



int i;
long long numero_de_graos = 1;
vector <long long> quadrados;

quadrados.push_back(numero_de_graos);

for(i=2;i<=64;i++){
    numero_de_graos = numero_de_graos * 2;
    quadrados.push_back(numero_de_graos);
}



for(i=0;i<64;i++){
    cout << "Casa " << i << " : "<< quadrados[i] << endl;
}

    return 0;
}


