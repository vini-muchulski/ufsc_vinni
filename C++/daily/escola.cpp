
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>



using namespace std;

int main(){

 vector< pair<int, vector<string>>> turmas;
size_t i,j;
int serie;
string nome;


for (i=0;i<6;i++){
 turmas.push_back(make_pair(i+1,vector<string>{}));
}

while(serie !=0){
cout << "digite a turma em que quer add alunos - 0 para sair" << endl;
cin >> serie;

if(serie == 0){
    break;
}

cout << "digite nome do aluno:" << endl;

cin >> nome;

for (i=0;i<6;i++){
 if(turmas[i].first == serie){
    turmas[i].second.push_back(nome);
 }
}

}



// sorted
for (i=0;i<6;i++){
 
 sort(turmas[i].second.begin(),turmas[i].second.end());
 
} 


// printa alunos
for (i=0;i<6;i++){
    cout << "\nTurma: " << turmas[i].first;
 for(j=0;j<turmas[i].second.size();j++){
   cout  << " " << turmas[i].second[j];
 }

 cout << " " <<endl;
}




    return 0;
}

