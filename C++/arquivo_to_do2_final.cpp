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

int i,j;

int letra;
char aux;
//string string_aux;



string filename("texto.txt");

string file_content = "";


// inicializa o vetor dos caracteres e atribui valor inicial 0 para a quantidade de caracteres encontrado
vector <pair<string,int>>  caracteres;

for (i=0;i<256;i++){

    aux = static_cast<char>(i);

    string string_aux = string(1,aux);

    caracteres.push_back(make_pair(string_aux,0));
    
}



if(Read_file(filename, file_content) == true){
    cout << "arquivo lido" << endl;
}
else{
    cout << "arquivo NAO lido" << endl;
}




int tamanho = file_content.size();




for(i=0;i<256;i++){
    for(letra=0;letra<tamanho;letra++){
        if(caracteres[i].first[0] == file_content[letra]){
            caracteres[i].second +=1;
        }
    }
}

for (i=0;i<256;i++){

     cout << caracteres[i].first << "  " << caracteres[i].second <<  endl;
    
}



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
    

    filereader.close();


    return true;

}