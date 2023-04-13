#include "triangulo.hpp"

void Triangulo::SetLados(float v1, float v2, float v3){
        l1 = v1;
        l2 = v2;
        l3 = v3;
}

void Triangulo::GetSemiPerimetro(){
    semiperimetro = l1+l2+l3;

    semiperimetro = semiperimetro/2;

    

}

float Triangulo::Calcula_area(){

    GetSemiPerimetro();

    float area = sqrt(semiperimetro*(semiperimetro-l1)*(semiperimetro-l2)*(semiperimetro-l3));

    return area;

}