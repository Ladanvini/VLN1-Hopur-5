#include "links.h"

Links::Links() {
    _computer = Comps();
    _person = Person();
}

Links::Links(Comps c, Person p) {
    _computer = c;
    _person = p;
}

//Tools and misc.
string Links::showLink() {
    string temp = "";
    temp = temp +
            margins(7, std::to_string(this->_computer.getId()) ) +
            margins(15, this->_computer.getName() );
    temp = temp + " <---> ";

    temp = temp +
            margins(7, std::to_string(this->_person.getId())) +
            margins(15, this->_person.getName());
    return temp;
}

bool Links::compare(Links l) {
    if(
            this->_computer.getId() == l._computer.getId()
         && this->_person.getId() == l._person.getId()
            )
        return true;
    return false;
}

string Links::margins(unsigned int cellSize, string value) {
   string sstr = "";
   int space = (cellSize - value.size())/2;
   if(value.size() >= cellSize) {
        value = value.substr(0, cellSize-3);
        value = value + "...";
   }
    else {
        for(int i=0; i<space; i++)
            sstr = sstr + " ";
    }
    return "|" + sstr + value + sstr + "|";
}

//Getters
int Links::getCID() {
    return _computer.getId();
}
int Links::getPID() {
    return _person.getId();
}


