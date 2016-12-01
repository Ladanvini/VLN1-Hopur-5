#ifndef PROCESS_H
#define PROCESS_H

#include <string>
#include <vector>
#include "database.h"

using namespace std;

class Process {
private:
    Database db;
    vector<Person> people;
    Person person;
    bool checkIfDigit(char c);
    bool numericStringCompare(const std::string& s1, const std::string& s2);
public:
    Process();
    Process(Database _db);
    //Search
    string create(string name, string age, char sex, string birth, string death, string contribution, string turingYear);
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
    string deletePerson(string name, string birth);
    // Edit
    // Showing
    string showPeople(vector<Person> results);

};

#endif // PROCESS_H
