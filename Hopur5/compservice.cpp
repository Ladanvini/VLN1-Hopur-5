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
vector<Comps> sortByName() {
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
vector<Comps> sortByType() {
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


vector<Comps> sortByBuilt() {
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
