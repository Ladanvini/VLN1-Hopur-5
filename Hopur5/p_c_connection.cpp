#include "p_c_connection.h"

P_C_Connection::P_C_Connection()
{

}
P_C_Connection::P_C_Connection(Comps c, Person p){

    _computer = c;
    _person = p;
}

string P_C_Connection::displayConnection(){
}
bool P_C_Connection::compare(P_C_Connection pccon)
{
    if( this->_computer.getId() == pccon.getCom().getId()
       && this->_person.getId() == pccon.getPerson() .getId()
            )
        return true;
    return false;
}






