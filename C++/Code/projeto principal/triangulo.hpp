#ifndef TRIANGULO_HPP_INCLUDED
#define TRIANGULO_HPP_INCLUDED

#include <iostream>

#include <math.h>

using namespace std;

class Triangulo{
private:

    float l1;
    float l2;
    float l3;

    float semiperimetro;

public:

    void SetLados(float v1, float v2, float v3);


    void GetSemiPerimetro();

    float Calcula_area();


};

#endif // TRIANGULO_HPP_INCLUDED