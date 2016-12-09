#ifndef LINKSERVICE_H
#define LINKSERVICE_H
#include "database.h"

class LinkService
{
private:
    Links _link;
    Database _db;
    vector<Links> _linkList;

public:
    LinkService();
    LinkService(Database db);
    void create(string comuterID, string personID);
    string showLinksTable(vector<Links> display);
};

#endif // LINKSERVICE_H
