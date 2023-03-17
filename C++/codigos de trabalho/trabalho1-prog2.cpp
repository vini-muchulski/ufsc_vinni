//TRABALHO 1 DE LINGUAGEM DE PROGRAMAÇAO 2 - MARÇO DE 2023 - UFSC
// ALUNOS = Vinícius Wolosky Muchulski - Fernando Morreti

#include <iostream>
#include <vector>
#include <string>


using namespace std;




int main(){

vector<string> vetor_de_palavras;

int opcao = -1;
size_t i;
int ocorrencias = 0;
int indice_para_apagar;
size_t posicao_substring;

string palavra_adicionada;
string buscar_palavra;
string palavra_aux;






while(opcao != 0){

cout << " ------------------------------------------------------- " << endl;
cout << " " << endl;
cout << " UFxC String Store V.0 " << endl;
cout << " 1. Insert string //inserir uma palavra sem espaco e armazenar no vetor " << endl;
cout << " 2. Print index and string //imprimir index seguido da palavra " << endl;
cout << " 3. Search string (literal) //buscar por uma ou mais palavras na lista " << endl;
cout << " 4. Search substrings //buscar todas as substrings  " << endl;
cout << " 5. Remove string (by index) //remover um index do vetor " << endl;

cout << " " << endl;
cout << " 0. Quit " << endl;
cout << " " << endl;
cout << " ------------------------------------------------------- " << endl;

cin >> opcao;





switch (opcao)
{


case 1:
    cout << "Digite uma palavra" << endl;
    cin >> palavra_adicionada;
    vetor_de_palavras.push_back(palavra_adicionada);
    cout << " " << endl;

    break;




case 2:
    for(i=0;i<vetor_de_palavras.size();i++){
        cout << vetor_de_palavras[i];
        cout << " - Posicao = " << i <<endl;
        cout << " " << endl;
    }
    break;





case 3:
    cout << "Digite uma palavra para buscar: " << endl;
    cin >> buscar_palavra; 

    for(i=0;i<vetor_de_palavras.size();i++){

        if(buscar_palavra == vetor_de_palavras[i]){
            cout<< "A palavra " << buscar_palavra << "  foi encontrada na posicao " << i << endl;
            cout<< vetor_de_palavras[i] << endl;
            ocorrencias +=1;
        }

        if(i == vetor_de_palavras.size()-1 && ocorrencias == 0){
            cout<< "A palavra " << buscar_palavra << " NAO foi encontrada no vetor " << endl;
            break;
        }
        
    }
    
    ocorrencias = 0;
    break;




case 4:
    cout << "Digite uma palavra para buscar nas strings: " << endl;
    cin >> palavra_aux;
    


    for(i=0;i<vetor_de_palavras.size();i++){
        posicao_substring = vetor_de_palavras[i].find(palavra_aux);


        if(posicao_substring !=string::npos){
            cout << " foi encontrada a substring " << palavra_aux << "  palavra " << vetor_de_palavras[i] << " - Posicao = " << i <<endl;

        }
    }

    break;

    /* for(i=0; i<vetor_de_palavras.size()-1;i++){
        if(i == vetor_de_palavras[i].find(palavra_aux,i)){
            cout << "Substring " << "'" << palavra_aux << "'" << "Achada na posicao: " << i << endl ;
        }
    } 
    codigo do fernado */

    





case 5:
    cout << "Digite o indice a ser apagado" << endl;
    cin >> indice_para_apagar;

    vetor_de_palavras.erase(vetor_de_palavras.begin() + indice_para_apagar);

    break;

case 0:
    break;



}
}
    return 0;
}
