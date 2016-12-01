#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include "appservice.h"
#include <string>

using namespace std;

class ConsoleUI {
private:
    Process _process;
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
};

#endif // CONSOLEUI_H
