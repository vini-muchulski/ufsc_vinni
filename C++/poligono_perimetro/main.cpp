
#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

class Polygon{
    // atributos
    private:
    vector< pair<int,int> > lados;

    //metodos
    public:

    void setter_polygon(vector< pair<int,int> > vetorzao){
        lados = vetorzao;
        
    }

    void print_lados(){
        size_t i;
        for(i=0;i<lados.size();i++){
            cout << "x: " << lados[i].first << " y: " << lados[i].second<< endl;
        }
    }

    float find_area(){
        float a =0;
        float ox = lados[0].first;
        float oy = lados[0].second;

        for(size_t i=1; i< lados.size() ;i++){
            a+= (lados[i].first*ox - lados[i].second*oy);
            ox = lados[i].first;
            oy = lados[i].second;
        }

        if ( a<0){
            a = a* (-1);
            return a;
        }
        else{
        return a;
        }
    }


    /* float find_perimetro(){
        float perimetro = 0;
        for (size_t i = 1; i < lados.size();i++){
            if( i == 1){
                perimetro += sqrt((lados[i].first - lados[0].first)*(lados[i].first - lados[0].first) + (lados[i].second - lados[0].second)* (lados[i].second - lados[0].second));
            }
            if( i != 1 &&   i!=(lados.size()-1)){
                perimetro += sqrt((lados[i].first - lados[i-1].first)*(lados[i].first - lados[i-1].first) + (lados[i].second - lados[i-1].second)* (lados[i].second - lados[i-1].second));
            }
            if( i == (lados.size()-1)){
                perimetro += sqrt((lados[0].first - lados[i].first)*(lados[0].first - lados[i].first) + (lados[0].second - lados[i].second)* (lados[0].second - lados[i].second));
            }

        }

        return perimetro;
    } */

    float find_perimetro(){
        float perimetro = 0;
        float x_dist = 0;
        float y_dist = 0;

        for (size_t i = 1; i < lados.size();i++){
            x_dist = lados[i].first - lados[i-1].first;
            y_dist = lados[i].second - lados[i-1].second;

            perimetro += sqrt(x_dist*x_dist + y_dist*y_dist);
            }

        // ultimo ponto
            x_dist = lados[0].first - lados[lados.size()-1].first;
            y_dist = lados[0].second - lados[lados.size()-1].second;

            perimetro += sqrt(x_dist*x_dist + y_dist*y_dist);

    return perimetro;
        }

       
    
};
int main(){

    vector< pair<int,int> > teste;

    int x,y,qnt,i;
     
     cout << "digite a quantidade de pontos " << endl;
     cin >> qnt;
     for(i=0;i<qnt;i++){
        cout << i << " digite os valores x e y: " << endl;
        cin >> x >> y;
        teste.push_back(make_pair(x,y));
        }

    Polygon quadr;
    quadr.setter_polygon(teste);
    quadr.print_lados();

    cout << "area quadrado " << quadr.find_area() << endl;
    cout << "perimetro " << quadr.find_perimetro() << endl;
    

    return 0;
}