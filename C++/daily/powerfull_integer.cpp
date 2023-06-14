
#include <iostream>
#include <vector>
#include <string>


#include <cstdlib>

using namespace std;

int main(){

vector <pair<int,int> > quantidade;

int n = 3; // numero de intervalos
bool existencia = false;

vector<vector<int>> matriz ={{1,3},{4,6},{3,4}};

for ( size_t i = 0; i < n; i++){
    for(size_t j = 0; j < 2; j++){
        existencia = false;
        for (size_t t = 0; t < quantidade.size(); t++){
            if(quantidade[t].first == matriz[i][j]){
                quantidade[t].second++;
                existencia = true;
                break;
                
            }
        }
        if (existencia == false) {
            quantidade.push_back(make_pair(matriz[i][j], 1));
        }

        
    }


}


for (size_t i=0; i<quantidade.size() ; i++){
    cout << quantidade[i].first << " - " << quantidade[i].second <<  "  " << endl;
}


system("pause");


    return 0;
}