#ifndef DATABASE_H
#define DATABASE_H
#include <string>
#include "person.h"

using namespace std;

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
    void update(vector<Person> peeps);
};

#endif // DATABASE_H
