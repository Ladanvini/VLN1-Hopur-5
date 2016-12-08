#include "p_c_connection.h"

P_C_Connection::P_C_Connection() {

}

P_C_Connection::P_C_Connection(Comps c, Person p) {
    _computer = c;
    _person = p;
}

string P_C_Connection::displayConnection() {
    string temp = "";
    temp = temp + " ( " + std::to_string(this->_computer.getId());
    temp = temp + " ) " + this->_computer.getName();
    temp = temp + "<--->";
    temp = temp + " ( " + std::to_string(this->_person.getId());
    temp = temp + " ) " + this->_person.getName();

    return temp;
}

bool P_C_Connection::compare(P_C_Connection pccon) {
    if( this->_computer.getId() == pccon.getCom().getId()
        && this->_person.getId() == pccon.getPerson() .getId()) {
            return true;
    }
    return false;
}






