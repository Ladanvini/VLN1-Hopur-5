#include <QCoreApplication>
#include <iostream>
#include "database.h"

int main(int argc, char *argv[])
{
//    QCoreApplication a(argc, argv);
    cout << "I'm here"<< endl;
    Database* db = new Database("/home/ladanvini/Documents/VLN1/VLN1-Hopur-5/Hopur5/database.txt");
    return 0;
    //return a.exec();
}
