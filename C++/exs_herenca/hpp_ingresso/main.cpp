#include "ingresso.hpp"
int main(){

vector <Ingresso> bilhetes;

size_t i;
size_t qntd;
float preco;
string nome_filme;
float valor_total = 0;

cout << "Quantos ingressos deseja? ";
cin >> qntd;

for(i=0;i<qntd;i++){
    cout << "Digite o nome do filme" << endl;
    cin >> nome_filme;

    cout << "Digite o preco do ingresso" << endl;
    cin >> preco;

    Ingresso ingresso = Ingresso(preco, nome_filme);
    bilhetes.push_back(ingresso);

}

cout << "-------------------" << endl;
cout << "       TOTAL       " << endl;
cout << "-------------------" << endl;

for(i=0;i<bilhetes.size();i++){
    cout << "Filme      "  << " Preco " <<  endl;
    cout <<  bilhetes[i].get_string() << "      " << bilhetes[i].get_preco() << endl;
    valor_total += bilhetes[i].get_preco();

}
cout << "-------------------" << endl;
cout << "PRECO TOTAL = " << valor_total << endl; 



    return 0;
}