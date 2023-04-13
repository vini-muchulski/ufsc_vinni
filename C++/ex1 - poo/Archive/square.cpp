#include "square.hpp"

void Square::SetEdge(float valor)
{
    edge = valor;
}

float Square::GetEdge()
{
    return edge;
}

float Square::CalcArea()
{
    return edge*edge;
}
