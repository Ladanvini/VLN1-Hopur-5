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

    if (!_db.open())
       {
          qDebug() << "Error: connection with database fail";
       }
       else
       {
          qDebug() << "Database: connection ok";
       }

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


        _people.push_back(Person(id, name.toStdString(), sex.toLatin1(), birthYear, deathYear, contribution.toStdString(), turingYear));
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
        _computers.push_back(Comps(idC, nameC.toStdString(), typeC.toStdString(), builtYearC, builtC));
    }



}
//Returns a list of people in the database
vector<Person> Database::getList() {
  return _people;
}
//Returns a list of computers in the database
vector<Comps> Database::getComputerList() {
    return _computers;
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

    _people = sorted;
}
//Updates the vector computers.
void updateCompDB(vector<Comps> comps) {
    vector<string> compNames;
    vector<Comps> sortedComps;
    for(unsigned int i = 0; i < comps.size(); i++) {
        compNames.push_back(comps.at(i).getName());
    }

    std::sort(compNames.begin(), compNames.end());

    for(unsigned int i = 0; i < compNames.size(); i++) {
        for(unsigned int j = 0; j < comps.size(); j++) {
            if(compNames.at(i) == comps.at(j).getName())
                sortedComps.push_back(comps.at(j));
        }
    }
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
    stmnt = "INSERT INTO People ( PID, pName, pBirthYear, pDeathYear, pSex, pContribution,"
            " pTuringYear, pTuring )"
            "\n VALUES ( " + std::to_string(p.getId()) + ", "
                    + p.getName() + ", " + std::to_string(p.getBirth())
                    + ", " + std::to_string(p.getDeath()) + ", " + p.getSex()
                    + ", " + p.getContribution() + ", " + std::to_string(p.getTuringYear()) + ", "
                    + turingB + " )";

    if(query.exec(QString::fromStdString(stmnt)))
        qDebug() << query.executedQuery();
    else
        qDebug() << "Could not execute query" << endl;

    qDebug() << query.lastError();

    cout << _db.commit() << endl;
    _db.close();
}
//Checks if the person exists in the people vector
bool Database::exists(Person p) {
    for(unsigned int i=0; i<_people.size(); i++) {
        if(_people.at(i) == (p))
            return true;
    }
    return false;
}
//Adds a new computer to the Database
void Database::writeToCompDB(Comps c) {
    _db.open();

    QSqlQuery query(_db);

    string stmnt;
    stmnt = "INSERT INTO Computers ( cID, cName, cType, cBuilt, cBuiltYear,)"
            "\n VALUES ( " + std::to_string(c.getId()) + ", "
                    + c.getName() + ", " + c.getType()
                    + ", " + std::to_string(c.getBuilt()) + ", " + std::to_string(c.getYearBuilt()) + " )";

    query.exec(QString::fromStdString(stmnt));
}
//Checks if the computer already exists in the vector
bool Database::existsInCompDB(Comps c) {
    for (unsigned int i = 0 ; i < _computers.size(); i++)
        if (_computers.at(i).getId() == c.getId()){
            return true;
}
    return false;

}
//Deletes a person from the database.
void Database::delFromDB(Person p) {


    _db.open();

    QSqlQuery query(_db);

    string stmnt;
    stmnt = "DELETE FROM People WHERE PID = "
            + std::to_string(p.getId());


    query.exec(QString::fromStdString(stmnt));
}
//Deletes a computer from the database.
void Database::delFromCompDB(Comps c) {
    _db.open();

    QSqlQuery query(_db);

    string stmnt;
    stmnt = "DELETE FROM Computers WHERE CID = "
            + std::to_string(c.getId());


    query.exec(QString::fromStdString(stmnt));

}
