#include <iostream>

#include <string>
#include <math.h>
#include "point2D.hpp"

using namespace std;

class Polygon{

    private:
    // atributos
    Point2D* shapeVertex;
    size_t numberOfVertex;

    public:
    // metodos
    Polygon();
    Polygon(size_t numero_vertices, Point2D* forma_vertices);

    ~Polygon();

    float find_area();
    float find_perimetro();

    void Set_pontos(size_t numero_vertices, Point2D* forma_vertices);
    
};

