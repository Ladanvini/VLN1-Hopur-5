#include <string>
#include <iostream>

#include "person.h"

using namespace std;

Person::Person()
{

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
void Person::showPerson(){
    /*
    cout << "NAME: " << this->_name << endl;
    cout << "AGE: " << this->_age << endl;
    cout << "SEX: " << this->_sex << endl;
    cout << "BIRTH: " << this->_birth << endl;
    cout << "DEATH: " << this->_death << endl;
    cout << "CONTRIBUTION: " << this->_contribution << endl;
    cout << "TURINGYEAR: " << this->_turingYear << endl;
*/
}

