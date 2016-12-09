#ifndef LINKS_H
#define LINKS_H

#include "comps.h"
#include "person.h"

class Links
{
private:
    Comps _computer;
    Person _person;
public:
    Links();
    Links(Comps c, Person p);
    string showLink();
};


#endif // LINKS_H
