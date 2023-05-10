
#include <iostream>
#include <vector>
#include <string>


using namespace std;



class Ingresso{
protected:
// atributos
string filme;
float valor;



public:
//metodos
Ingresso(float preco, string nome){
    valor = preco;
    filme = nome;
}

 string preco_to_string(){
    string preco = to_string(valor);
    return preco;
 }

 float get_preco(){
    return valor;
 }

    void set_preco(float novo_preco){
    valor = novo_preco;
 }

 string get_string(){
    return filme;
     }
void set_string(string descricao){
    filme = descricao;
}


};

class Ingresso_VIP : public Ingresso{
    protected:
    float valor_add;

    public:
    Ingresso_VIP(float valor_adicional, float preco, string nome) : Ingresso(preco, nome) {
    valor_add = valor_adicional;
    set_preco(preco + valor_add);
}

    float get_preco_vip(){
        return get_preco();
    }

    void set_preco_vip(float preco, float valor_extra){
    valor_add = valor_extra;
    set_preco(preco + valor_add);
    }






};



int main(){

 Ingresso_VIP ing_vp = Ingresso_VIP(5,20,"Vingadores");

 cout<< "nome:  " << ing_vp.get_string() << "\npreco: " << ing_vp.get_preco_vip() << endl; 



    return 0;
}