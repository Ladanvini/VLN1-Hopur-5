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
bool Links::compare(Links l){
    if(
            this->_computer.getId() == l._computer.getId()
         && this->_person.getId() == l._person.getId()
            )
        return true;
    return false;
}
int Links::getCID(){
    return _computer.getId();
}
int Links::getPID(){
    return _person.getId();
}
