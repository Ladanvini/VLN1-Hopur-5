#include <QCoreApplication>
#include <iostream>

#include "consoleui.h"

using namespace std;

int main(int argc, char *argv[]) {

    QCoreApplication a(argc, argv);

    string path = QCoreApplication::applicationDirPath().toStdString() + "/database.txt";
    Database* db = new Database(path);
    Process* doStuff = new Process(*db);

    ConsoleUI ui(*doStuff);
    ui.runUI();

    return 0;
}
