#include "links.h"

Links::Links()
{
    _computer = Comps();
    _person = Person();
}
Links::Links(Comps c, Person p){
    _computer = c;
    _person = p;
}
string Links::showLink(){
    string temp = "";
    temp = temp +
            "|  " + std::to_string(this->_computer.getId()) + "  "
            "|  " + this->_computer.getName() + "  ";
    temp = temp + " <---> ";

    temp = temp +
            "|  " + std::to_string(this->_person.getId()) + "  "
            "|  " + this->_person.getName() + "  |";
    return temp;
}
