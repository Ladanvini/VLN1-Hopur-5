#ifndef COMPUTERUI_H
#define COMPUTERUI_H

#include <string>

#include "compservice.h"

using namespace std;

class ComputerUI {
private:
    CompService _compService;
public:
    ComputerUI();
    ComputerUI(CompService cs);
    string inputHandling();
    void searchMenu();
    void sortMenu();
    void createMenu();
    void runCompUI();
    string unicorn();
    void displayList();

};

#endif // COMPUTERUI_H
