//  Top K Frequent Elements
//  Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.


#include <iostream>
#include <vector>
#include <string>


//#include <cstdlib>

using namespace std;

int main(){

vector <int> vetorzao = {1,1,1,2,2,3};
vector <pair<int,int> > repeticoes;
size_t nums = vetorzao.size();
size_t maior_numero = 0;
size_t i;
int k;


cout << "Digite um inteiro k: " << endl;

cin >> k;


// inicializao do vetor pair com numero : qnt de repeticoes


for (i=0;i<nums;i++){
    if (vetorzao[i]>maior_numero){
        maior_numero = vetorzao[i];
    }
}

for (i=0;i<=maior_numero;i++){
    repeticoes.push_back(make_pair(i, 0));
}



for(i=0;i<nums;i++){
    repeticoes[vetorzao[i]].second++;
}

for(i=0;i<repeticoes.size();i++){
    if( repeticoes[i].second >= k){
        cout << repeticoes[i].first << " ";
    }
}



//system("pause");
    return 0;
}

