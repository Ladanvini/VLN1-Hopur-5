#ifndef DATABASE_H
#define DATABASE_H

#include "person.h"

class Database
{
private:
    Person person;
    vector<Person> people;
public:
    Database();
    Database(string dbFile);
    Person getPerson();
    vector<Person> getList();
};

#endif // DATABASE_H
