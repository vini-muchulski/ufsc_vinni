#include <iostream>
#include <string>

using namespace std;


int main(){
 
 string nome = "vini";

 cout << nome << endl;

string name("vinii");

cout << name << endl;

cout << " tamanho =  "  << name.size() << endl;

cout << " primeiro caractere =  "  << name.front() << endl;

cout << " primeiro caractere =  "  << name.at(0) << endl;

cout << " primeiro caractere =  "  << name[0] << endl;

cout << " posicao find v =  "  << name.find("v") << endl;



    return 0;
}