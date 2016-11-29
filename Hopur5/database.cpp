#include "database.h"
#include <fstream>
#include <iostream>

using namespace std;
Database::Database(){

}

Database::Database(string dbFile)
{
    vector<string> strstr;
    ifstream fin;
    if(fin.open(dbFile))
        cout << "fucking success!";
    else
        cout << "fucking fail :(";

    string str;
    while(fin >> str)
        strstr.push_back(str);

    for(int i=0; i<strstr.size(); i++)
        cout<< strstr.at(i);
}
Person Database::getPerson()
{

}

vector<Person> Database::getList()
{

}

