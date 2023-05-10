
#include <iostream>
#include <vector>
#include <string>


//#include <cstdlib>

using namespace std;



class Empregado{
// atributos
private:
    string nome;


protected:
float salario;


public:
//metodos

Empregado(string nome_parametro, float salario_parametro){
    nome = nome_parametro;
    salario = salario_parametro;
}

void set_salario(float novo_salario){
    salario = novo_salario;
}

void set_nome(string novo_nome){
    nome = novo_nome;
}

float get_salario(){
    return salario;
}

string get_nome(){
    return nome;
}

void salario_ToString(){
    cout << "NOME: " << get_nome() << "\nSalario: " << get_salario() << endl;
}

};






class Gerente : public Empregado{
// atributos
private:
string depto;

public:
//metodos

Gerente(string departamento , string nome_parametro, float salario_parametro) : Empregado(nome_parametro,salario_parametro){
    depto = departamento;
}


void set_salario_gerente(float novo_salario){
    set_salario(novo_salario);

}

void set_nome_gerente(string novo_nome){
    set_nome(novo_nome);
}

float get_salario_gerente(){
    return get_salario();
}

string get_nome_gerente(){
    return get_nome();
}

void salario_ToString_gerente(){
    
    cout << "NOME: " << get_nome() << "\nDepartamento: " << depto << "\nSalario: " << get_salario_gerente() << endl;

   
}
};


class Vendedor: public Empregado{
private:
float percentual_comissao = 0;
float salario_sem_comissao = 0;

public:

Vendedor(string nome_parametro, float salario_parametro, float comissao): Empregado(nome_parametro,salario_parametro){
 percentual_comissao = (comissao/100);
 salario_sem_comissao = salario_parametro;

}

void set_salario_vendedor(float novo_salario){
    set_salario(novo_salario);

}

void set_nome_vendedor(string novo_nome){
    set_nome(novo_nome);
}

float get_salario_vendedor(){
    return get_salario();
}

string get_nome_vendedor(){
    return get_nome();
}

void calcular_salario(){
    float salario_temp = salario_sem_comissao * (1 + percentual_comissao);
    set_salario_vendedor(salario_temp);

}
void toString_vendedor(){
        cout << "NOME: " << get_nome() << "\nSALARIO sem COMISSAO: " << salario_sem_comissao << "\nSALARIO com COMISSAO: " << get_salario_vendedor() << "\nPERCENTUAL DE COMISSAO: %" << percentual_comissao << endl;

}

};





int main(){

Vendedor vend1 = Vendedor("Vini ", 1000, 5);

vend1.calcular_salario();

vend1.toString_vendedor();

cout << "\n----------------------------\n" << endl;
cout<< "GERENTE" << endl;

Gerente gerent1 = Gerente("Aero", "Levi", 5000);

gerent1.salario_ToString_gerente();

cout << "\n----------------------------\n" << endl;
cout<< "EMPREGADO" << endl;

Empregado emp1 = Empregado("Kira", 2000);
emp1.salario_ToString();


 


//system("pause");


    return 0;
}