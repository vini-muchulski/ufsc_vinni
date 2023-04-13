#include <iostream>

using namespace std;

class Circle
{
//atributos
private:
    float ratio; //raio de um circle

//metodos
public:
    //getters and setters
    void SetRatio(float valor);
    float GetRatio();

    float CalcArea();

};

