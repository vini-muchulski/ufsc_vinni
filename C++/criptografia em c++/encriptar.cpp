#include <iostream>
#include <vector>
#include <utility>
#include <fstream>

using namespace std;

vector< pair <char , char>  > cria_tabela( int deslocamento);

string encriptar( string texto, vector < pair< char, char > > tabela_de_conversao);

void print_vector(vector < pair< char, char > > vetor_funcao);

//bool Read_file(string path, string &conteudo);




int main(){

   string file_content = "";
    string text = "Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";

    //string filename("lorem.txt");  
/*

// inicializa a leitura do arquivo
    if(Read_file(filename, file_content) == true){
        cout << "arquivo lido" << endl;
    }
    else{
        cout << "arquivo NAO lido" << endl;
*/


    vector < pair< char, char > > tabela_de_conversao;

    tabela_de_conversao = cria_tabela(10);

    print_vector(tabela_de_conversao);

    file_content = encriptar(text, tabela_de_conversao);

    cout << "Texto encriptado: " << file_content << endl;

    return 0; 
}




vector< pair <char , char>  > cria_tabela( int deslocamento){
    vector < pair< char, char > > vetorzao(256);

    
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

    return texto;
}


/* 
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

}*/