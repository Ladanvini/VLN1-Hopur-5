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
    Person person;
    vector<Person> people;
    string _dbFile;
    vector<Comps> computers;
public:
    Database();
    Database(string dbFile);
    Person getPerson();
    vector<Comps> getComputerList();
    vector<Person> getList();
    void update(vector<Person> peeps);
    void writeToDB(Person p);
    bool exists(Person p);
    void reWriteDb();
    void reWriteCompDB();
    void updateCompDB(vector<Comps> comps);
    void writeToCompDB(Comps c);
    bool existsInCompDB(Comps c);

};

#endif // DATABASE_H
