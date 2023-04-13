#include "square.hpp"


void Square::SetLado(float valor)
{


    lado = valor;


}

float Square::GetLado(){

    return lado;
}

float Square::Calcula_area(){
    return lado*lado;
    
}
