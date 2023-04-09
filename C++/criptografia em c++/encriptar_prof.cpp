#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector<pair<char,char> > CreateTable(int desloc);
string EncryptText(string text, const vector<pair<char,char> > &convTable); //const para passagem read-only, & para evitar copia de memoria

string DecryptText(string text, const vector<pair<char,char> > &convTable); //const para passagem read-only, & para evitar copia de memoria


int main()
{
    string text = "Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";

    vector<pair<char,char> > convTable;
    convTable = CreateTable(10);

    //print table
    for(size_t i=0; i< convTable.size(); i++)
    {
        cout << convTable.at(i).first << " -> " << convTable.at(i).second << endl;
    }

    //encrypt text
    string encryptedText = EncryptText(text, convTable);
    cout << "Encrypted Text: " << encryptedText << endl << endl;

    //encrypt text
    string decryptedText = DecryptText(encryptedText, convTable);
    cout << "Dencrypted Text: " << decryptedText << endl;

    return 0;
}


vector<pair<char,char> > CreateTable(int desloc)
{
    vector<pair<char,char> > table(256);
    for(size_t i=0; i< table.size(); i++)
    {
        table.at(i).first = i;
        table.at(i).second = table.at(i).first + desloc;

    }
    return table;
}

string EncryptText(string text, const vector<pair<char,char> > &convTable)
{
    string result;

    for(size_t i=0; i< text.size(); i++) //navegar na string
    {
        char ch = text.at(i);
        //cout << ch;
        result += convTable.at(ch).second;
    }

    return result;
}

string DecryptText(string text, const vector<pair<char,char> > &convTable)
{
    string result;

    for(size_t i=0; i< text.size(); i++) //navegar na string
    {
        char ch = text.at(i);
        for(size_t j=0; j< convTable.size(); j++)
        {
            if(ch == convTable.at(j).second)
            {
                result += convTable.at(j).first;
            }
        }
    }

    return result;
}