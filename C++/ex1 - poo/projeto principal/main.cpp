
#include <iostream>
#include <vector>
#include <string>

#include "square.hpp"
#include "circulo.hpp"
#include "triangulo.hpp"

#include <cstdlib>

// g++ main.cpp circulo.cpp square.cpp triangulo.cpp -o main.exe 

using namespace std;

int main(){

    Square quadrado1;

    quadrado1.SetLado(5);

    cout << " area : " << quadrado1.Calcula_area() << endl;

    Triangulo t1;
    t1.SetLados(3,4,5);

    cout << " t1 area : " << t1.Calcula_area() << endl;


    Circulo c1;
    c1.SetLado(1);
    cout << " t1 area : " << c1.Calcula_area() << endl;

system("pause");


    return 0;
}