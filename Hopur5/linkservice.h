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

    //Create and showing
    string create(string comuterID, string personID);
    string showLinksTable(vector<Links> display);

    //Getters
    vector<Links> getLinkList();
    vector<Comps> getCompList();
    vector<Person> getPersList();

    //Checks if exists
    bool exists(Links l);

};

#endif // LINKSERVICE_H
