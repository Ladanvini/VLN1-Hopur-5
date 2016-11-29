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
    void create(string name, string age, string sex, string birth, string death, string contribution, string turingYear);
    void searchByName(string name);
    void searchByAge(string age);
    void searchBySex(char sex);
    void searchByBirth(string birth);
    void searchByDeath(string death);
    void searchByContribution(string contribution);
    void searchByTuring(string turing);
    // Sort
    // Edit

};

#endif // PROCESS_H
