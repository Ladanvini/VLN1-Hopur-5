#ifndef PERSON_H
#define PERSON_H
#include<string>
#include<vector>

using namespace std;

class Person
{
private:
    string name;
    int age;
    char sex;
    int birth;
    int death;
    string contribution;
    int turingYear;
    bool turing;
public:
    Person();
    Person(string _name, int _age, char _sex, int _birth);
    Person(string _name, int _age, char _sex, int _birth, int _death);
    Person(string _name, int _age, char _sex, int _birth, int _death, string _contribution);
    Person(string _name, int _age, char _sex, int _birth, int _death, string _contribution, int _truringYear);
};

#endif // PERSON_H
