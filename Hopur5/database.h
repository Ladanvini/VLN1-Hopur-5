#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <vector>
#include <algorithm>
#include <QtSql>

#include "comps.h"
#include "person.h"

using namespace std;

class Database {
private:
    QSqlDatabase _db;
    Person person;
    vector<Person> _people;
    string _dbFile;
    vector<Comps> _computers;
public:
    Database();
    //Constructor opens connection and fills vectors from the database.
    Database(QString dbFile);
    //Returns list of computers from the database.
    vector<Comps> getComputerList();
    //Returns list of people from the database.
    vector<Person> getList();
    //Updates the vector people.
    void update(vector<Person> peeps);
    //Updates the vector computers.
    void updateCompDB(vector<Comps> comps);
    //Adds a person to the database.
    void writeToDB(Person p);
    //Adds a computer to the database.
    void writeToCompDB(Comps c);
    //Checks if the person already exists.
    bool exists(Person p);
    //Checks if the computer already exists.
    bool existsInCompDB(Comps c);
    //Deletes a person from the database.
    void delFromDB(Person p);
    //Deletes a computer from the database.
    void delFromCompDB(Comps c);

    //TODO delete the following functions!

    void reWriteDb();
    void reWriteCompDB();

};

#endif // DATABASE_H
