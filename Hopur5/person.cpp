#include "person.h"
#include <string>
#include <iostream>

using namespace std;

Person::Person()
{
    name = "";
    age = "";
    sex = ' ';
    birth = "";
    death = "";
    contribution = "";
    turingYear = "";
    turing = false;

}

Person::Person(string _name, string _age, char _sex, string _birth, string _death, string _contribution, string _truringYear){
    name = _name;
    age = _age;
    sex = _sex;
    birth = _birth;
    death = _death;
    contribution = _contribution;
    turingYear = _truringYear;
    turing = true;
}
void Person::showPerson(){
    cout << "NAME: " << this->name << endl;
    cout << "AGE: " << this->age << endl;
    cout << "SEX: " << this->sex << endl;
    cout << "BIRTH: " << this->birth << endl;
    cout << "DEATH: " << this->death << endl;
    cout << "CONTRIBUTION: " << this->contribution << endl;
    cout << "TURINGYEAR: " << this->turingYear << endl;

}

