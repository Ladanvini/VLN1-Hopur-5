#ifndef APPSERVICE_H
#define APPSERVICE_H

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

#include "database.h"

using namespace std;

class appservice {
private:
    Database db;
    vector<Person> people;
    Person person;
public:
    appservice();
    appservice(Database _db);
    vector<Person> getList() { return people; }
    //Search
    string create(int id, string name, int age, char sex, int birth, int death, string contribution, int turingYear);
    vector<Person> searchByName(string name);
    vector<Person> searchByAge(string age);
    vector<Person> searchBySex(string _sex);
    vector<Person> searchByBirth(string birth);
    vector<Person> searchByDeath(string death);
    vector<Person> searchByContribution(string contribution);
    vector<Person> searchByTuring(string _flag);
    // Sort
    bool compareByName(const Person p1, const Person p2);
    vector<Person> sortByName();
    vector<Person> sortByAge();
    vector<Person> sortBySex(string _sex);
    vector<Person> sortByBirth();
    vector<Person> sortByDeath();
    vector<Person> sortByContribution(string contribution);
    vector<Person> sortByTuring(string _flag);
    //DELETE
    string deletePerson(string name, int birth);
    // Edit
    // Showing
    string showPeople(vector<Person> results);

    //SortByDec
    vector<Person> sortByNameDec();
    vector<Person> sortByAgeDec();
    vector<Person> sortBySexDec(string _sex);
    vector<Person> sortByBirthDec();
    vector<Person> sortByDeathDec();
    vector<Person> sortByTuringDec(string _flag);

};

#endif // APPSERVICE_H
