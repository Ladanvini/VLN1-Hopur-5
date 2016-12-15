#include<iostream>
#include "compservice.h"

CompService::CompService() {

}

CompService::CompService(Database db) {
    _db = db;
    computers = _db.getComputerList();
}

vector<Comps> CompService::getList() {
    return computers;
}

// Create
string CompService::create(int id, string name, string type, int yearBuilt, bool built) {

    Comps* newComputer = new Comps(id, name, type, yearBuilt, built);
    bool flag = false;

    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    int currYear = (now->tm_year + 1900);

    if(((yearBuilt < 100 && yearBuilt != 0) || yearBuilt > currYear))
        return "Unacceptable value for year built!\n";
    if(type.empty() || type.at(0) == ' ')
        return "Type was not accepted!\n";
    if(name.empty() || name.at(0) == ' ')
        return "Name was not accepted!\n";

    if(_db.existsInCompDB(*newComputer)) {
            flag = true;
    }
    if(flag) {
       return "Computer already exists\n";
    }

    computers.push_back(*newComputer);
    _db.updateCompDB(computers);
    _db.writeToCompDB(*newComputer);

    _db = Database(_db.getDbName());
    computers = _db.getComputerList();

    clearScreen();
    return "Added successfully\n";
}

//Search
vector<Comps> CompService::searchByName(string name) {

    transform(name.begin(), name.end(), name.begin(), ::tolower);
    string _name = "";

    vector<Comps> result;

    for(size_t i = 0; i < computers.size(); i++) {
        _name = computers.at(i).getName();
        transform(_name.begin(), _name.end(), _name.begin(), ::tolower);
        if(_name.find(name) != std::string::npos) {
                result.push_back(computers.at(i));
        }
    }
    return result;
}
vector<Comps> CompService::searchById(int id) {

    vector<Comps> result;

    for (size_t i = 0; i < computers.size(); i++) {
        if(id == computers.at(i).getId()) {
            result.push_back(computers.at(i));
        }
    }
    return result;
}
vector<Comps> CompService::searchByType(string type) {

    vector<Comps> result;

    for(size_t i = 0; i < computers.size(); i++) {
        if(type == computers.at(i).getType()) {
            result.push_back(computers.at(i));
        }
    }
    return result;
}
vector<Comps> CompService::searchByBuilt(int yearBuilt) {

    vector<Comps> result;

    for(size_t i = 0; i < computers.size(); i++) {

        if(yearBuilt == computers.at(i).getYearBuilt()) {
            result.push_back(computers.at(i));
        }
    }
    return result;
}

// Sort
vector<Comps> CompService::sortByName() {

    vector<int> IDs;
    vector<string> names;
    vector<Comps> sorted;

    for(unsigned int i = 0; i < computers.size(); i++)
                names.push_back(computers.at(i).getName());

    std::sort(names.begin(), names.end());

    for(unsigned int i = 0; i < names.size(); i++) {
        for(unsigned int j = 0; j < computers.size(); j++)
            if(names.at(i) == computers.at(j).getName()
            && !containsID(IDs, computers.at(j).getId())) {
                IDs.push_back(computers.at(j).getId());
                sorted.push_back(computers.at(j));
            }
    }
    return sorted;
}
vector<Comps> CompService::sortByNameDec() {
    vector<Comps> Resaults = sortByName();
    reverse(Resaults.begin(), Resaults.end());

    return Resaults;
}
vector<Comps> CompService::sortByType() {
    vector<string> types;
    vector<Comps> sorted;
    vector<int> IDs;

    for(unsigned int i = 0; i < computers.size(); i++)
        types.push_back(computers.at(i).getType());

    std::sort(types.begin(), types.end());

    for(unsigned int i = 0; i < types.size(); i++) {
        for(unsigned int j = 0; j < computers.size(); j++) {

            if(types.at(i) == computers.at(j).getType()
               && !containsID(IDs, computers.at(j).getId())) {

                IDs.push_back(computers.at(j).getId());
                sorted.push_back(computers.at(j));
            }
        }
    }
    return sorted;
}
vector<Comps> CompService::sortByTypeDec() {
    vector<Comps> Resaults = sortByType();
    reverse(Resaults.begin(), Resaults.end());

    return Resaults;
}
vector<Comps> CompService::sortByBuilt() {

    int yearBuilt;
    vector<int> builtComps;
    vector<Comps> sorted;
    vector<int> id;

    for(unsigned int i = 0; i < computers.size(); i++) {
        if(computers.at(i).getBuilt() == false) {
            yearBuilt = 0;
            computers.at(i).setYearBuilt(yearBuilt);
        }
        builtComps.push_back(computers.at(i).getYearBuilt());
    }

    std::sort(builtComps.begin(), builtComps.end());

    for(unsigned int i = 0; i < builtComps.size(); i++) {
        for(unsigned int j = 0; j < computers.size(); j++)
            if(builtComps.at(i) == computers.at(j).getYearBuilt() && !containsID(id, computers.at(j).getId())) {
                id.push_back(computers.at(j).getId());
                sorted.push_back(computers.at(j));
            }
    }
    return sorted;
}
vector<Comps> CompService::sortByBuiltDec() {
    vector<Comps> Resaults = sortByBuilt();
    reverse(Resaults.begin(), Resaults.end());

    return Resaults;
}
vector<Comps> CompService::sortByID() {

    vector<int> IDComps;
    vector<Comps> sorted;
    for(unsigned int i = 0; i < computers.size(); i++)
         IDComps.push_back(computers.at(i).getId());

    std::sort(IDComps.begin(), IDComps.end());

    for(unsigned int i = 0; i < IDComps.size(); i++) {
        for(unsigned int j = 0; j < computers.size(); j++)
            if(IDComps.at(i) == computers.at(j).getId())
                sorted.push_back(computers.at(j));
    }
    return sorted;
}
vector<Comps> CompService::sortByIDDec() {
    vector<Comps> Resaults = sortByID();
    reverse(Resaults.begin(), Resaults.end());

    return Resaults;
}

