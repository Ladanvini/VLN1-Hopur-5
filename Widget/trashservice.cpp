#include "trashservice.h"

TrashService::TrashService()
{

}

vector<Comps> TrashService::getTrashComp(){
    QString _dbpath =  QCoreApplication::applicationDirPath() + "/create.sqlite";

    Database db(_dbpath);
    return db.getTrashComps();
}
vector<Person> TrashService::getTrashPeople()
{
    QString _dbpath =  QCoreApplication::applicationDirPath() + "/create.sqlite";

    Database db(_dbpath);
    return db.getTrashPeople();
}
vector<Links> TrashService::getTrashLinks()
{
    QString _dbpath =  QCoreApplication::applicationDirPath() + "/create.sqlite";

    Database db(_dbpath);

    return db.getTrashLinks();
}

void TrashService::restoreComp(Comps c)
{
    QString _dbpath =  QCoreApplication::applicationDirPath() + "/create.sqlite";

    Database db(_dbpath);

    db.restoreComp(c);
}
void TrashService::restoreLink(Links l)
{
    QString _dbpath =  QCoreApplication::applicationDirPath() + "/create.sqlite";

    Database db(_dbpath);
    db.restoreLink(l);
}
void TrashService::restorePers(Person p)
{
    QString _dbpath =  QCoreApplication::applicationDirPath() + "/create.sqlite";

    Database db(_dbpath);
    db.restorePers(p);
}
