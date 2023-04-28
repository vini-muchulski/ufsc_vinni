
#include <iostream>
#include <vector>
#include <string>
#include <fstream>


#include <cstdlib>

// arquivo.open("square.txt", ios::app);
using namespace std;

int main(){
    string conteudo; 

    ifstream arquivo;
    arquivo.open("square.txt");

    //verificar se o arquivo leu;
    if(!arquivo.is_open()){
        cout<< "arquivo nao foi aberto " << endl;
        return 1;  
    }
    

    while (getline(arquivo, conteudo))
        {
            cout << conteudo << endl;
        }
    arquivo.close();

    system("pause");

    return 0;
}