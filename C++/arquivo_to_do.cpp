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

//vetor onde cada elemento é uma linha do texto.txt
vector <string> vetorzao;

int i,j;
string aux;

int cont_aux =0;


// inicializa o vetor dos caracteres e atribui valor inicial 0 para a quantidade de caracteres encontrado
vector <pair<string,int>>  caracteres;

for (i=0;i<256;i++){

    aux = static_cast<char>(i);
    caracteres.push_back(make_pair(aux,0));
    
}
/*for (i=0;i<256;i++){

     cout << caracteres[i].first << "  " << caracteres[i].second <<  endl;
    
}*/
 // metodo count()

 for (i=0;i<vetorzao.size();i++){
    

    for (j=0;j<256;j++){
    cont_aux = vetorzao[i].count(vetorzao[i].begin(), vetorzao[i].end(),caracteres[j].first);
    


    
}

    
}






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