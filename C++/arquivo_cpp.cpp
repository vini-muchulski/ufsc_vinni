// contar todos os caracteres do texto

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <utility>

using namespace std;

// le um arquivo e devolve o conteudo no tipo string
bool Read_file(string path, string &conteudo);


// std::  vector <pair<int,int>> tabela

int main(){

string filename("texto.txt");

string file_content = "";



if(Read_file(filename, file_content) == true){
    cout << "arquivo lido" << endl;
}
else{
    cout << "arquivo NAO lido" << endl;
}

cout << file_content << endl;

    return 0;
}


bool Read_file(string path, string &conteudo){

    ifstream filereader(path);

    if(!filereader.is_open()){
        return false;
    }


    string tmp;

    while( getline(filereader, tmp)){
        conteudo +=tmp;
    }
    cout << tmp << endl;


    // to do - contar no texto a frequencia de cada caracter - a - b - c ...

    filereader.close();


    return true;

}