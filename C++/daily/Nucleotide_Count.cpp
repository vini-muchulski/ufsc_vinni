
#include <iostream>
#include <vector>
#include <string>



using namespace std;

int main(){

string dna = "GATTACA";
int cont_a= 0;
int cont_g= 0;
int cont_c= 0;
int cont_t= 0;

for(char letra : dna){
    if(letra == 'A'){
        cont_a++;
    }
    else if(letra == 'G'){
        cont_g++;
    }

    else if(letra == 'C'){
        cont_c++;
    }

    else if(letra == 'T'){
        cont_t++;
    }

    else{
        cout << "INVALIDO" << endl;
    }
}

cout << "a: " << cont_a << endl;
cout << "g: " << cont_g << endl;
cout << "c: " << cont_c << endl;
cout << "t: " << cont_t << endl;


    return 0;
}

