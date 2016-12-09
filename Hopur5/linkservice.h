#ifndef LINKSERVICE_H
#define LINKSERVICE_H
#include "database.h"

class LinkService
{
private:
    Links _link;
    Database _db;
    vector<Links> _linkList;
    vector<Comps> _compList;
    vector<Person> _persList;

public:
    LinkService();
    LinkService(Database db);
    string create(string comuterID, string personID);
    string showLinksTable(vector<Links> display);
    vector<Links> getLinkList();
    vector<Comps> getCompList();
    vector<Person> getPersList();
    bool exists(Links l);

};

#endif // LINKSERVICE_H
