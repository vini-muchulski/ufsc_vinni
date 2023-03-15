// Faça um programa que leia três números e os mostre na tela, separados por uma "\" (barra) e na linha abaixo imprima os mesmos três números multiplicados por "-5".


#include <iostream>

using namespace std;

int main(){
    int n1,n2,n3;

    cout << "Digite tres valores: "<< endl;

    cin >> n1 >> n2 >> n3;

    cout << "Os valores foram "<< n1 << " \\ " <<  n2 << " \\ "  << n3 << " \\ "  << endl;

    cout << "-5* = "<< -5*n1 << " \\ " <<  -5*n2 << " \\ "  << -5*n3 << " \\ "  << endl;

    return 0;
}