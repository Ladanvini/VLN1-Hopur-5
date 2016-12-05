#ifndef COMPSERVICE_H
#define COMPSERVICE_H
#include "comps.h"
#include <vector>
class CompService {
private:
    Comps _comp;
    Database _db;
    vector<Comps> computers;
public:
    CompService();
    CompService(Database db);
    vector<Person> getList() { return people; }

    // Create
    string create(string name, string type, bool built);
    //Search
    vector<Comps> searchByName(string name);
    vector<Comps> searchByType(string type);
    vector<Comps> searchByBuilt(string contribution);
    // Sort
    vector<Comps> sortByName();
    vector<Comps> sortByType();


    vector<Comps> sortByBuilt();

    //DELETE
    string deleteComputers(string name, string type);
    // Edit
    // Showing
    string showComputers(vector<Comps> results);


};

#endif // COMPSERVICE_H
