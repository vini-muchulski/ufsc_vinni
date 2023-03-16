
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){

size_t i;
size_t aux;

vector <string> vetorzao;

vetorzao.push_back("vini");

vetorzao.push_back("olaa");

for(i=0;i<=vetorzao.size()-1;i++){

        cout << vetorzao[i];
        cout << " - Posicao = " << i <<endl;
        cout << " " << endl;

        aux = vetorzao[i].find("ini");

        if (aux != string::npos){
        cout << aux << endl;
        cout << " substring poss" << endl;
        }
    }



return 0;
}