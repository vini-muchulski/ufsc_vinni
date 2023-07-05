
#include <iostream>
#include <vector>
#include <string>
#include<cmath>



using namespace std;
class Shape2d{
protected:
// atributos
int x;
int y;


public:
    Shape2d(){
 x=0;
 y=0;
    }

    Shape2d(int px, int py){
        x = px;
        y = py;
    }

virtual void show_perimeters(){
    cout << "X " << x << "- Y " << y << endl;
}




};




class Point2d{
protected:
int x;
int y;

public:
Point2d(){
    x = 0;
    y = 0;
}

Point2d(int xp,int yp){
    x = xp;
    y = yp;
}
// getters

int GetX(){
    return x;
}

int GetY(){
    return y;
}


// setters

void set_x(int p){
    x = p;
}

void set_y(int p){
    y = p;
}
};






class Circle : public Shape2d{
protected:
//atributos
size_t raio;

public:
 Circle(): Shape2d(){
    raio = 0;
 }

 Circle(size_t raioP): Shape2d(){
    raio = raioP;
 }
float calc_perimeter(){
    float perimetro = 2 * (3.14) * raio;
    return perimetro;
}

void show_perimeters() override{
    cout << "Circulo Perimetro = " << calc_perimeter() << endl;

}

};

class Square: public Shape2d{

protected:
//atributos
size_t lado;

public:
    Square(): Shape2d(){
 lado = 0;

    }

    Square(size_t edge): Shape2d(){
        lado = edge;

    }

    float calc_perimeter(){
        float perimetro = lado*4;
        return perimetro;
    }

    void show_perimeters() override{
    cout << "Quadrado Perimetro = " << calc_perimeter() << endl;

}

};

class Triangle : public Shape2d{
protected:
Point2d p1;
Point2d p2;
Point2d p3;

public:
 Triangle():Shape2d(){}

 Triangle(Point2d p1p,Point2d p2p,Point2d p3p):Shape2d(){
    p1 = p1p;
    p2 = p2p;
    p3 = p3p;
    
 }

float calc_perimeter(){

        float perimetro = 0;
        float dx = 0;
        float dy=0;


            
            // p2 - p1 --- p3 - p2
            dx = p2.GetX() - p1.GetX();
            dy = p2.GetY() - p1.GetY();

            perimetro += sqrt(dx*dx + dy*dy);

            dx = p3.GetX() - p2.GetX();
            dy = p3.GetY() - p2.GetY();

            perimetro += sqrt(dx*dx + dy*dy);
            

            // ultimo ponto
 
            dx = p3.GetX() - p1.GetX();
            dy = p3.GetY() - p1.GetY();

            perimetro += sqrt(dx*dx + dy*dy);

            return perimetro;


        }

void show_perimeters() override{
    cout << " Triangulo Perimetro = " << calc_perimeter() << endl;

}


};

class Polygon: public Shape2d{
    protected:
    //atributos
    vector<Point2d> vertices;

    public:
    Polygon(vector<Point2d> vetorzao) : Shape2d(){
        for(size_t i=0;i<vetorzao.size();i++){
            vertices.push_back(vetorzao[i]);
        }
    }

    float calc_perimeter(){
        float perimetro = 0;
        float dx = 0;
        float dy=0;

        size_t i;
        for (i=1; i < vertices.size(); i++){
            dx = vertices[i].GetX() - vertices[i-1].GetX();
            dy = vertices[i].GetY() - vertices[i-1].GetY();

            perimetro += sqrt(dx*dx + dy*dy);
            }

            // ultimo ponto

            dx = vertices[0].GetX() - vertices[vertices.size()-1].GetX();
            dy = vertices[0].GetY() - vertices[vertices.size()-1].GetY();

            perimetro += sqrt(dx*dx + dy*dy);

            return perimetro;


        }

    void show_perimeters() override{
    cout << " Poligono Perimetro = " << calc_perimeter() << endl;

}

};

int main(){
int opcao = 0;

vector<Shape2d*> formas;

while(opcao!=6){
    cout << "UFSC SHAPE MANAGER " << endl;
    cout << "------------------ " << endl;
    cout << "1 - Insert a circle " << endl;
    cout << "2 - Insert a Triangle " << endl;
    cout << "3 - Insert a Square " << endl;
    cout << "4 - Insert a Polygon " << endl;
    cout << "5 - Show informations " << endl;
    cout << "6 - Quit " << endl;

    cin >> opcao;

    switch (opcao)
    {
    case 1:
        {
            size_t raio;
            cout << "Digite o raio: ";
            cin >> raio;
             Circle* circulo1= new Circle(raio);
             formas.push_back(circulo1);

        }
        break;
    
    case 2:
          {
            int x,y;
            cout << "Digite x1 e y1: ";
            cin >> x;
            cin >> y;
            Point2d p1(x,y);

            cout << "Digite x2 e y2: ";
            cin >> x;
            cin >> y;
            Point2d p2(x,y);

            cout << "Digite x3 e y3: ";
            cin >> x;
            cin >> y;
            Point2d p3(x,y);

            Triangle* triangulo = new Triangle(p1,p2,p3);

            formas.push_back(triangulo);

            

        }
        break;

    case 3:
          {
            size_t lado;
            cout << "Digite o lado: ";
            cin >> lado;
             Square* quadrado1= new Square(lado);
             formas.push_back(quadrado1);

        }
        break;

    case 4:
        {
            int x,y;
            int lados;
            vector<Point2d> pontos;

            cout << "Digite o numero de lados: ";
            cin >> lados;
            
            for ( int i =0 ; i <lados;i++){
                cout << i+1 <<" - Digite x e y: ";
            cin >> x;
            cin >> y;
            Point2d p1(x,y);
            pontos.push_back(p1);
            
            }

            Polygon* poligono = new Polygon(pontos);
            formas.push_back(poligono);

            

        }
        break;

    case 5:
        {
            for(size_t j = 0 ; j<formas.size(); j++){
                cout << "id " << j << " ";
                formas[j]->show_perimeters();

            }
        }
        break;

    case 6:
        // Desalocar objetos
        for (size_t j = 0; j < formas.size(); j++) {
        delete formas[j];
    }
        break;
    default:
        break;
    }
}




    return 0;
}