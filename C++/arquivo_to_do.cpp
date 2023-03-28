// contar todos os caracteres do texto

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <utility>

using namespace std;

// le um arquivo e devolve o conteudo no tipo string
bool Read_file(string path, string &conteudo , vector<string> &vetorzao);


// std::  vector <pair<int,int>> tabela






int main(){

string filename("texto.txt");

string file_content = "";

vector <string> vetorzao;



if(Read_file(filename, file_content, vetorzao) == true){
    cout << "arquivo lido" << endl;
}
else{
    cout << "arquivo NAO lido" << endl;
}

//cout << file_content << endl;

cout << vetorzao.size() << endl;



    return 0;
}









bool Read_file(string path, string &conteudo, vector<string> &vetorzao){

    

    ifstream filereader(path);

    if(!filereader.is_open()){
        return false;
    }


    string tmp;

    while( getline(filereader, tmp)){
        conteudo +=tmp;
        conteudo +='\n';

        //cout << tmp << endl;

        vetorzao.push_back(conteudo);
    }
    //cout << tmp << endl;


    // to do - contar no texto a frequencia de cada caracter - a - b - c ...

    filereader.close();


    return true;

}