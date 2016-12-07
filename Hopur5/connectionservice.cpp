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
