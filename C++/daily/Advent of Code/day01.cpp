
#include <iostream>
#include <vector>
#include <string>


/*
À vez, os Elfos anotam o número de Calorias contido em várias refeições, snacks, rações, etc. 
que eles trouxeram com eles, um item por linha. 
Cada Elfo separa o seu próprio inventário do Elfo anterior (se existir) por uma linha em branco.
Encontra o Elfo que leva mais Calorias. Quantas calorias esse Elfo leva no total?
*/

using namespace std;

int main(){

vector <pair<int,vector<int> >> elfos;

vector <pair<int,int>> comida_total_deCadaElfo;
size_t comida_total = 0;

pair<int,size_t> elfo_que_mais_comeu;


size_t j,i;

for(i=0;i<5;i++){
    elfos.push_back(make_pair(i,vector<int>(0)));
}
elfos[0].second.push_back(1000);
elfos[0].second.push_back(2000);
elfos[0].second.push_back(3000);

elfos[1].second.push_back(4000);

elfos[2].second.push_back(5000);
elfos[2].second.push_back(6000);


elfos[3].second.push_back(7000);
elfos[3].second.push_back(8000);
elfos[3].second.push_back(9000);

elfos[4].second.push_back(10000);


for(i=0;i<5;i++){
    comida_total = 0;
    for(j=0;j<elfos[i].second.size();j++){
        comida_total += elfos[i].second[j];

    }
    if(i == 0){
        elfo_que_mais_comeu.first = i+1;
        elfo_que_mais_comeu.second = comida_total;
    }

    else{
        if(comida_total > elfo_que_mais_comeu.second){
            elfo_que_mais_comeu.first = i+1;
            elfo_que_mais_comeu.second = comida_total;
        }
    }
    comida_total_deCadaElfo.push_back(make_pair(i,comida_total));
}

for(i=0;i<comida_total_deCadaElfo.size();i++){
    cout << "Elfo " << comida_total_deCadaElfo[i].first+1 << " comeu " << comida_total_deCadaElfo[i].second << endl;
}
cout << "Elfo que mais comeu: " << elfo_que_mais_comeu.first << " com " << elfo_que_mais_comeu.second << " de comida" << endl;

    return 0;
}

