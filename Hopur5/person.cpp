#include <string>
#include <iostream>

#include "person.h"

using namespace std;

Person::Person() {
    _name = "";
    _id = 0;
    _age = 0;
    _sex = ' ';
    _birth = 0;
    _death = 0;
    _contribution = "";
    _turingYear = 0;
    _turing = false;
}

Person::Person(int id, string name, int age, char sex, int birth, int death, string contribution, int truringYear) {
    _name = name;
    _id = id;
    _age = age;
    _sex = sex;
    _birth = birth;
    _death = death;
    _contribution = contribution;
    _turingYear = truringYear;
    if(truringYear == 0)
        _turing = false;
    else
        _turing = true;
}

bool Person::isSame(Person p) {
    cout << p.getName() << " != " << this->getName();
    return(     this->getName().find(p.getName()) != std::string::npos &&
                this->getAge() == (p.getAge()) &&
                this->getBirth() == (p.getBirth())
                );
}

bool operator==(Person p, Person p2) {
    if(p.getName().find(p2.getName()) != std::string::npos
            && p.getBirth() == (p2.getBirth())
            && p.getDeath() == (p2.getDeath())
            && p.getSex() == p2.getSex())
        return true;
    else
        return false;
}

string Person::showPerson() {
    string temp = "";

    temp = temp + "NAME: " + this->_name + '\n';
    temp = temp + "AGE OF CONTRIBUTION: " + std::to_string(this->_age) + '\n';
    temp = temp + "SEX: " + this->_sex + '\n';
    temp = temp + "BIRTH: " + std::to_string(this->_birth) + '\n';
    temp = temp + "DEATH: " + std::to_string(this->_death) + '\n';
    temp = temp + "CONTRIBUTION: " + this->_contribution + '\n';
    temp = temp + "TURINGYEAR: " + std::to_string(this->_turingYear) + '\n';

    return temp;
}

