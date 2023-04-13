#include "square.hpp"
#include "circle.hpp"
#include "triangle.hpp"
#include <math.h>

#include <cstdlib>


#include <iostream>

using namespace std;

// "${workspaceFolder}/*.cpp"

int main()
{
    Square sq1;
    sq1.SetEdge(5);
    cout << "Square 1. Edge: " << sq1.GetEdge() << " Area: " << sq1.CalcArea() << endl;

    Square sq2;
    sq2.SetEdge(10);
    cout << "Square 2. Edge: " << sq2.GetEdge() << " Area: " << sq2.CalcArea() << endl;

    Square sq3;
    sq3.SetEdge(20);
    cout << "Square 3. Edge: " << sq3.GetEdge() << " Area: " << sq3.CalcArea() << endl;

    Circle ci1;
    ci1.SetRatio(4);
    cout << "Circle 1. Ratio: " << ci1.GetRatio() << " Area: " << ci1.CalcArea() << endl;

    Triangle tr1;
    tr1.SetEdges(1,1,1.4142);
    cout << "Triangle 1. Area: " << tr1.CalcArea() << endl;

    system("pause");

    return 0;
}
