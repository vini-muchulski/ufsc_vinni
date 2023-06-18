
#include <iostream>
#include <vector>
#include <string>



using namespace std;

int main(){

string dna = "ACGTGGTCTTAA";

size_t i;
string rna_mensageiro ="";

for(i=0;i<dna.size();i++){
    if(dna[i] == 'G'){
        rna_mensageiro+="C";
    };

    if(dna[i] == 'C'){
        rna_mensageiro+="G";
    };

    if(dna[i] == 'T'){
        rna_mensageiro+="A";
    };

    if(dna[i] == 'A'){
        rna_mensageiro+="U";
    };
}

cout << "RNA = " << rna_mensageiro << endl;


    return 0;
}

