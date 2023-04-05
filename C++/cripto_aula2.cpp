#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector< pair <char , char>  > cria_tabela( int deslocamento);

string encriptar( string texto, vector < pair< char, char > > tabela_de_conversao);

void print_vector(vector < pair< char, char > > vetor_funcao);




int main(){
    vector < pair< char, char > > tabela_de_conversao;

    tabela_de_conversao = cria_tabela(1);

    print_vector(tabela_de_conversao);



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
    int i;
    
    for (i=0;i<vetorzao.size();i++){

     cout << vetorzao[i].first << "  " << vetorzao[i].second <<  endl;
}
}




string encriptar( string texto, vector < pair< char, char > > tabela_de_conversao){
    size_t i;

     for(size_t i=0; i<texto.size(); i++)
    {
        char ch = texto.at(i);
        texto.at(i) = chCount.at(ch).second++;
        
    }
}


  
