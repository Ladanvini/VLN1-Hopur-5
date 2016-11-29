#ifndef PROCESS_H
#define PROCESS_H

#include "database.h"
class Process
{
private:
    Database db;
    vector<Person> people;
    Person person;
public:
    Process(Database _db);
    void addToList(Person p);
    Person retrievePerson(Person p);
    void sortBy(string sortVal);
    Person searchBy(string searchVal);
    vector<Person> searchPeopleBy(string searchVal);
};

#endif // PROCESS_H
