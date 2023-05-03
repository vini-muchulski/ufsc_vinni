
#include <iostream>
#include <vector>
#include <string>


#include <cstdlib>

using namespace std;

class Box{
    protected:
// atributos
float comprimento,altura,largura;

    public:
Box(){
    comprimento = 0;
    largura = 0;
    altura = 0;
    cout << "eu sou uma caixa " << endl;

}
Box(int comp, int alt, int larg){
 comprimento = comp;
 largura = larg;
 altura = alt;

  cout << " eu sou uma caixa especificada " << endl;
}

void Show_information(){
    cout << " largura: " << largura << " comprimento: " << comprimento << " altura " << altura << endl;
}

};

class Cartoon : public Box{
    private:
    int peso_max;
    public:

    Cartoon(int comp, int alt, int larg, int peso): Box(comp,  alt,  larg){
    
    peso_max = peso;

  cout << " eu sou um cartoon " << endl;
}

    
};

int main(){

Box caixa1 = Box(5,5,5);
Box caixa2;

caixa1.Show_information();
caixa2.Show_information();


cout << "-------------------------" << endl;
Cartoon cart = Cartoon(1,2,3,4);

cart.Show_information();




 return 0;
}