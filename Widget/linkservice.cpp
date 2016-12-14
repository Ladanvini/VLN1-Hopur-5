#include <iostream>
#include "linkservice.h"

using namespace std;

LinkService::LinkService() {

}

LinkService::LinkService(Database db) {
    _db = db;
    _linkList = db.getConnectionList();
    _compList = db.getComputerList();
    _persList = db.getList();
}

//Getters
vector<Links> LinkService::getLinkList() {
    return _linkList;
}
vector<Comps> LinkService::getCompList() {
    return _compList;
}
vector<Person> LinkService::getPersList() {
    return _persList;
}

//Creates a new link
string LinkService::create(string computerID, string personID) {
    bool flagc = false;
    bool flagp = false;

    int cID = stoi(computerID);
    int pID = stoi(personID);

    Comps c;
    Person p;
    _db = Database(_db.getDbName());
    _linkList = _db.getConnectionList();
    _compList = _db.getComputerList();
    _persList = _db.getList();

    for(unsigned int i = 0; i < _compList.size(); i++) {
        if(!flagc && _compList.at(i).getId() == cID) {
            c = _compList.at(i);
            flagc = true;
        }
    }
    for(unsigned int i = 0; i < _persList.size(); i++) {
        if(!flagp && _persList.at(i).getId() == pID) {
            p = _persList.at(i);
            flagp = true;
        }
    }
    if(!flagc)
        return "Computer " + computerID + " Not Found\n";
    if(!flagp)
        return "Person " + personID + " Not Found\n";
    if(exists(stoi(computerID), stoi(personID)))
        return "Link already exists\n";

    _linkList.push_back(Links(c, p));
    _db.updateLinkDB(_linkList);
    _db.addToConsDB(Links(c, p));

    _db = Database(_db.getDbName());
    _linkList = _db.getConnectionList();
    _compList = _db.getComputerList();
    _persList = _db.getList();
    clearScreen();

    return "Link added successfully\n";
}

//Checks if link exists
bool LinkService::exists(int cid, int pid) {
    for(unsigned int i = 0; i < _linkList.size(); i++) {
        if(cid == (_linkList.at(i)).getCID()
              && pid == (_linkList.at(i)).getPID())
            return true;
    }
    return false;
}

//Showing
string LinkService::showLinksTable(vector<Links> display) {
    string temp = "";
    temp = temp + "|       COMPUTER        | <---> |         PERSON        |\n"
                  "|   ID  |      NAME     | <---> |   ID  |      NAME     |\n";

    for(unsigned int i = 0; i < display.size(); i++)
        temp = temp + (display.at(i)).showLink();

    return temp;
}

//Deleting links
string LinkService::deleteLink(int cid, int pid) {
    if(!exists(cid, pid))
        return "Link does not exist\n";

    bool flag = false;
    for(unsigned int i = 0; i < _linkList.size() && !flag; i++) {
        if(cid == (_linkList.at(i)).getCID()
                && pid == (_linkList.at(i)).getPID()) {
            flag = true;
            _linkList.erase(_linkList.begin() + i);
        }
    }
    _db.updateLinkDB(_linkList);
    _db.deleteCons(cid, pid);

    return "Link deleted successfully\n";
}

void LinkService::updateLinkc(int cid) {
    for(unsigned int i = 0; i < _linkList.size(); i++) {
        if(_linkList.at(i).getCID() == cid) {
            _linkList.erase(_linkList.begin() + i );
            cerr<< "SURPRISE BITCHEEES" << endl;
        }
    }
    _db.updateLinkDB(_linkList);
}

void LinkService::updateLinkp(int pid) {
    for(unsigned int i = 0; i < _linkList.size(); i++) {
        if(_linkList.at(i).getPID() == pid) {
            _linkList.erase(_linkList.begin() + i );
        }
    }
    _db.updateLinkDB(_linkList);
}
