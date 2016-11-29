#include "database.h"
#include <fstream>
#include <iostream>

using namespace std;
Database::Database(){

}

Database::Database(string dbFile)
{
    vector<char> strstr;
    ifstream fin;
    cout << "hi";
    fin.open("/home/ladanvini/Documents/VLN1/VLN1-Hopur-5/Hopur5/database.txt");
    if(fin.is_open())
        cout << "fucking success!" << endl;
    else
        cout << "fucking fail :(";

    char str;
    fin.get(str);
    cout << str << endl;


    while(str != '$'){
        strstr.push_back(str);
        cout << str << endl;
        fin.get(str);
    }
    fin.close();
    for(int i=0; i<strstr.size(); i++)
        cout<< strstr.at(i);
}
Person Database::getPerson()
{

}

vector<Person> Database::getList()
{

}

