
#include <iostream>
#include <vector>
#include <string>

#include <sstream>

#include <iomanip>





using namespace std;


class Cliente{
    //atributos
    private:
    string nome;
    string endereco;
    string profissao;
    float salario;

    public:
   // Cliente() : nome(""),endereco("") , profissao("")  , salario(0) {};
   Cliente(string n, string ender="", string prof="", float salr=0 ){
    nome = n;
    endereco = ender;
    profissao = prof;
    salario =salr;
   }

    string get_nome(){
        return nome;
    }

    string get_endereco(){
        return endereco;
    }

    string get_profissao(){
        return profissao;
    }

    float get_salario(){
        return salario;
    }



   string Get_info(){
    //string palavra = nome + endereco + profissao + to_string(salario);
    //return palavra;
    stringstream palavra;

    palavra << "Cliente: " << nome << " Endereco: " << endereco << " Profissao: " << profissao <<  " Salario: " << fixed << setprecision(2) << salario << " \n";

    return palavra.str();
   }

};

class ContaCorrente{
    protected:
    Cliente *m_cliente; //variaveis estaticas que tem seu endereço passado para um ponteiro nao precisam ser limpas
    float m_saldo;

    public:
    ContaCorrente(Cliente *cliente , float saldo){
        m_cliente = cliente;
        m_saldo = saldo;
    }

    void Show_info(){

    }

    string Get_info_cc(){
    //string palavra = nome + endereco + profissao + to_string(salario);
    //return palavra;
    stringstream palavra;

    palavra << "Cliente: " << m_cliente->get_nome() << " Endereco: " << m_cliente->get_endereco() << " Profissao: " << m_cliente->get_profissao() <<  " Salario: " << fixed << setprecision(2) << m_cliente->get_salario() <<   " Limite: " << fixed << setprecision(2) << m_saldo << " \n";

    return palavra.str();
   }
 void depositar(float valor){
    m_saldo += valor;

 }

 void operator+=(float valor){
    depositar(valor);
 }
    ~ContaCorrente(){}


    // sacar
    // trasnferir 
    // transferir tudo
};

class Conta{
// atributos
private:
float saldo;

public:
// metodos

};
int main(){

Cliente c1("Vini","Mars","Eng",2710);

Cliente c3("Levi");
Cliente c2("Eren Jager", "Paradis");

cout << c1.Get_info() << endl;
cout << c2.Get_info() << endl;
cout << c3.Get_info() << endl;

ContaCorrente conta1(&c1,5000);

cout <<  conta1.Get_info_cc() << endl;

/* Cliente *cliente6 = new Cliente("Apeiron","Earth", "AstroNaut", 5000);
ContaCorrente conta2(cliente6,10000);

delete cliente6; */




    return 0;
}