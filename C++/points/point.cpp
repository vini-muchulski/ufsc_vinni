
#include <iostream>
#include "point.hpp"

using namespace std;




Point::Point(int x, int y){
    m_x = x;
    m_y = y;

    cout << "contrutor com parm" << endl;
}

int Point::GetX(){
    return m_x;
}
int Point::getY(){
    return m_y;
}

void Point::SetX(int x){
    m_x = x;
}

void Point::Sety(int y){
    m_y = y;
}

Point::~Point(){
cout << "destrutor -- " << endl;
}



