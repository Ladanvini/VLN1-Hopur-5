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
    cout << "hi";
    fin.open("/home/ladanvini/Documents/VLN1/VLN1-Hopur-5/Hopur5/database.txt");
    if(!fin.fail())
        cout << "fucking success!";
    else
        cout << "fucking fail :(";

    string str;
    getline(fin, str);

/*    while(str != "$"){
        strstr.push_back(str);
        cout << str << endl;
        getline(fin, str);
    }
*/
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

