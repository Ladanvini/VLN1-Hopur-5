#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <vector>
#include <algorithm>
#include <QtSql>
#include "links.h"

#define clearScreen() printf("\033[H\033[J")

using namespace std;

class Database {
private:
    QSqlDatabase _db;
    Person person;
    vector<Person> _people;
    string _dbFile;
    QString _dbName;
    vector<Comps> _computers;
    vector<Links> _connections;
public:
    Database();

    //Constructor opens connection and fills vectors from the database.
    Database(QString dbFile);
    QString getDbName() {
        return _dbName;
    }

    //Returns list of computers from the database.
    vector<Comps> getComputerList();

    //Returns list of people from the database.
    vector<Person> getList();
    vector<Links> getConnectionList();

    //Updates the vector people.
    void update(vector<Person> peeps);

    //Updates the vector computers.
    void updateCompDB(vector<Comps> comps);

    //Updates the vector links
    void updateLinkDB(vector<Links> links);

    //Adds a person to the database.
    void writeToDB(Person p);

    //Adds a computer to the database.
    void writeToCompDB(Comps c);

    //Checks if the person already exists.
    bool exists(Person p);

    //Checks if the computer already exists.
    bool existsInCompDB(Comps c);

    //Checks if connection already exists
    bool existsInConns(Links pccon);

    //Deletes a person from the database.
    void delFromDB(Person p);

    //Deletes a computer from the database.
    void delFromCompDB(Comps c);

    //Add connection to database
    void addToConsDB(Links l);

    //TODO delete the following functions!
    void deleteCons(int cId, int pId);

    //Edit person
    void editDB(Person p);

    //Edit Computers
    void editCompDB(Comps c);

    //Add to trash
    void trashComp(Comps c);
    void trashPers(Person p);
    void trashLink(Links l);

    vector<Comps> getTrashComps();
    vector<Person> getTrashPeople();
    vector<Links> getTrashLinks();

    //Restore from trash
    void restoreComp(Comps c);
    void restorePers(Person p);
    void restoreLink(Links l);

};

#endif // DATABASE_H
