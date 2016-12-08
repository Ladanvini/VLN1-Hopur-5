#ifndef COMPSERVICE_H
#define COMPSERVICE_H

#include <ctime>
#include "database.h"


class CompService {
private:
    Comps _comp;
    Database _db;
    vector<Comps> computers;
public:
    CompService();
    CompService(Database db);
    //GETTERS
    vector<Comps> getList() { return computers; }

    // Create
    string create(int id, string name, string type, int yearBuilt, bool built);
    //Search
    vector<Comps> searchByName(string name);
    vector<Comps> searchById(int id);
    vector<Comps> searchByType(string type);
    vector<Comps> searchByBuilt(int yearBuilt);
    // Sort
    vector<Comps> sortByName();
    vector<Comps> sortByType();
    vector<Comps> sortByBuilt();
    vector<Comps> sortByID();
    //DELETE
    string deleteComputers(string name, string type);
    // Edit
    // Showing
    string showComputers(vector<Comps> results);
    bool containsID(vector<int> ids, int id);
};

#endif // COMPSERVICE_H
