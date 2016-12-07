#include "connectionservice.h"



connectionService::connectionService()
{

}

connectionService::connectionService(Database db){

   _db = db;

}

// User to Computers.
string connectionService::connUtoC(Person p, vector<Comps> cv){

    for (unsigned int i = 0 ; i < cv.size(); i++){

        _db.addToConsDB(cv.at(i), p);

    }



}
// Computer to users.

string connectionService::connCtoU(Comps c, vector<Person> pV){

    for (unsigned int i = 0 ; i < pV.size(); i++){

        _db.addToConsDB(c, pV.at(i));
    }


}
