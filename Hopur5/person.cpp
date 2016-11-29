#include "person.h"

Person::Person()
{
    name = "";
    age = 0;
    sex = ' ';
    birth = 0;
    death = 0;
    contribution = "";
    turingYear = 0;
    turing = false;

}
Person::Person(string _name, int _age, char _sex, int _birth){
    name = _name;
    age = _age;
    sex = _sex;
    birth = _birth;
    death = 0;
    contribution = "";
    turingYear = 0;
    turing = false;
}
Person::Person(string _name, int _age, char _sex, int _birth, int _death){
    name = _name;
    age = _age;
    sex = _sex;
    birth = _birth;
    death = _death;
    contribution = "";
    turingYear = 0;
    turing = false;
}
Person::Person(string _name, int _age, char _sex, int _birth, int _death, string _contribution){
    name = _name;
    age = _age;
    sex = _sex;
    birth = _birth;
    death = _death;
    contribution = _contribution;
    turingYear = 0;
    turing = false;
}
Person::Person(string _name, int _age, char _sex, int _birth, int _death, string _contribution, int _truringYear){
    name = _name;
    age = _age;
    sex = _sex;
    birth = _birth;
    death = _death;
    contribution = _contribution;
    turingYear = _truringYear;
    turing = true;
}