//####################Delete####################//

string CompService::deleteComputers(string name, string type) {
    bool flag = false;
    string c_name;
    Comps result;

    for(unsigned int i = 0; i < computers.size(); i++) {
        c_name = computers.at(i).getName();

        if(c_name.find(name) != std::string::npos && computers.at(i).getType() == type ) {
            result = computers.at(i);
            computers.erase(computers.begin() + i);
            flag = true;
        }
    }

    if(flag) {
        _db.updateCompDB(computers);
        _db.delFromCompDB(result);
        clearScreen();
        return result.showComputer() +
                "Erased successfully\n";
    }
    return "Computer: \n" + result.getName() + "\n not found\n";
}

// Get ID
int CompService::getCompID(string name, string type) {

    for(unsigned int i = 0; i < computers.size(); i++) {
        string c_name = computers.at(i).getName();

        if(c_name.find(name) != std::string::npos && computers.at(i).getType() == type ) {
            return computers.at(i).getId();
         }
    }
}

// Edit
string CompService::editComputer(string id) {
    if(!checkIDExists(id))
        return "Computer ID: " + id + "does not exist!\n";
}
void CompService::editComputerWith(int id, string name, string type, int yearBuilt) {
    bool built = true;
    if(yearBuilt == 0)
        built = false;
    _db.editCompDB(Comps(id, name, type, yearBuilt, built));
}

// Showing
string CompService::showComputers(vector<Comps> results) {

    string temp = "";

    for(unsigned int i = 0; i < results.size(); i++) {
        temp = temp + "--------------------------------------------------------------\n";
        temp = temp + results.at(i).showComputer();
    }

    if(results.size() == 0) {
        temp = "#########################################################################\n";
        temp = temp + "No Computers Found!\n";
    }

    temp =  temp + "--------------------------------------------------------------\n";
    return temp;
}
string CompService::showComputersTable(vector<Comps> results) {
        string temp = "";
        string line = "";
        for(int i = 0; i < 84; i++)
            line = line + "-";
        line = line + '\n';
        temp = temp + line;
        temp = temp + "|      ID       "
               "|     NAME       "
               "|      TYPE      "
               "|     BUILT     "
               "|     YEAR       |\n";

    for(unsigned int i = 0; i < results.size(); i++) {
        temp = temp + line;
        temp = temp + results.at(i).showComputerTable();
    }
    if(results.size() == 0) {
        temp = "#########################################################################\n";
        temp = temp + "No Computers Found!\n";
    }

    temp =  temp + line;

    return temp;
}

//Tools and misc.
bool CompService::containsID(vector<int> ids, int id) {
    for(unsigned int i = 0; i < ids.size(); i++)
        if(ids.at(i) == id)
            return true;
    return false;
}
bool CompService::checkIDExists(string id) {

    QString _dbpath =  QCoreApplication::applicationDirPath() + "/create.sqlite";

    _db = Database(_dbpath);
    computers = _db.getComputerList();

    bool flag = false;
    if(id == "")
        return false;

    int ID = stoi(id);

    for(unsigned int i = 0; i < computers.size(); i++) {

        if((computers.at(i)).getId() == ID) {
            flag = true;
        }
    }
    return flag;
}
Comps CompService::getCompFromId(int id) {
    QString _dbpath =  QCoreApplication::applicationDirPath() + "/create.sqlite";

    _db = Database(_dbpath);
    computers = _db.getComputerList();

    for(unsigned int i=0; i<computers.size(); i++) {
        if(computers.at(i).getId() == id)
            return computers.at(i);
    }
}
