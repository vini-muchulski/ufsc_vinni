
#include <iostream>
#include <vector>
#include <string>


//#include <cstdlib>

using namespace std;

int main(){


int ano;
cout << "digite o ano: ";
cin >> ano;

if(ano%4 == 0 && (ano%100 != 0 or ano%400 == 0) ){
    cout << "ano bissexto " << ano << endl;
}
else{
     cout << "ano NAO bissexto " << ano << endl;
}
//system("pause");


    return 0;
}


