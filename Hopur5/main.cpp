#include <QCoreApplication>
#include <iostream>

#include "consoleui.h"
#include "appservice.h"
#include "database.h"



using namespace std;

int main(int argc, char *argv[]) {
/* ################ATTENTION################
 * Please make sure the file database.txt is in the build folder of your project
 * with relevance to the compiler you´re using
*/

    QCoreApplication a(argc, argv);



//    string path = QCoreApplication::applicationDirPath().toStdString() + "/database.txt";
    Database* db = new Database("/home/ladanvini/Documents/VLN1/VLN1-Hopur-5/create.sqlite");
    appservice* doStuff = new appservice(*db);
    CompService* cs = new CompService(*db);
    ConsoleUI ui(*doStuff, *cs);
    ui.runUI();
    //ui.runUIComp();
    return 0;
}
