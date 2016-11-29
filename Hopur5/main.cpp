#include <QCoreApplication>
#include <iostream>
#include "database.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Database* db = new Database("database");

    return a.exec();
}
