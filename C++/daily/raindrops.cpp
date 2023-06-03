
#include <iostream>
#include <vector>
#include <string>



using namespace std;

int main(){

string song = "";

int raindrops;

cout << "Digite o numero de raindrops: ";
cin >> raindrops;

bool no_song = true; 

if(raindrops%3==0){
 song +="Pling";
 no_song = false; 
}

 if(raindrops%5==0){
     song +="Plang";
no_song = false; 

}
 if(raindrops%7==0){
     song +="Plong";
     no_song = false; 
}

if(no_song){
    song += to_string(raindrops);
}


cout << "Song: " << song << endl;


    return 0;
}

