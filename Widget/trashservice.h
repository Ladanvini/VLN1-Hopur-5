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
    vector<Comps> getTrashComp();
    vector<Person> getTrashPeople();
    vector<Links> getTrashLinks();

    void restoreComp(Comps c);
    void restorePers(Person p);
    void restoreLink(Links l);

    void emptyCompTrash();
    void emptyPersTrash();
    void emptyLinkTrash();

};

#endif // TRASHSERVICE_H
