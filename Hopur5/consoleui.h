#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include "appservice.h"
#include "compservice.h"
#include "connectionservice.h"


#include <string>

using namespace std;

class ConsoleUI {
private:
    CompService _compService;
    appservice _appservice;
    connectionService _linkService;
public:
    ConsoleUI();
    ConsoleUI(appservice p, CompService c, connectionService l);

    string inputHandling();
    string unicorn();
    string cORp(string name);
    void displayList();

    void searchMenu();
    void sortMenu();
    void createMenu();
    void deleteMenu();
    void linkMenu();

    void searchMenuPerson();
    void sortMenuPerson();
    void createMenuPerson();
    void deleteMenuPerson();
    void runUI();


    void searchMenuComp();
    void sortMenuComp();
    void createMenuComp();
    void deleteMenuComp();
    void runUIComp();
    void displayListComp();

};

#endif // CONSOLEUI_H
