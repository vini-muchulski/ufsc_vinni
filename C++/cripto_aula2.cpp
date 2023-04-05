#include <iostream>
#include <vector>
#include <utility>
#include <fstream>

using namespace std;

vector< pair <char , char>  > cria_tabela( int deslocamento);

string encriptar( string texto, vector < pair< char, char > > tabela_de_conversao);

void print_vector(vector < pair< char, char > > vetor_funcao);

bool Read_file(string path, string &conteudo);




int main(){

    string filename("lorem.txt");

    string file_content = "";

// inicializa a leitura do arquivo
    if(Read_file(filename, file_content) == true){
        cout << "arquivo lido" << endl;
    }
    else{
        cout << "arquivo NAO lido" << endl;
    }



    vector < pair< char, char > > tabela_de_conversao;

    tabela_de_conversao = cria_tabela(1);

    print_vector(tabela_de_conversao);

    file_content = encriptar(filename, tabela_de_conversao);

    cout << file_content << endl;



    return 0; 
}









vector< pair <char , char>  > cria_tabela( int deslocamento){
    vector < pair< char, char > > vetorzao(256);

    char aux;
    char cifra_indice;
    size_t i;

    for (i=0;i<256;i++)
    {
    vetorzao.at(i).first = i; 
    vetorzao.at(i).second = i + deslocamento; 
    }

    return vetorzao;


}


void print_vector(vector < pair< char, char > > vetorzao){
    size_t i;
    
    for (i=0;i<vetorzao.size();i++){

     cout << vetorzao[i].first << "  " << vetorzao[i].second <<  endl;
}
}




string encriptar( string texto, vector < pair< char, char > > tabela_de_conversao){
    

     for(size_t i=0; i<texto.size(); i++)
    {
        char ch = texto.at(i);
        texto.at(i) = tabela_de_conversao.at(ch).second++;
        
    }
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