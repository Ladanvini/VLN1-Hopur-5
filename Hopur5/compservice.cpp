#include "compservice.h"

CompService::CompService()
{

}
CompService::CompService(Database db){
    _db = db;
    computers = _db.getComputerList();

}
// Create
string CompService::create(int id, string name, string type, int yearBuilt, bool built){

    Comps* newComputer = new Comps(id, name, type, yearBuilt, built);
    bool flag = false;

    if(
            (yearBuilt > 100 ||!(yearBuilt != 0 && yearBuilt < 2016 ))
            )
        return "unacceptable value in one of the fields\n";

    if(_db.exists(*newComputer)) {
        flag = true;
    }
    if(flag) {
       return "Computer already exists\n";
    }
    computers.push_back(*newComputer);

    _db.update(computers);
    _db.writeToDB(*newComputer);
    return "Added successfully\n";
}





    /*

    bool flag = false;



*/


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
