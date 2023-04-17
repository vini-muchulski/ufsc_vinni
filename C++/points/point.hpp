#include <iostream>


using namespace std;


class Point{

    private:
    int m_x,m_y;

    public:
Point();
Point(int x, int y);
~Point();

int GetX();
int getY();

void SetX(int x);

void Sety(int y);

};