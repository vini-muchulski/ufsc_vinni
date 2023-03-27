//TRABALHO 1 DE LINGUAGEM DE PROGRAMAÇAO 2 - MARÇO DE 2023 - UFSC
// ALUNOS = Vinícius Wolosky Muchulski - Fernando Morreti

#include <iostream>         //bibliotecas de funcao
#include <vector>
#include <string>


using namespace std;




int main(){                                 //declaracao de variaveis

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

cout << " ------------------------------------------------------- " << endl;                    //menu
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
    cout << "Digite uma palavra" << endl;               //usuario insere o argumento e a funcao push_back coloca a palavra inserida na vector
    cin >> palavra_adicionada;
    vetor_de_palavras.push_back(palavra_adicionada);
    cout << " " << endl;

    break;




case 2:
    for(i=0;i<vetor_de_palavras.size();i++){            //Estrutura de repeticao que imprime todas as palavras adicionadas e suas posicoes na vector
        cout << vetor_de_palavras[i];
        cout << " - Posicao = " << i <<endl;
        cout << " " << endl;
    }
    break;





case 3:
    cout << "Digite uma palavra para buscar: " << endl;        //Argumento inserido pelo usuario que vai buscar a string
    cin >> buscar_palavra; 

    for(i=0;i<vetor_de_palavras.size();i++){                    //Estrutura de repeticao que vai passar pela vector e buscar a string inserida

        if(buscar_palavra == vetor_de_palavras[i]){                                         //Condicao onde a palavra inserida esta na vector, logo ela é impressa na tela com sua posicao respectiva
            cout<< "A palavra " << buscar_palavra << "  foi encontrada na posicao " << i << endl;
            
            ocorrencias +=1;
        }

        if(i == vetor_de_palavras.size()-1 && ocorrencias == 0){                            //Condicao negativa onde a palavra nao esta na vector, logo é impresso um aviso que diz que a palavra nao esta na vector
            cout<< "A palavra " << buscar_palavra << " NAO foi encontrada no vetor " << endl;
            break;
        }
        
    }
    
    ocorrencias = 0;
    break;




case 4:
    cout << "Digite uma palavra para buscar nas strings: " << endl;             //argumento inserido pelo usuario salvo na string
    cin >> palavra_aux;                                                         //para buscar palavra na vector string
    


    for(i=0;i<vetor_de_palavras.size();i++){                                    //Estrutura de repeticao para verificar
        posicao_substring = vetor_de_palavras[i].find(palavra_aux);             //palavra inserida pelo usuario na vector


        if(posicao_substring !=string::npos){                                                                                                  //Condicao que se cumprida, printa na tela
            cout << " foi encontrada a substring " << palavra_aux << "  palavra " << vetor_de_palavras[i] << " - Posicao = " << i <<endl;      //Posicao na string e a palavra se achada

        }
    }

    break;



    





case 5:
    cout << "Digite o indice a ser apagado" << endl;    //Argumento inserido é salvo em int
    cin >> indice_para_apagar;

    vetor_de_palavras.erase(vetor_de_palavras.begin() + indice_para_apagar);      //funcao que passa pela vector e apaga a palavra na posicao inserida

    break;

case 0:
    break;



}
}
    return 0;
}