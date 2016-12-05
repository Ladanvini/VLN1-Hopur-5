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
vector<Comps> CompService::sortByName() {
    vector<string> names;
    vector<Comps> sorted;
    for(unsigned int i = 0; i < computers.size(); i++)
        names.push_back(computers.at(i).getName());

    std::sort(names.begin(), names.end());

    for(unsigned int i = 0; i < names.size(); i++) {
        for(unsigned int j = 0; j < computers.size(); j++)
            if(names.at(i) == computers.at(j).getName())
                sorted.push_back(computers.at(j));
    }

    return sorted;
}
vector<Comps> CompService::sortByType() {
    vector<string> types;
    vector<Comps> sorted;
    for(unsigned int i = 0; i < computers.size(); i++)
        types.push_back(computers.at(i).getType());

    std::sort(types.begin(), types.end());

    for(unsigned int i = 0; i < types.size(); i++) {
        for(unsigned int j = 0; j < computers.size(); j++)
            if(types.at(i) == computers.at(j).getType())
                sorted.push_back(computers.at(j));
    }

    return sorted;

}


vector<Comps> CompService::sortByBuilt() {
    vector<string> builtComps;
    vector<Comps> sorted;
    for(unsigned int i = 0; i < computers.size(); i++)
        builtComps.push_back(computers.at(i).getBuilt());

    std::sort(builtComps.begin(), builtComps.end());

    for(unsigned int i = 0; i < builtComps.size(); i++) {
        for(unsigned int j = 0; j < computers.size(); j++)
            if(builtComps.at(i) == computers.at(j).getBuilt())
                sorted.push_back(computers.at(j));
    }

    return sorted;

}
//DELETE
string deleteComputers(string name, string type);
// Edit
// Showing
string showComputers(vector<Comps> results);
