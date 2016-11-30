#include <QCoreApplication>
#include <iostream>
#include "appservice.h"
#include "consoleui.h"

using namespace std;

int main(int argc, char *argv[])
{
     //ConsoleUI ui;
  //   ui.runUI();


//    QCoreApplication a(argc, argv);
    cout << "I'm here"<< endl;
    Database* db = new Database("/home/ladanvini/Documents/VLN1/VLN1-Hopur-5/Hopur5/database.txt");
    Process* doStuff = new Process(*db);
   // vector<Person> sbyname = doStuff->searchByName("Hoar");
   // vector<Person> sbyage = doStuff->searchByAge("");
   // vector<Person> sbysex = doStuff->searchBySex('f');
   // vector<Person> sbyTuring = doStuff->searchByTuring(true);

    doStuff->create("Smari Looooovely <3 ", "21", 'm', "1995", "2016", "being thought of when people go to the bathroom", "0");


 /*   for(int i=0; i<sbyTuring.size(); i++)
        sbyTuring.at(i).showPerson();
 */   return 0;
    //return a.exec();
}
