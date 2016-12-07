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

//search
void ComputerUI::searchMenu() {
    string input = "";
    bool exitMenu = false;

    string lowline = "--------------------------------------------------------------\n";

    do {
        cout << "Please enter one of these commands" << endl;
        cout << "Name - Search by computer's name (Using correct capitalization of letters)" << endl;
        cout << "ID - Search by computer's ID" << endl;
        cout << "Type - Search by computer's type" << endl;
        cout << "Built - Search by if computer has been built and then when" << endl;
        cout << "Back - Go back to the main menu" << endl;

        cout << lowline << endl;

        input = inputHandling();

        if(input == "name") {
            cout << lowline;
            cout << "Enter the name here: " << endl;
            input = inputHandling();
            cout << lowline;
            cout << _compService.showComputers(_compService.searchByName(input));
        }
        else if(input == "unicorn"){
            cout << lowline;
            cout << unicorn();
            cout << lowline;
        }
        else if(input == "id") {
            cout << lowline;
            cout << "Please enter the ID you want" << endl;
            input = inputHandling();
            cout << lowline;
            cout << _compService.showComputers(_compService.searchById(input));
        }
        else if(input == "built") {
            cout << lowline;
            cout << "Please enter yes or no if built or not" << endl;
            input = inputHandling();
            cout << lowline;
            cout << _compService.showComputers(_compService.searchByBuilt(input));
        }
        else if(input == "type") {
            cout << lowline;
            cout << "Enter the type please" << endl;
            input = inputHandling();
            cout << lowline;
            cout << _compService.showComputers(_compService.searchByType(input));
        }
        else if(input == "back") {
            cout << lowline;
            cout << "Thank you, taking you back to the main menu" << endl;
            cout << lowline;
            exitMenu = true;
        }
        else {
            cout << lowline;
            cout << "Wrong Input! Please try again." << endl;
            cout << lowline;
        }
    }while(!exitMenu);
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
            cout << unicorn();
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
