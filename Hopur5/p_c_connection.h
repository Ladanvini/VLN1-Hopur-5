#ifndef P_C_CONNECTION_H
#define P_C_CONNECTION_H
#include "comps.h"
#include "person.h"


// User can connect many computers.
// Every computer can be connected to every persons.
// These connection have to be able for displaying and maintaince.
class P_C_Connection
{
private:
    Comps _computer;
    Person _person;

public:
    P_C_Connection();
    string connUtoC(Person p, vector<Comps> cv);
    string connCtoU(Comps c, vector<Person> pV);
    string displayConnection();





};

#endif // P_C_CONNECTION_H
