
#include <iostream>
#include <vector>
#include <string>


//#include <cstdlib>

using namespace std;

int main(){


string palavra;

cout << "Digite a palavra: "; 
cin >> palavra;


size_t tamanho = palavra.size();
int i;
string reversa;



for(i=tamanho-1;i>=0;i--){
    reversa += palavra[i];
    
}

cout << "PALAVRA: " << palavra << endl;

cout << "REVERSA: " << reversa << endl;

    return 0;
}


/*
#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#endif

*/