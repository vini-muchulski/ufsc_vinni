#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//read a file and return its content into a string object
bool ReadFile(string path, string &content);

int main()
{
    string filename("texto.txt");

    string filecontent;
    filecontent = "";

    if(ReadFile(filename, filecontent) == true){
        cout << "File was read" << endl;
}
    else{
        cout << "File was not read" << endl;

        return 1;
    }

    cout << "Content: " << filecontent << endl;

    //character counting

    vector <pair<char, size_t> > ch_count(256);

    for(size_t i=0;i<ch_count.size(); i++){
        ch_count[i].first = i;
        ch_count[i].second = 0;
    }

    

    for(size_t i=0; i<filecontent.size();i++){
        char ch = filecontent.at(i);
        ch_count.at(ch).second++;
        
    }

    for(size_t j=0; j<ch_count.size();j++){
        cout <<  "char id: " << (int)ch_count[j].first <<"caracter char: " << ch_count[j].first << " Counting: " << ch_count.at(j).second << endl;
    }

    return 0;
}

bool ReadFile(string path, string &content)
{   
    // path.c_str()
    ifstream filereader(path.c_str());

    if(!filereader.is_open())
    return false;


    string tmp;
    while(getline(filereader, tmp))
    {
        content += tmp;
    }

    filereader.close();

    return true;
}

//eliminar as ocorrencias de caracteres zerados
// ordenar o vetor em funcao do segundo elemento em ordem decrescente;
// como usar o sort, stable_sort;

//encriptador;