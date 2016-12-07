#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include "appservice.h"

#include <string>

using namespace std;

class ConsoleUI {
private:
    appservice _appservice;
public:
    ConsoleUI();
    ConsoleUI(appservice p);
    string inputHandling();
    //string tolower();
    void searchMenu();
    void sortMenu();
    void createMenu();
    void runUI();
    string unicorn();
    void displayList();
};

#endif // CONSOLEUI_H
