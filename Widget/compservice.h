#ifndef COMPSERVICE_H
#define COMPSERVICE_H

#include <ctime>
#include "database.h"

class CompService {
private:
    Comps _comp;
    Database _db;
    vector<Comps> computers;
    vector<Comps> trash;
public:
    CompService();
    CompService(Database db);

    //Getters
    vector<Comps> getList();

    //Create
    string create(int id, string name, string type, int yearBuilt, bool built);

    //Search
    vector<Comps> searchByName(string name);
    vector<Comps> searchById(string _id);
    vector<Comps> searchByType(string type);
    vector<Comps> searchByBuilt(string _yearBuilt);

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
    /*
     * First we check if the computer exists with editComputer function,
     * then we open the edit page and have the user input the information
     * then call the editComputerWith function with the information of the computer
     * along with the previously inputted id
     */
    string editComputer(string id);
    void editComputerWith(int id, string name, string type, int yearBuilt);

    // Showing
    string showComputers(vector<Comps> results);
    string showComputersTable(vector<Comps> results);

    //Tools and misc.
    bool containsID(vector<int> ids, int id);
    bool checkIDExists(string id);

    //geet comp ID
    int getCompID(string name, string type);
    Comps getCompFromId(int id);

};

#endif // COMPSERVICE_H
