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
    bool compareByName(const Person p1, const Person p2);
    vector<Person> sortByName();
    vector<Person> sortByAge(string age);
    vector<Person> sortBySex(char sex);
    vector<Person> sortByBirth(string birth);
    vector<Person> sortByDeath(string death);
    vector<Person> sortByContribution(string contribution);
    vector<Person> sortByTuring(bool flag);

    vector<int> mergeSort(vector<int> arr, size_t begin, size_t end);
    vector<int> merge(vector<int> arr1, vector<int> arr2);
    // Edit

};

#endif // PROCESS_H
