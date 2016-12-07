#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include "appservice.h"
#include "compservice.h"

#include <string>

using namespace std;

class ConsoleUI {
private:
    Process _process;
    CompService _compService;
public:
    ConsoleUI();
    ConsoleUI(Process p);
    string inputHandling();
    //string tolower();
    void searchMenu();
    void sortMenu();
    void createMenu();
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
