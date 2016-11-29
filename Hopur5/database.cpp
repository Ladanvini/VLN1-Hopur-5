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

    fin.open("database.txt");
    if(fin.is_open())
        cout << "fucking success!" << endl;
    else
        cout << "fucking fail :(";

    char* str = new char[512];
    fin.getline(str, 255);


    while(str != "$" && !fin.eof()){

        strstr.push_back(string(str));
//cout << str << endl;
        fin.getline(str, 255);
    }
    for(int i=0; i< strstr.size(); i++)
        cout << strstr.at(i) << endl;
    fin.close();
 /*   while(!strstr.empty()){
        string s = strstr.at(strstr.size()-1);
        strstr.pop_back();
        cout << s << endl;
    }
*/
}
/*Person Database::getPerson()
{

}

vector<Person> Database::getList()
{

}*/

