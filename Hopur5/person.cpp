#include <string>
#include <iostream>

#include "person.h"

using namespace std;

Person::Person(){
    _name = "";
    _age = "";
    _sex = ' ';
    _birth = "";
    _death = "";
    _contribution = "";
    _turingYear = "";
    _turing = false;
}

Person::Person(string name, string age, char sex, string birth, string death, string contribution, string truringYear){
    _name = name;
    _age = age;
    _sex = sex;
    _birth = birth;
    _death = death;
    _contribution = contribution;
    _turingYear = truringYear;
    if(truringYear.size()<4)
        _turing = false;
    else
        _turing = true;
}

bool Person::isSame(Person p){
    cout << p.getName() << " != " << this->getName();
    return(     this->getName().find(p.getName()) != std::string::npos &&
                this->getAge().find(p.getAge()) != std::string::npos &&
                this->getBirth().find(p.getBirth()) != std::string::npos
                );
}

bool operator==(Person p, Person p2){
    if(p.getName().find(p2.getName()) != std::string::npos
            /*&& p.getAge().find(p2.getAge()) != std::string::npos*/
            && p.getBirth().find(p2.getBirth()) != std::string::npos
            && p.getDeath().find(p2.getDeath()) != std::string::npos
            && p.getSex() == p2.getSex())
        return true;
    else
        return false;
}

void Person::showPerson(){
    cout << "NAME: " << this->_name << endl;
    cout << "AGE: " << this->_age << endl;
    cout << "SEX: " << this->_sex << endl;
    cout << "BIRTH: " << this->_birth << endl;
    cout << "DEATH: " << this->_death << endl;
    cout << "CONTRIBUTION: " << this->_contribution << endl;
    cout << "TURINGYEAR: " << this->_turingYear << endl;
}

