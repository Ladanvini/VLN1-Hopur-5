#include <iostream>
#include <algorithm>
#include <string>

#include "computerui.h"

using namespace std;

ComputerUI::ComputerUI() {

}

ComputerUI::ComputerUI(CompService cs) {
    _compService = cs;
}

string ComputerUI::inputHandling() {
    string input = " ";
    getline(cin, input);
    transform(input.begin(), input.end(), input.begin(), ::tolower);

    return input;
}

void ComputerUI::runCompUI() {
    string input = " ";
    bool exitUI = false;
    string lowline = "--------------------------------------------------------------\n";
    cout << "*******************FAMOUS COMPUTERS*********************" << endl;

    do {
        cout << lowline << endl;
        cout << "Please input one of these commands: " << endl;
        cout << "Display - Displays the list of famous computers" << endl;
        cout << "Add - Adds a computer to the list" << endl;
        cout << "Search - Searches for a computer in the list" << endl;
        cout << "Sort - Displays the list sorted order from options" << endl;
        cout << "Delete - Deletes a computer from the list" << endl;
        cout << "Unicorn - A unicorn" << endl;
//NEEDS TO HAVE A BACK MENU TO THE MAIN MENU INSTEAD OF EXIT. SAME FOR PEOPLE
        cout << "Exit - End the programs run" << endl;

        input = inputHandling();

        if(input == "add") {
            cout << lowline;
            createMenu();
        }
        else if(input == "unicorn"){
            cout << lowline;
            cout << unicorn2();
            cout << lowline;
        }
        else if(input == "search") {
            cout << lowline;
            searchMenu();
        }
        else if(input == "sort") {
            cout << lowline;
            sortMenu();
        }
        else if(input == "display") {
            cout << lowline;
            displayList();
        }
        else if(input == "delete") {
            string name;
            string type;
            cout << lowline;
            cout << "Enter the computer's name: \n";
            getline(cin, name);
            cout << "Enter the computer's type: \n";
            getline(cin, type);
            cout << _compService.deleteComputers(name, type) << endl;
            cout << lowline << endl;
        }
        else if(input == "exit") {
            cout << lowline;
            cout << "Thank you, have a nice day!" << endl;
            cout << lowline;
            exitUI = true;
        }
        else {
            cout << lowline;
            cout << "Wrong input!" << endl;
            cout << lowline;
        }

    }while(!exitUI);
}
