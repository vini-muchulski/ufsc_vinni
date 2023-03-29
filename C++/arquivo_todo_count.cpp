#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <utility>
#include <algorithm>

using namespace std;

// le um arquivo e devolve o conteudo no tipo string
bool Read_file(string path, string &conteudo , vector<string> &vetorzao);


int main(){

int i,j;
string aux;

int cont_aux =0;

string filename("texto.txt");

string file_content = "";

//vetor onde cada elemento é uma linha do texto.txt
vector <string> vetorzao;

// inicializa o vetor dos caracteres e atribui valor inicial 0 para a quantidade de caracteres encontrado
vector <pair<string,int>>  caracteres;


for (i=0;i<256;i++){

    aux = static_cast<char>(i);
    caracteres.push_back(make_pair(aux,0));
    
}



if(Read_file(filename, file_content, vetorzao) == true){
    cout << "arquivo lido" << endl;
}
else{
    cout << "arquivo NAO lido" << endl;
}

cout << vetorzao.size() << endl;

/* for(i=0;i<vetorzao.size();i++){
 cout << vetorzao[i] << endl;

}*/



 // metodo count()


 for (j=0;j<256;j++){
    cont_aux = count(vetorzao[i].begin(), vetorzao[i].end(),caracteres[j].first);
    caracteres[j].second = cont_aux;
    //cout << cont_aux << endl;
    cont_aux = 0; 
} 



for (i=0;i<256;i++){

     cout << caracteres[i].first << "  " << caracteres[i].second <<  endl;
    
}

cout << file_content << endl;

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