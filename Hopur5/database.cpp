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

    fin.open("/home/ladanvini/Documents/VLN1/VLN1-Hopur-5/Hopur5/database.txt");
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
    string line = "";
    string name;
    char sex;
    string birth;
    int death;
    string cont;
    int ty;
    for(int i=0; i<strstr.size(); i++){
        line = strstr.at(i);
        while(i<strstr.size() && strstr.at(i) != "#"){
 //namw
            int count = 0;
            while(i<strstr.size() && line[count] != ':' && count < line.size()){
                count ++;
            }
            count++;

            while(i<strstr.size() && line[count] != '\n' && count < line.size()){

                name = name + line[count];
                count++;
            }
            cout << name << endl;
//Sex
            line = strstr.at(i);
            i++;
            count = 0;
            while(i<strstr.size() && line[count] != ':' && count < line.size()){
                count ++;
            }
            count++;

            while(i<strstr.size() && line[count] != '\n' && count < line.size()){
                sex = line[count];
                count++;
            }
            cout << sex << endl;
//Birth
            line = strstr.at(i);
            i++;
            count = 0;

            while(i<strstr.size() && line[count] != ':' && count < line.size()){
                count ++;
            }
            count++;


            while(i<strstr.size() && line[count] != '\n' && count < line.size()){
                birth ="";
                birth = birth + line[count];

                count++;
            }

            cout << birth << endl;
            line = strstr.at(i);
            i++;
        }



    }
}
/*Person Database::getPerson()
{

}

vector<Person> Database::getList()
{

}*/

