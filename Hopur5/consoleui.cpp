#include "consoleui.h"
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;


ConsoleUI::ConsoleUI()
{

}

void ConsoleUI::runUI()
{
    string input = " ";
    bool exitUI = false;

    do
    {
        cout << "Please input one of these commands: " << endl;
        cout << "Add" << endl;
        cout << "Edit" << endl;
        cout << "Search" << endl;
        cout << "Delete" << endl;
        cout << "Exit" << \n << endl;

        cin >> input;

        transform(input.begin(), input.end(), input.begin(), ::tolower);

        if(input == "add")
        {
            //todo
        }
        else if(input == "edit")
        {
            //todo
        }
        else if(input == "search")
        {
            //todo
        }
        else if(input == "delete")
        {
            //todo
        }
        else if(input == "exit")
        {
            cout << "Thank you, have a nice day!" << endl;
            cout << endl;
            exitUI = true;
        }
    }while(!exitUI)
}
