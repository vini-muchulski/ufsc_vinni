#include <iostream>

using namespace std;

class Square
{
//atributos
private:
    float edge; //lado de um quadrado

//metodos
public:
    //getters and setters
    void SetEdge(float valor);
    float GetEdge();

    float CalcArea();

};
