#include <QCoreApplication>
#include <iostream>

#include "consoleui.h"




using namespace std;

int main(int argc, char *argv[]) {
/* ################ATTENTION################
 * Please make sure the file database.txt is in the build folder of your project
 * with relevance to the compiler you´re using
*/

    QCoreApplication a(argc, argv);



//    string path = QCoreApplication::applicationDirPath().toStdString() + "/database.txt";
    Database* db = new Database("/Users/BjarniKristinn/VLN1-Hopur-5/create.sqlite");
    Process* doStuff = new Process(*db);

    ConsoleUI ui(*doStuff);
    ui.runUI();
    return 0;
}
