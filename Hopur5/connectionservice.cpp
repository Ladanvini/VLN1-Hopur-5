#include "connectionservice.h"



connectionService::connectionService()
{

}

connectionService::connectionService(Database db){

   _db = db;

}

// User to Computers.
string connectionService::connUtoC(Person p, vector<Comps> cv){

    if(!_db.exists(p))
        return "Person does not exist\n";

    for (unsigned int i = 0 ; i < cv.size(); i++){
        if(!_db.existsInCompDB(cv.at(i)))
            return "Computer with id: " + std::to_string(cv.at(i).getId()) + "does not exist\n";
        if(_db.existsInConns(P_C_Connection(cv.at(i), p)))
            return "Connection between person with ID: " + std::to_string(p.getId()) +
                    "and computer with ID: " + std::to_string(cv.at(i).getId()) + " already exists\n";
        _db.addToConsDB(cv.at(i), p);

    }

    return "Connections added successfully\n";

}
// Computer to users.

string connectionService::connCtoU(Comps c, vector<Person> pV){

    if(!_db.existsInCompDB(c))
        return "Computer not found\n";
    for (unsigned int i = 0 ; i < pV.size(); i++){
        if(!_db.exists(pV.at(i))){
            return "Person with ID: " + std::to_string(pV.at(i).getId()) + " Does not exist\n";
        }
        if(_db.existsInConns(P_C_Connection(c, pV.at(i))))
            return "Connection between person with ID: " + std::to_string(pV.at(i).getId()) +
                    "and computer with ID: " + std::to_string(c.getId()) + " already exists\n";
        _db.addToConsDB(c, pV.at(i));
    }

    return "Connections added successfully\n";
}
string connectionService::addConnPtoC(string pIDstr, vector<string> cIdstr){
    Person p;
    int pID = stoi(pIDstr);

    bool flag = false;
    vector<Comps> cv;
    for(unsigned int i=0; i< _db.getList().size() && !flag; i++){
        if(_db.getList().at(i).getId() == pID){
            p = _db.getList().at(i);
            flag = true;
        }
    }
    for(unsigned int i=0; i<_db.getComputerList().size() ; i++){

        for(unsigned int j=0; j<cIdstr.size(); j++){
            if(_db.getComputerList().at(i).getId() == stoi(cIdstr.at(j)))
                cv.push_back(_db.getComputerList().at(i));
        }
    }
    return connUtoC(p, cv);
}

string connectionService::addConnCtoP(string cID, vector<string> pIds){
    Comps c;
    bool flag = false;
    for(unsigned int i = 0; i< _db.getComputerList().size() && !flag; i++){
        if(_db.getComputerList().at(i).getId() == stoi(cID)){
            c = _db.getComputerList().at(i);
            flag = true;
        }
    }
    vector<Person> pv;
    for(unsigned int i =0; i<_db.getList().size(); i++){
        for(unsigned int j=0; j<pIds.size(); j++){
            if(_db.getList().at(i).getId() == stoi(pIds.at(j)))
                pv.push_back(_db.getList().at(i));
        }
    }

    return connCtoU(c, pv);
}

string connectionService::deleteConn(string cIdstr, string pIdstr){
    int cId = stoi(cIdstr);
    int pId = stoi(pIdstr);

    _db.deleteCons(cId, pId);


}