#ifndef LINKSERVICE_H
#define LINKSERVICE_H

#include "database.h"
#include "appservice.h"
#include "compservice.h"

class LinkService {
private:
    Links _link;
    Database _db;
    vector<Links> _linkList;
    vector<Comps> _compList;
    vector<Person> _persList;
    vector<Links> trash;
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
    bool exists(int cid, int pid);
    //Delete link
    string deleteLink(int cid, int pid);
    //Updates Links after person has been deleted
    void updateLinkc(int cid);
    //Updates Links after computer has been deleted
    void updateLinkp(int pid);
    //Searching
    vector<Links> searchByName(string name);
    vector<Links> searchById(string id);

};

#endif // LINKSERVICE_H
