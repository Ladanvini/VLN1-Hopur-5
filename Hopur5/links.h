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

    //Tools and misc.
    string showLink();
    bool compare(Links l);
    string margins(int cellSize, string value);

    //Getters
    int getCID();
    int getPID();
};


#endif // LINKS_H
