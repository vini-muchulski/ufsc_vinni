// Leia 2 variáveis A e B, que correspondem a 2 notas de um aluno. A seguir, calcule a média do aluno, sabendo que a nota A tem peso 3,5 e a nota B tem peso 7,5.

#include <iostream>

using namespace std;

int main(){

float a,b;
float media;

cout << "Digite a nota A e a nota B: "<< endl;

cin >> a >> b;

media = (a*3.5 + b*7.5)/11;

cout.precision(4);

cout << "O valor de media foi: " << media << endl;
    return 0;
}