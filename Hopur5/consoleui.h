#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include "appservice.h"
#include "compservice.h"

#include <string>

using namespace std;

class ConsoleUI {
private:
    CompService _compService;
    appservice _appservice;
public:
    ConsoleUI();
    ConsoleUI(appservice p, CompService c);
    string inputHandling();
    //string tolower();
    void searchMenu();
    void sortMenu();
    void createMenu();

    void searchMenuPerson();
    void sortMenuPerson();
    void createMenuPerson();
    void runUI();
    string unicorn();
    void displayList();

    void searchMenuComp();
    void sortMenuComp();
    void createMenuComp();
    void runUIComp();
    void displayListComp();
};

#endif // CONSOLEUI_H
