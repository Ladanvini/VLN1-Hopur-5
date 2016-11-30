#ifndef DATABASE_H
#define DATABASE_H
#include <string>
#include <vector>
#include "person.h"

using namespace std;

class Database
{
private:
    Person person;
    vector<Person> people;
    string _dbFile;
public:
    Database();
    Database(string dbFile);
    Person getPerson();
    vector<Person> getList();
    void update(vector<Person> peeps);
    void writeToDB(Person p);
};

#endif // DATABASE_H
