#ifndef CONNECTIONSERVICE_H
#define CONNECTIONSERVICE_H
#include "database.h"


class connectionService
{

private:

    Database _db;

public:
    connectionService();
    connectionService(Database db);

    string connUtoC(Person p, vector<Comps> cv);
    string connCtoU(Comps c, vector<Person> pV);
    string deleteConn(string cIdstr, string pIdstr);
    string addConnPtoC(string pID, vector<string> cIds);
    string addConnCtoP(string cID, vector<string> pIds);
};

#endif // CONNECTIONSERVICE_H
