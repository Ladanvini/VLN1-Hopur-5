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

    //Getters
    vector<Comps> getList();

    //Create
    string create(int id, string name, string type, int yearBuilt, bool built);

    //Search
    vector<Comps> searchByName(string name);
    vector<Comps> searchById(int id);
    vector<Comps> searchByType(string type);
    vector<Comps> searchByBuilt(int yearBuilt);

    //Sort
    vector<Comps> sortByName();
    vector<Comps> sortByType();
    vector<Comps> sortByBuilt();
    vector<Comps> sortByID();
    vector<Comps> sortByNameDec();
    vector<Comps> sortByTypeDec();
    vector<Comps> sortByBuiltDec();
    vector<Comps> sortByIDDec();

    //Delete
    string deleteComputers(string name, string type);

    // Edit

    // Showing
    string showComputers(vector<Comps> results);
    string showComputersTable(vector<Comps> results);

    //Tools and misc.
    bool containsID(vector<int> ids, int id);
    bool checkIDExists(string id);

    //geet comp ID
    int getCompID(string name, string type);

};

#endif // COMPSERVICE_H
