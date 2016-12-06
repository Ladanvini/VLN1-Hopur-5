#include <iostream>
#include <algorithm>
#include <string>

#include "consoleui.h"

using namespace std;

ConsoleUI::ConsoleUI() {

}

ConsoleUI::ConsoleUI(Process p) {
    _process = p;
}

//Takes input and puts them in lowercasing
string ConsoleUI::inputHandling() {
    string input = " ";
    getline(cin, input);
    transform(input.begin(), input.end(), input.begin(), ::tolower);
    //https://notfaq.wordpress.com/2007/08/04/cc-convert-string-to-upperlower-case/
    //Link to where the code is originally displayed

    return input;
}

//search
void ConsoleUI::searchMenu() {
    string input = "";
    bool exitMenu = false;

    string lowline = "--------------------------------------------------------------\n";

    do {
        cout << "Please enter one of these commands" << endl;
        cout << "Name - Search by persons name (Using correct capitalization of letters)" << endl;
        cout << "Age - Search by persons age of contribution" << endl;
        cout << "Sex - Search by persons gender" << endl;
        cout << "Birth - Search by persons birth year" << endl;
        cout << "Death - Search by persons death year" << endl;
        cout << "Contribution - Search by persons contribution" << endl;
        cout << "Turing - Search those that have won Turing award" << endl;
        cout << "Back - Go back to the main menu" << endl;

        cout << lowline << endl;

        input = inputHandling();

        if(input == "name") {
            cout << lowline;
            cout << "Enter the name here: " << endl;
            input = inputHandling();
            cout << lowline;
            cout << _process.showPeople(_process.searchByName(input));
        }
        else if(input == "unicorn"){
            cout << lowline;
            cout << unicorn();
            cout << lowline;
        }
        else if(input == "age") {
            cout << lowline;
            cout << "Please enter the age you want" << endl;
            input = inputHandling();
            cout << lowline;
            cout << _process.showPeople(_process.searchByAge(input));
        }
        else if(input == "sex") {
            cout << lowline;
            cout << "Please enter the gender" << endl;
            input = inputHandling();
            cout << lowline;
            cout << _process.showPeople(_process.searchBySex(input));
        }
        else if(input == "birth") {
            cout << lowline;
            cout << "Enter the birth year please" << endl;
            input = inputHandling();
            cout << lowline;
            cout << _process.showPeople(_process.searchByBirth(input));
        }
        else if(input == "death") {
            cout << lowline;
            cout << "Enter the death year (0 if still alive)" << endl;
            input = inputHandling();
            cout << lowline;
            cout << _process.showPeople(_process.searchByDeath(input));
        }
        else if(input == "contribution") {
            cout << lowline;
            cout << "Enter the contribution you're looking for" << endl;
            input = inputHandling();
            cout << lowline;
            cout << _process.showPeople(_process.searchByContribution(input));
        }
        else if(input == "turing") {
            cout << lowline;
            cout << "If you're looking for people who have won a turing award, enter yes, otherwise enter no" << endl;
            input = inputHandling();
            cout << lowline;
            cout << _process.showPeople(_process.searchByTuring(input));
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

//sortMenu
void ConsoleUI::sortMenu() {
    string lowline = "--------------------------------------------------------------\n";
    string input = "";
    bool exitMenu = false;

    do {
        cout << "Please enter one of these commands" << endl;
        cout << "Name - Sort by persons name" << endl;
        cout << "Sex - Sort by persons gender" << endl;
        cout << "Birth - Sort by persons birth year" << endl;
        cout << "Death - Sort by persons death year" << endl;
        cout << "Turing - Sort those that have won Turing award" << endl;
        cout << "Back - Back to main menu" << endl;

        cout << lowline;

        input = inputHandling();

        if(input == "name") {
            cout << lowline;
            cout << "The list sorted alphabetically: " << endl;
            cout << lowline;
            cout << _process.showPeople(_process.sortByName());
        }
        else if(input == "age") {
            cout << lowline;
            cout << "The list sorted by age of contribution: " << endl;
            cout << lowline;
            cout << _process.showPeople(_process.sortByAge());
        }
        else if(input == "sex") {
            cout << lowline;
            cout << "Enter the gender you want the list to be sorted by" << endl;
            input = inputHandling();
            cout << lowline;
            cout << _process.showPeople(_process.sortBySex(input));
        }
        else if(input == "birth") {
            cout << lowline;
            cout << "Sorted from eldest to youngest" << endl;
            cout << lowline;
            cout << _process.showPeople(_process.sortByBirth());
        }
        else if(input == "death") {
            cout << lowline;
            cout << "Sorted by year died" << endl;
            input = inputHandling();
            cout << lowline;
            cout << _process.showPeople(_process.sortByDeath());
        }
        else if(input == "turing") {
            cout << lowline;
            cout << "Sort by those who won turing award, input yes" << endl;
            input = inputHandling();
            cout << lowline;
            cout << _process.showPeople(_process.sortByTuring(input));
        }
        else if(input == "back"){
            cout << lowline;
            cout << "Thank you, taking you back to the main menu" << endl;
            cout << lowline;
            exitMenu = true;
        }
        else {
            cout << lowline;
            cout << "wrong input! Try again" << endl;
            cout << lowline;
        }

    }while(!exitMenu);
}

//create option
void ConsoleUI::createMenu() {
    string name;
    string age;
    string sex;
    string birth;
    string death;
    string contribution;
    string turing;
    int id;

    cout << "Enter Name (Using correct capitalization of letters): " << endl;
    getline(cin, name);
    cout << "Enter The Age Of Contribution( 0 if unknown): " << endl;
    getline(cin, age);
    cout << "Enter Sex (m/f): " << endl;
    getline(cin, sex);
    cout << "Enter Birth Year: " << endl;
    getline(cin, birth);
    cout << "Enter Death Year (0 if still alive): " << endl;
    getline(cin, death);
    cout << "Enter Contribution: " << endl;
    getline(cin, contribution);
    cout << "Enter Turing Year (0 if unknown or not applicable): " << endl;
    getline(cin, turing);

    char _sex = sex.at(0);
    cout << _process.create(id, name, age, _sex, birth, death, contribution, turing);
}

//Main Menu
void ConsoleUI::runUI() {
    string input = " ";
    bool exitUI = false;
    string lowline = "--------------------------------------------------------------\n";
    cout << "**************FAMOUS COMPUTER SCIENTISTS****************" << endl;

    do {
        cout << lowline << endl;
        cout << "Please input one of these commands: " << endl;
        cout << "Display - Displays the list of famous computer scientists" << endl;
        cout << "Add - Adds a person to the list" << endl;
        cout << "Search - Searches the list" << endl;
        cout << "Sort - Displays the list sorted order from options" << endl;
        cout << "Delete - Deletes a person from the list" << endl;
        cout << "Unicorn - A unicorn" << endl;
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
            cout << lowline;
            cout << "Enter the person's name: \n";
            getline(cin, name);
            cout << "Enter the person's birth year: \n";
            input = inputHandling();
            cout << _process.deletePerson(name, input) << endl;
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

//Fun Unicorn for the users
string ConsoleUI::unicorn() {
    string uni = "";
    uni = uni + "                   ." + '\n' +
"                  /|" + '\n'+
"                 /_|" + '\n'+
"             (0)/__|__" + '\n'+
"               |\/ (.) \\  " + '\n'     +
"               | \/ \/ \/:> " + '\n'+
"               |\/ \/ \/_/  " + '\n'+
"              /\/ \/ | " + '\n'+
" ____________/ \/ \/ | " + '\n'+
"/ \/ \/ \/ \/ \/ \/ \/ \/ \/| " + '\n'+
"| \/ \/ \/ \/ \/ \/ \/ \/ \/| " + '\n'+
"|\/ \/_\/_\/_\/_\/_\/_\/ \/ | " + '\n'+
"|_0|            |_0| " + '\n';

    return uni;
}

//Display
void ConsoleUI::displayList() {
    cout << _process.showPeople(_process.getList());
}

