#include "ingresso.hpp"


 Ingresso::Ingresso(float preco, string nome){
    valor = preco;
    filme = nome;
}

 string Ingresso::preco_to_string(){
    string preco = to_string(valor);
    return preco;
 }

 float  Ingresso::get_preco(){
    return valor;
 }

    void  Ingresso::set_preco(float novo_preco){
    valor = novo_preco;
 }

 string  Ingresso::get_string(){
    return filme;
     }
void  Ingresso::set_string(string descricao){
    filme = descricao;
}




