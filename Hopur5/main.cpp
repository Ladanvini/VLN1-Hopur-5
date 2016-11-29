#include <QCoreApplication>
#include <iostream>
#include "consoleui.h"

int main(int argc, char *argv[])
{
    ConsoleUI ui;

    ui.runUI();

//    QCoreApplication a(argc, argv);
  //  cout << "I'm here"<< endl;
  //  Database* db = new Database("/home/ladanvini/Documents/VLN1/VLN1-Hopur-5/Hopur5/database.txt");
  //  Process* doStuff = new Process(*db);


    return 0;
    //return a.exec();
}
