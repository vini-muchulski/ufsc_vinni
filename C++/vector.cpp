#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main(){

vector<int> vetorzao;

vetorzao.push_back(10);

vetorzao.push_back(15);

vetorzao.push_back(2);

for(size_t i=0;i < vetorzao.size();i++){
    cout << vetorzao[i] << endl;
}

    return 0;
}