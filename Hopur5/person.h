#ifndef PERSON_H
#define PERSON_H
#include <string>
#include<vector>

using namespace std;

class Person
{
private:
    string name;
    string age;
    char sex;
    string birth;
    string death;
    string contribution;
    string turingYear;
    bool turing;
public:
    Person();
    Person(string _name, string _age, char _sex, string _birth, string _death, string _contribution, string _truringYear);
    void showPerson();
};

#endif // PERSON_H
