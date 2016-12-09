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
    bool compare(Links l);
    int getCID();
    int getPID();
    string margins(int cellSize, string value);
};


#endif // LINKS_H
