#include "database.h"

#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

Database::Database() {

}

Database::Database(string dbFile) {

    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "computer_db.sqlite";
    db.setDatabaseName(dbName);

    db.open();

    QSqlQuery query(db);

    query.exec("SELECT * FROM People");

    int id;
    string name;
    int age;
    int birthYear;
    int deathYear;
    char sex;
    string contribution;
    int turingYear;
    bool turing;

    while(query.next()) {
        id = query.value("PID").toInt();
        name = query.value("pName").toString();
        birthYear = query.value("pBirthYear").toInt();
        deathYear = query.value("pDeathYear").toInt();
        sex = query.value("pSex").toChar();
        contribution = query.value("pContribution").toString();
        turingYear = query.value("pTuringYear").toInt();
        turing = query.value("pTuring").toBool();

        people.push_back(Person(id, name, sex, birthYear, deathYear, contribution, turingYear));
    }


    QSqlQuery queryC(db);

    queryC.exec("SELECT * FROM Computers");

    int idC;
    string nameC;
    string typeC;
    bool builtC;
    int builtYearC;

    while(queryC.next()) {
        idC = queryC.value("cID").toInt();
        nameC = queryC.value("cName").toString();
        typeC = queryC.value("cType").toString();
        builtC = queryC.value("cBuilt").toBool();
        builtYearC = queryC.value("cBuiltYear").toInt();
    }


    /*
    vector<string> strstr;
    ifstream fin;
    _dbFile = dbFile;
    fin.open(dbFile);

    if(!fin.is_open())
        cerr << "failed oppening :( " << dbFile << endl;

    char* str = new char[512];
    fin.getline(str, 255);

    while(!fin.eof()) {
        strstr.push_back(string(str));
        fin.getline(str, 255);
    }

    string line = "";
    string name;
    char sex;
    string birth;
    string death;
    string contribution;
    string ty;
    string age;

    for(unsigned int i = 0; i < strstr.size(); i++) {
        line = strstr.at(i);

        while(i < strstr.size() && strstr.at(i) != "#" && strstr.at(i) != "$") {

//name
            unsigned int count = 0;

            while(i < strstr.size() && line[count] != ':' && count < line.size()) {
                count ++;
            }

            count++;
            name = "";

            while(i < strstr.size() && line[count] != '\n' && count < line.size()) {
                name = name + line[count];
                count++;
            }

//Age
            i++;
            line = strstr.at(i);
            count = 0;

            while(i < strstr.size() && line[count] != ':' && count < line.size()) {
                count ++;
            }

            count++;
            age = "";

            while(i < strstr.size() && line[count] != '\n' && count < line.size()) {
                age = age + line[count];
                count++;
            }

 //Sex
            i++;
            line = strstr.at(i);
            count = 0;

            while(i < strstr.size() && line[count] != ':' && count < line.size()) {
                count ++;
            }

            count++;

            while(i < strstr.size() && line[count] != '\n' && count < line.size()) {
                sex = line[count];
                count++;
            }

//Birth
            i++;
            line = strstr.at(i);
            count = 0;

            while(i < strstr.size() && line[count] != ':' && count < line.size()) {
                count ++;
            }

            count++;
            birth = "";

            while(i < strstr.size() && line[count] != '\n' && count < line.size()) {
                birth = birth + line[count];
                count++;
            }

//death
            i++;
            line = strstr.at(i);
            count = 0;

            while(i < strstr.size() && line[count] != ':' && count < line.size()) {
                count ++;
            }

            count++;
            death = "";

            while(i < strstr.size() && line[count] != '\n' && count < line.size()) {
                death = death + line[count];
                count++;
            }

//contribution
            i++;
            line = strstr.at(i);
            count = 0;

            while(i < strstr.size() && line[count] != ':' && count < line.size()) {
                count ++;
            }

            count++;
            contribution = "";

            while(i < strstr.size() && line[count] != '\n' && count < line.size()) {
                contribution = contribution + line[count];
                count++;
            }

//turing award year
            i++;
            line = strstr.at(i);
            count = 0;

            while(i < strstr.size() && line[count] != ':' && count < line.size()) {
                count ++;
            }

            count++;
            ty = "";

            while(i<strstr.size() && line[count] != '\n' && count < line.size()) {
                ty = ty + line[count];
                count++;
            }

            i++;
            Person* p = new Person(name, age, sex, birth, death, contribution, ty);
            people.push_back(*p);
        }
    }
    */
}


vector<Person> Database::getList() {
  return people;
}
vector<Comps> Database::getComputerList(){


    return computers;



}

void Database::update(vector<Person> peeps) {
    vector<string> names;
    vector<Person> sorted;
    for(unsigned int i=0; i<peeps.size(); i++)
        names.push_back(peeps.at(i).getName());

    std::sort(names.begin(), names.end());

    for(unsigned int i=0; i<names.size(); i++) {
        for(unsigned int j=0; j<peeps.size(); j++) {
            if(names.at(i) == peeps.at(j).getName())
                sorted.push_back(peeps.at(j));
        }
    }

    people = sorted;
}
void Database::writeToDB(Person p) {
    ofstream fout(_dbFile, ios::app);
    string name = "Name: ";
    string age = "Age: ";
    string sex = "Sex: ";
    string birth = "BirthYear: ";
    string death = "DeathYear: ";
    string contribution = "Contribution: ";
    string turingYear = "TuringAwardYear: ";
    string end = "#\n";
    string all = "";

    name = name + p.getName() + '\n';
    age = age + std::to_string(p.getAge()) + '\n';
    sex = sex + p.getSex() + '\n';
    birth = birth + std::to_string(p.getBirth()) + '\n';
    death = death + std::to_string(p.getDeath()) + '\n';
    contribution = contribution + p.getContribution() + '\n';
    turingYear = turingYear + std::to_string(p.getTuringYear()) + '\n';
    all = all + name + age + sex + birth + death + contribution + turingYear + end;

    fout << all;
    fout.close();
}

bool Database::exists(Person p) {
    for(unsigned int i=0; i<people.size(); i++) {
        if(people.at(i) == (p))
            return true;
    }
    return false;
}

void Database::reWriteDb() {
    ofstream fout(_dbFile);
    string name = "Name: ";
    string age = "Age: ";
    string sex = "Sex: ";
    string birth = "BirthYear: ";
    string death = "DeathYear: ";
    string contribution = "Contribution: ";
    string turingYear = "TuringAwardYear: ";
    string end = "#\n";
    string all = "";

    for(unsigned int i=0; i<people.size(); i++) {
        name = "Name: ";
        name = name + people.at(i).getName() + '\n';
        age = "Age: ";
        age = age + std::to_string(people.at(i).getAge()) + '\n';
        sex = "Sex: ";
        sex = sex + people.at(i).getSex() + '\n';
        birth = "BirthYear: ";
        birth = birth + std::to_string(people.at(i).getBirth()) + '\n';
        death = "DeathYear: ";
        death = death + std::to_string(people.at(i).getDeath()) + '\n';
        contribution = "Contribution: ";
        contribution = contribution + people.at(i).getContribution() + '\n';
        turingYear = "TuringAwardYear: ";
        turingYear = turingYear + std::to_string(people.at(i).getTuringYear()) + '\n';
        all = all + name + age + sex + birth + death + contribution + turingYear + end;
    }

    fout << all;
    fout.close();
}
void Database::reWriteCompDB(){}
void Database::update(vector<Comps> comps){

}
void Database::writeToDB(Comps c){}
bool Database::exists(Comps c){
}
