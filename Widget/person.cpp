#include <string>
#include <iostream>
#include <ctime>
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

Person::Person(int id, string name, char sex, int birth, int death, string contribution, int truringYear) {
    _name = name;
    _id = id;
    _sex = sex;
    _birth = birth;
    _death = death;
    _contribution = contribution;
    _turingYear = truringYear;
    if(truringYear == 0)
        _turing = false;
    else
        _turing = true;

    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    int currYear = (now->tm_year + 1900);
    //int currMonth = (now->tm_mon + 1);
    //int currDay = now->tm_mday;

    if(death == 0)
        _age = currYear - birth;
    else
        _age = death - birth;
}

//Friend
bool operator==(Person p, Person p2) {
    if(p.getName().find(p2.getName()) != std::string::npos
            && p.getBirth() == (p2.getBirth())
            && p.getDeath() == (p2.getDeath())
            && p.getSex() == p2.getSex())
        return true;
    else
        return false;
}

//Showing
string Person::showPerson() {
    string temp = "";
    temp = temp + "ID: " + std::to_string(this->_id) + '\n';
    temp = temp + "NAME: " + this->_name + '\n';
    temp = temp + "AGE: " + std::to_string(this->_age) + '\n';
    temp = temp + "SEX: " + this->_sex + '\n';
    temp = temp + "BIRTH: " + std::to_string(this->_birth) + '\n';
    temp = temp + "DEATH: " + std::to_string(this->_death) + '\n';
    temp = temp + "CONTRIBUTION: " + this->_contribution + '\n';
    temp = temp + "TURINGYEAR: " + std::to_string(this->_turingYear) + '\n';

    return temp;
}
string Person::showPersonTable() {
    string temp = "";
    int cellsize = 15;
    string spTemp;

    spTemp = spaceCalc(cellsize,std::to_string(this->_id));
    temp = temp + "|"+ spTemp ;
    spTemp = spaceCalc(cellsize,this->_name);
    temp = temp + "|" + spTemp ;
    spTemp = spaceCalc(cellsize,std::to_string(this->_age));
    temp = temp + "|" + spTemp ;

    temp = temp + "|       " + this->_sex + "       ";
    spTemp = spaceCalc(cellsize,std::to_string(this->_birth));
    temp = temp + "|" + spTemp ;
    spTemp = spaceCalc(cellsize,std::to_string(this->_death));
    temp = temp + "|" + spTemp ;
    spTemp = spaceCalc(cellsize,std::to_string(this->_turingYear));
    temp = temp + "|" + spTemp  + "|\n";

    return temp;
}

//Tools and misc.
string Person::spaceCalc(int cellsize, string value) {
    string idTemp = "";
    int idSize = value.size();

    if(idSize>=cellsize) {
        value = value.substr(0, cellsize-3);
        value = value + "... ";
    }
    else {
        unsigned int spaceSize = cellsize - idSize;
        if(spaceSize%2 != 0)
            spaceSize++;

        for(int unsigned i=0; i<spaceSize/2; i++)
            idTemp = idTemp + " ";
    }
    return idTemp + value + idTemp;
}
bool Person::isSame(Person p) {
    cout << p.getName() << " != " << this->getName();
    return(     this->getName().find(p.getName()) != std::string::npos &&
                this->getAge() == (p.getAge()) &&
                this->getBirth() == (p.getBirth())
                );
}
