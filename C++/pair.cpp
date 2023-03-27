#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <utility>

using namespace std;



// std::  vector <pair<int,int>> tabela

// tabela.push_back(make_pair(20,200)) slide 10 pair


int main(){

vector <pair<string,int>> tabela;

int idade;
size_t i;
string nome;


for ( i = 0; i<3;i++){
    cout << "Digite um nome: " << endl;
    cin >> nome;

     cout << "Digite uma idade: " << endl;
     cin >> idade;

     tabela.push_back(make_pair(nome,idade));


}  

for ( i = 0; i<tabela.size();i++){
    cout << "nome  " << tabela[i].first<< " idade  " << tabela[i].second<< endl;


} 



    return 0;
}