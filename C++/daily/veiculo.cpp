
#include <iostream>
#include <vector>
#include <string>




using namespace std;


class Veiculo{
protected:
size_t vel_max;


public:

Veiculo(size_t velocidade=0){
    vel_max=velocidade;
}

virtual void velocidade_max(){
cout << "Veiculo -" << "Velocidade Max = " << vel_max << endl;
}

size_t get_vel(){
    return vel_max;
}

};




class Carro: public Veiculo{

public:
Carro(size_t velocidade=0): Veiculo(velocidade){}


void velocidade_max() override {
    cout << "Carro -" << "Velocidade Max = " << get_vel() << endl;
}
};

class Aviao: public Veiculo{
    protected:
    int n_motores;

    public: 
    
    Aviao(size_t velocidade=0, int numero_motores=1): Veiculo(velocidade){
        n_motores=numero_motores;
    }

    void velocidade_max() override{
        size_t vel = get_vel()*n_motores;
        cout << "Aviao -" << "Velocidade Max = " << vel << endl;
    }


};
int main(){

    Veiculo v1(100);
    Carro c1(200);
    Aviao a1(300,2);
    Aviao a2(400,4);

    vector<Veiculo*> veiculos;
    veiculos.push_back(&v1);
    veiculos.push_back(&c1);
    veiculos.push_back(&a1);
    veiculos.push_back(&a2);

    for(size_t i = 0; i < veiculos.size();i++){
        veiculos[i]->velocidade_max();
    }





    return 0;
}