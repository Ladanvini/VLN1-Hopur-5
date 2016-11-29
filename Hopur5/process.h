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
    void create(string name, string age, char sex, string birth, string death, string contribution, string turingYear);
    vector<Person> searchByName(string name);
    vector<Person> searchByAge(string age);
    vector<Person> searchBySex(char sex);
    vector<Person> searchByBirth(string birth);
    vector<Person> searchByDeath(string death);
    vector<Person> searchByContribution(string contribution);
    vector<Person> searchByTuring(bool flag);
    // Sort
    // Edit

};

#endif // PROCESS_H
