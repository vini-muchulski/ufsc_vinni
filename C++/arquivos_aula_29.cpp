#include <iostream>
#include <fstream>

using namespace std;

//read a file and return its content into a string object
bool ReadFile(string path, string &content);

int main()
{
    string filename("manuscript2.txt");

    string filecontent;
    filecontent = "";

    if(ReadFile(filename, filecontent) == true)
        cout << "File was read" << endl;
    else
        cout << "File was not read" << endl;

        return 1;

    cout << "Content: " << filecontent << endl;

    return 0;
}

bool ReadFile(string path, string &content)
{
    ifstream filereader(path);

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