#include <iostream>
#include <math.h>

using namespace std;

class Triangle
{
//atributos
private:
    float e1,e2,e3; //lados de um triangulo
    float sp; //semiperimeter


//metodos
private:
    void CalcSemiperimeter();


public:
    //getters and setters
    void SetEdges(float v1,float v2,float v3);
    //float GetRatio();

    float CalcArea();

};
