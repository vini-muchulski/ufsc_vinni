#include "circulo.hpp"



    
void Circulo::SetLado(float valor)
{


    raio = valor;


}

float Circulo::GetLado(){

    return raio;
}

float Circulo::Calcula_area(){
    return raio*raio*3.1415;
    
}
