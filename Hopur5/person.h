#ifndef PERSON_H
#define PERSON_H
#include <string>
#include<vector>

using namespace std;

class Person
{
private:
    string _name;
    string _age;
    char _sex;
    string _birth;
    string _death;
    string _contribution;
    string _turingYear;
    bool _turing;
public:
    Person();
    Person(string name, string age, char sex, string birth, string death, string contribution, string truringYear);
    void showPerson();
    string getName() { return _name; }
    string getAge() {return _age; }
    char getSex(){ return _sex; }
    string getBirth(){ return _birth; }
    string getDeath(){ return _death; }
    string getContribution() { return _contribution; }
    string getTuring() { return _turingYear; }

};

#endif // PERSON_H
