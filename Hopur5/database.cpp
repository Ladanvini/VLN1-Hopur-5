#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "database.h"

using namespace std;

Database::Database(){

}

Database::Database(string dbFile)
{
    vector<string> strstr;
    ifstream fin;

    fin.open(dbFile);
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
    string death;
    string cont;
    string contribution;
    string ty;
    for(int i=0; i<strstr.size(); i++){
        line = strstr.at(i);
        while(i<strstr.size() && strstr.at(i) != "#" && strstr.at(i) != "$"){
 //name
            int count = 0;
            while(i<strstr.size() && line[count] != ':' && count < line.size()){
                count ++;
            }
            count++;
            name = "";
            while(i<strstr.size() && line[count] != '\n' && count < line.size()){

                name = name + line[count];
                count++;
            }
            //cout <<"name " << i <<" " << name << endl;
//Sex
            i++;
            line = strstr.at(i);

            count = 0;
            while(i<strstr.size() && line[count] != ':' && count < line.size()){
                count ++;
            }
            count++;

            while(i<strstr.size() && line[count] != '\n' && count < line.size()){
                sex = line[count];
                count++;
            }
            //cout <<"Sex: " <<i << " " << sex << endl;
//Birth

            i++;
            line = strstr.at(i);
            count = 0;

            while(i<strstr.size() && line[count] != ':' && count < line.size()){
                count ++;
            }
            count++;

            birth ="";
            while(i<strstr.size() && line[count] != '\n' && count < line.size()){

                birth = birth + line[count];

                count++;
            }

            //cout << i << " birthyear: " <<birth << endl;

//death

            i++;
            line = strstr.at(i);
            count = 0;
            while(i<strstr.size() && line[count] != ':' && count < line.size()){
                count ++;
            }
            count++;
            death = "";
            while(i<strstr.size() && line[count] != '\n' && count < line.size()){

                death = death + line[count];

                count++;
            }
            //cout << "deathyear: " << death << endl;

//contribution

            i++;
            line = strstr.at(i);
            count = 0;
            while(i<strstr.size() && line[count] != ':' && count < line.size()){
                count ++;
            }
            count++;
            //cout << "count: " << count << endl;

            contribution = "";

            while(i<strstr.size() && line[count] != '\n' && count < line.size()){
                contribution = contribution + line[count];
                count++;

            }
            //cout <<"contribution: " << contribution << endl;

//turing award year


            i++;
            line = strstr.at(i);
            count = 0;
            while(i<strstr.size() && line[count] != ':' && count < line.size()){
                count ++;
            }
            count++;
            ty = "";
            while(i<strstr.size() && line[count] != '\n' && count < line.size()){

                ty = ty + line[count];

                count++;
            }
            //cout <<"turing year: " <<ty << endl;
            i++;
            string age = "";
            Person* p = new Person(name, age, sex, birth, death, contribution, ty);
            people.push_back(*p);
        }



    }



}
/*Person Database::getPerson()
{

}
*/
vector<Person> Database::getList()
{
    /*for(int i=0; i<people.size(); i++){
        cout << "----  " << i <<"  ----"<< endl;
        people.at(i).showPerson();
    }*/

  return people;
}
void Database::update(vector<Person> peeps){
    people = peeps;

}
