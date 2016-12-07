#ifndef P_C_CONNECTION_H
#define P_C_CONNECTION_H

#include "comps.h"
#include "person.h"

// User can connect many computers.
// Every computer can be connected to every persons.
// These connection have to be able for displaying and maintaince.

class P_C_Connection {
private:
    Comps _computer;
    Person _person;
public:
    P_C_Connection();
    P_C_Connection(Comps c, Person p);

    Comps getCom() { return _computer; }
    Person getPerson() { return _person; }
    bool compare(P_C_Connection pccon);
    string displayConnection();

};

#endif // P_C_CONNECTION_H
