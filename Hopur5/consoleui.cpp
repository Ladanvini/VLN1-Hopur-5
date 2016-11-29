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

    Database* db = new Database("/home/ladanvini/Documents/VLN1/VLN1-Hopur-5/Hopur5/database.txt");
    Process* doStuff = new Process(*db);

    do
    {
        cout << "Please input one of these commands: " << endl;
        cout << "Add" << endl;
        cout << "Edit" << endl;
        cout << "Search" << endl;
        cout << "Delete" << endl;
        cout << "Exit" << endl;

        cin >> input;

        transform(input.begin(), input.end(), input.begin(), ::tolower);

        if(input == "add")
        {
            cout << "I'm here"<< endl;
            //todo
        }
        else if(input == "edit")
        {
            cout << "I'm here"<< endl;
            //todo
        }
        else if(input == "search")
        {
            cout << "Im in search motha facka!" << endl;
            //todo
        }
        else if(input == "delete")
        {
            cout << "I'm here"<< endl;
            //todo
        }
        else if(input == "exit")
        {
            cout << "Thank you, have a nice day!" << endl;
            cout << endl;
            exitUI = true;
        }
        else
        {
            cout << "Wrong input Moron!!!" << endl;
        }
    }while(!exitUI);
}
