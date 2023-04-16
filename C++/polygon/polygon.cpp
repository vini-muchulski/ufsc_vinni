
#include <iostream>
#include <vector>
#include <string>

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
};
int main(){

    vector< pair<int,int> > teste;
    size_t i;
    int x,y,qnt;
     
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
    

    return 0;
}