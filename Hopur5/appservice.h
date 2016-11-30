#ifndef PROCESS_H
#define PROCESS_H

#include <string>
#include <vector>

#include "database.h"
#include "person.h"

using namespace std;

class Process
{
private:
    Database db;
    vector<Person> people;
    Person person;
public:
    Process();
    Process(Database _db);
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
    vector<Person> sortBySex(char sex);
    vector<Person> sortByBirth();
    vector<Person> sortByDeath();
    vector<Person> sortByContribution(string contribution);
    vector<Person> sortByTuring(bool flag);
    string deletePerson(Person p);
    vector<int> mergeSort(vector<int> arr, size_t begin, size_t end);
    vector<int> merge(vector<int> arr1, vector<int> arr2);
    // Edit

};

#endif // PROCESS_H
