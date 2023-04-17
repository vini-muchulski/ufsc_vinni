
#include <iostream>
#include <vector>
#include <string>


#include <cstdlib>

#include "point.hpp"

using namespace std;

int main(){
Point p1 = Point(2,2);
Point p2 = Point(4,4);
Point p3 = Point(0,0);

vector <Point> myShap1;
myShap1.push_back(p1);
myShap1.push_back(p2);
myShap1.push_back(p3);

for( size_t i=0; i < myShap1.size(); i++){
    cout<< "point x " << myShap1[i].GetX() << " y " << myShap1[i].getY() << endl; 
}

system("pause");


    return 0;
}