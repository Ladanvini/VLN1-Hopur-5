#ifndef CONNECTIONSERVICE_H
#define CONNECTIONSERVICE_H
#include "database.h"


class connectionService {
private:
    Database _db;
public:
    connectionService();
    connectionService(Database db);

    string connUtoC(Person p, Comps c);
    string connCtoU(Comps c, vector<Person> pV);
    string deleteConn(string cIdstr, string pIdstr);
    string addConnCtoP(string pID, vector<string> cIds);
    string addConn(string pIDstr, string cIdstr);
};

#endif // CONNECTIONSERVICE_H
