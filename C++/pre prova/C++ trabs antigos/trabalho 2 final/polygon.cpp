#include "point2D.hpp"
#include "polygon.hpp"

using namespace std;


    Polygon::Polygon(size_t numero_vertices, Point2D* forma_vertices){
            
       

             shapeVertex = forma_vertices;
             numberOfVertex = numero_vertices;

            
             
    };
    
    Polygon::Polygon(){
        shapeVertex = NULL;
        
        numberOfVertex = 0;


    };

    

   


float Polygon::find_area(){
        float a =0;
        float ox = shapeVertex[0].GetX();
        float oy = shapeVertex[0].GetY();

        for(size_t i=1; i< numberOfVertex ;i++){
            a+= (shapeVertex[i].GetX()*oy - shapeVertex[i].GetY()*ox);
            
            ox = shapeVertex[i].GetX();
            oy = shapeVertex[i].GetY();
        }

        a = a/2;

        if ( a<0){
            a = a* (-1);
            return a;
        }
        else{
        return a;
        }
    } 

float  Polygon::find_perimetro(){
        float perimetro = 0;
        float dx = 0;
        float dy=0;

        size_t i;
        for (i=1; i < numberOfVertex; i++){
            dx = shapeVertex[i].GetX() - shapeVertex[i-1].GetX();
            dy = shapeVertex[i].GetY() - shapeVertex[i-1].GetY();

            perimetro += sqrt(dx*dx + dy*dy);
            }

            // ultimo ponto

            dx = shapeVertex[0].GetX() - shapeVertex[numberOfVertex-1].GetX();
            dy = shapeVertex[0].GetY() - shapeVertex[numberOfVertex-1].GetY();

            perimetro += sqrt(dx*dx + dy*dy);

            return perimetro;


        }

void Polygon::Set_pontos(size_t numero_vertices, Point2D* forma_vertices){
            if(shapeVertex != NULL) delete [] shapeVertex;
            shapeVertex = NULL;

            shapeVertex = forma_vertices;
            numberOfVertex = numero_vertices;

        }


Polygon::~Polygon(){
    if(shapeVertex != NULL) delete [] shapeVertex;

        };
    


