#ifndef CONSOLEUI_H
#define CONSOLEUI_H
#include "appservice.h"
#include <string>
using namespace std;
class ConsoleUI
{
private:

    Process _fuck;

public:
    ConsoleUI();
    ConsoleUI(Process p);

    string inputHandling();

    //string tolower();

    void searchMenu();

    void runUI();
};

#endif // CONSOLEUI_H
