#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Point2D{
//atributos
private:
    int x,y;



//metodos
public:
    void SetarX(int novo_x){
        x = novo_x;
    }

};

int main(){

Point2D ponto1;
ponto1.SetarX(20);

//Point2D ponto2();


    return 0;
}