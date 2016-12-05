#include "database.h"

#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

Database::Database() {

}
/*Constructor, opens a connection and the database
 * Gets the instances of people and adds it to vector people
 * Gets instances of Computers and adds them to computers
 * keeping all their attributes
 */
Database::Database(QString dbName) {


    _db = QSqlDatabase::addDatabase("QSQLITE");

    _db.setDatabaseName(dbName);

    _db.open();

    QSqlQuery query(_db);

    query.exec("SELECT * FROM People");

    int id;
    QString name;
    int age;
    int birthYear;
    int deathYear;
    QChar sex;
    QString contribution;
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


        people.push_back(Person(id, name.toStdString(), sex.toLatin1(), birthYear, deathYear, contribution.toStdString(), turingYear));
    }


    QSqlQuery queryC(_db);

    queryC.exec("SELECT * FROM Computers");

    int idC;
    QString nameC;
    QString typeC;
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
//Returns a list of people in the database
vector<Person> Database::getList() {
  return people;
}
//Returns a list of computers in the database
vector<Comps> Database::getComputerList() {
    return computers;
}
//Updates the vector of people
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
//Adds a new Person to the Database
void Database::writeToDB(Person p) {

    _db.open();

    QSqlQuery query(_db);
    string turingB;
    if(p.getTuring())
        turingB = "TRUE";
    else
        turingB = "FALSE";

    string stmnt;
    stmnt = "INSERT INTO People ( PID, pName, pBirthYear, pDeathYear, pSex, pContributon,"
            " pTuringYear, pTuring )"
            "\n VALUES ( " + std::to_string(p.getId()) + ", "
                    + p.getName() + ", " + std::to_string(p.getBirth())
                    + ", " + std::to_string(p.getDeath()) + ", " + p.getSex()
                    + ", " + p.getContribution() + ", " + std::to_string(p.getTuringYear()) + ", "
                    + turingB + " )";

    query.exec(QString::fromStdString(stmnt));
}
//Checks if the person exists in the people vector
bool Database::exists(Person p) {
    for(unsigned int i=0; i<people.size(); i++) {
        if(people.at(i) == (p))
            return true;
    }
    return false;
}
//Updates the computers vector
void Database::updateCompDB(vector<Comps> comps) {

}
//Adds a new computer to the Database
void Database::writeToCompDB(Comps c) {}
//Checks if the computer already exists in the vector
bool Database::existsInCompDB(Comps c) {
}
//Deletes a person from the database.
void delFromDB(Person p) {


}

//Deletes a computer from the database.
void delFromCompDB(Comps c) {

}
