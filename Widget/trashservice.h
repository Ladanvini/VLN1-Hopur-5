#ifndef TRASHSERVICE_H
#define TRASHSERVICE_H

#include "linkservice.h"
class TrashService
{
private:
    appservice _ps;
    CompService _cs;
    LinkService _ls;

public:
    TrashService();
    void restoreComp(Comps c);
    void restorePers(Person p);
    void restoreLink(Links l);

};

#endif // TRASHSERVICE_H
