#include <QCoreApplication>
#include <iostream>

#include "consoleui.h"

using namespace std;

int main(int argc, char *argv[]) {

    QCoreApplication a(argc, argv);

    string path = QCoreApplication::applicationDirPath().toStdString() + "/database.txt";
    cout << "I'm here"<< endl;
    Database* db = new Database(path);
    Process* doStuff = new Process(*db);
    ConsoleUI ui(*doStuff);
    ui.runUI();

   // vector<Person> sbyname = doStuff->searchByName("Hoar");
   // vector<Person> sbyage = doStuff->searchByAge("");
   // vector<Person> sbysex = doStuff->searchBySex('f');
   // vector<Person> sbyTuring = doStuff->searchByTuring(true);
   // cout << doStuff->create("Arfa Karim", "9", 'f', "1995", "2012", "youngest microsoft certified professional", "0");
   // cout << doStuff->create("Joshua Travis Mann", "8", 'm', "1982", "0", "invented his own OO computer language", "0");
   // cout << doStuff->create("Babar Iqbal", "9", 'm', "2001", "0", "became an MCP in 2010", "0");
   // cout << doStuff->create("John McCarthy", "84", 'f', "1927", "2011", "in AI", "1971");
   // cout << doStuff->create("Whitfield Diffie", "72", 'm', "1944", "0", "New Directions in Cryptography", "2015");
   // cout << doStuff->create("Martin E. Hellman", "71", 'm', "1945", "0", "New Directions in Cryptography", "2015");

 /*   for(int i=0; i<sbyTuring.size(); i++)
        sbyTuring.at(i).showPerson();
 */   return 0;
    //return a.exec();
}
