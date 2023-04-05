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

int letra;
char aux;

int aux_int;
//string string_aux;



string filename("texto.txt");

string file_content = "";


// inicializa o vetor dos caracteres e atribui valor inicial 0 para a quantidade de caracteres encontrado
vector <pair<string,int> > caracteres;
for (i=0;i<256;i++){
    aux = static_cast<char>(i);

    string string_aux = string(1,aux);

    caracteres.push_back(make_pair(string_aux,0));    
}





// inicializa a leitura do arquivo
if(Read_file(filename, file_content) == true){
    cout << "arquivo lido" << endl;
}
else{
    cout << "arquivo NAO lido" << endl;
}



// contagem de caracteres repetidos
int tamanho = file_content.size();

for(i=0;i<256;i++){
    for(letra=0;letra<tamanho;letra++){
        if(caracteres[i].first[0] == file_content[letra]){
            caracteres[i].second +=1;
        }
    }
}





// remover zeros

for(i=caracteres.size()-1;i>0; i--){
    if (caracteres[i].second == 0){
        caracteres.erase(caracteres.begin() + i);
    }
}



// ordena vetor 


//sort(caracteres.second.begin(), caracteres.second.end());

for (size_t v =1 ; v<caracteres.size(); v++){
    for(i=0;i<caracteres.size()-1;i++){

        if (caracteres[i].second<caracteres[i+1].second){
            aux_int = caracteres[i].second;
            string aux_string = caracteres[i].first;


            caracteres[i].second= caracteres[i+1].second;
            caracteres[i].first = caracteres[i+1].first;

            caracteres[i+1].second = aux_int;
            caracteres[i+1].first = aux_string;
    }
    }
}



// size_t do codigo
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




// ordenar o vetor em funcao do segundo elemento em ordem decrescente;
// como usar o sort, stable_sort;

//encriptador;