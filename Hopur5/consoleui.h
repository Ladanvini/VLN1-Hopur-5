#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include <string>
using namespace std;
class ConsoleUI
{
private:

public:
    ConsoleUI();

    std::string inputHandling();

    std::string tolower();

    void searchMenu();

    void runUI();
};

#endif // CONSOLEUI_H
