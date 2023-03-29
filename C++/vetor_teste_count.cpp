#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <utility>
#include <algorithm>

using namespace std;

int main(){

string banana = "banana";


cout << " a APARECEU vezes " << count(banana.begin(),banana.end(),'a') << endl;

vector <pair<string,int>> vetorzao;

string ab= "abacaxi";

string vini = "vini";

vetorzao.push_back(make_pair(banana,1));

vetorzao.push_back(make_pair(ab,2));

vetorzao.push_back(make_pair(vini,3));

cout << "ab 5 " << ab[4] << endl;


int i;

for(i=0; i < vetorzao.size();i++){
    cout << vetorzao[i].first << endl;
    cout << vetorzao[i].second << endl;

}

    return 0;
}