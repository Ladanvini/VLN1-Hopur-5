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
    string unicorn();
    string cORp(string name);
    void displayList();

    void searchMenu();
    void sortMenu();
    void createMenu();
    void deleteMenu();

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
