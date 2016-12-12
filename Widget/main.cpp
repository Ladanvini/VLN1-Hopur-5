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

    QString path = QCoreApplication::applicationDirPath() + "/create.sqlite";

    Database* db = new Database(path);
    appservice* doStuff = new appservice(*db);
    CompService* cs = new CompService(*db);
    LinkService* ls = new LinkService(*db);
    //ConsoleUI ui(*doStuff, *cs, *ls);
    //ui.runUI();
    return 0;
}
