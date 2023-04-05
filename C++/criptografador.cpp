#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <utility>
#include <algorithm>

using namespace std;

// le um arquivo e devolve o conteudo no tipo string
bool Read_file(string path, string &conteudo);


int main(){

size_t i;
char aux;
char cifra_indice;

string filename("lorem.txt");

string file_content = "";

// inicializa a leitura do arquivo
if(Read_file(filename, file_content) == true){
    cout << "arquivo lido" << endl;
}
else{
    cout << "arquivo NAO lido" << endl;
}


// inicializa o vetor dos caracteres 
vector <pair<char,char> > caracteres;


for (i=0;i<256;i++){
    aux = static_cast<char>(i);

    cifra_indice =  static_cast<char>(i+3);

    caracteres.push_back(make_pair(aux,cifra_indice));    
}


// print vector
for (i=0;i<caracteres.size();i++){
     cout << caracteres[i].first << "  " << caracteres[i].second <<  endl;
}




    return 0;
}


bool Read_file(string path, string &conteudo){

    
     // path.c_str()
    ifstream filereader(path.c_str());

    if(!filereader.is_open()){
        return false;
    }


    string tmp;

    while( getline(filereader, tmp)){
        conteudo +=tmp;
       
    }
    

    filereader.close();


    return true;

}