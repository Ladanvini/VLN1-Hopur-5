#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include "appservice.h"
#include "compservice.h"
#include "linkservice.h"
#include "tictactoe.h"


#include <string>

using namespace std;

class ConsoleUI {
private:
    CompService _compService;
    appservice _appservice;
    LinkService _linkService;
    TicTacToe _ticTacToe;
public:
    ConsoleUI();
    ConsoleUI(appservice p, CompService c, LinkService l);

    //Tools and misc.
    string inputHandling();
    string unicorn();
    string cORp(string name);
    void displayList();

    //Overall menus
    void searchMenu();
    void sortMenu();
    void createMenu();
    void deleteMenu();
    void linkMenu();

    //Person menus
    void searchMenuPerson();
    void sortMenuPerson();
    void createMenuPerson();
    void deleteMenuPerson();
    void runUI();

    //Computer menus
    void searchMenuComp();
    void sortMenuComp();
    void createMenuComp();
    void deleteMenuComp();
    void runUIComp();
    void displayListComp();

};

#endif // CONSOLEUI_H
