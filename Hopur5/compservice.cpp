#include "compservice.h"

CompService::CompService()
{

}
CompService::CompService(Database db){
    _db = db;
    computers = _db.getComputerList();

}
// Create
string CompService::create(string name, string type, bool built){

    Comps* newComputer = new Comps(name, type, built);
    bool flag = false;

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
    if(
            (age.size() > 3 || age.size() < 1 || age == "0")
            || (sex != 'm' && sex != 'f')
            || (birth.size() < 4 || birth.size() > 4)
            || (death.size() > 4 ||!(death.size() == 4 || death.find("0") != std::string::npos))
            )
        return "unacceptable value in one of the fields\n";

    if(db.exists(*p)) {
        flag = true;
    }
    if(flag) {
       return "Person already exists\n";
    }
    people.push_back(*p);

    db.update(people);
    db.writeToDB(*p);
    return "Added successfully\n";

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
