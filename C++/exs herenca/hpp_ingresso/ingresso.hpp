#include <iostream>
#include <vector>
#include <string>


using namespace std;


class Ingresso{
private:
// atributos
string filme;
float valor;



public:
//metodos
Ingresso(float preco, string nome);

string preco_to_string();

float get_preco();

void set_preco(float novo_preco);

string get_string();

void set_string(string descricao);


};
