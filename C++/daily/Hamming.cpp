
#include <iostream>
#include <vector>
#include <string>



using namespace std;

int main(){

string dna1 ="GAGCCTACTAACGGGAT";
string dna2 ="CATCGTAATGACGGCCT";
int distancia_hamming = 0;

for(size_t i =0; i<dna1.size(); i++){
    if(dna1[i] != dna2[i]){
        distancia_hamming++;
    }
}

cout <<" distancia = " <<distancia_hamming << endl;



    return 0;
}

