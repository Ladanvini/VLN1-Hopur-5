#include "compservice.h"

CompService::CompService()
{

}
CompService::CompService(Database db){
    _db = db;
    computers = _db.getComputerList();

}
// Create
string CompService::create(string name, string type, string yearBuilt, bool built){

    Comps* newComputer = new Comps(name, type, yearBuilt, built);
    bool flag = false;

    if(
            (yearBuilt.size() > 4 ||!(yearBuilt.size() == 4 || yearBuilt.find("0") != std::string::npos))
            )
        return "unacceptable value in one of the fields\n";

    if(db.exists(*newComputer)) {
        flag = true;
    }
    if(flag) {
       return "Computer already exists\n";
    }
    Computers.push_back(*newComputer);

    db.update(computers);
    db.writeToDB(*newComputer);
    return "Added successfully\n";
}





    /*

    bool flag = false;



*/
}

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
