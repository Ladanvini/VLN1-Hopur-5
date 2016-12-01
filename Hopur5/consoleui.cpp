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

string ConsoleUI::inputHandling() {
    string input = " ";
    getline(cin, input);
    transform(input.begin(), input.end(), input.begin(), ::tolower);
    //https://notfaq.wordpress.com/2007/08/04/cc-convert-string-to-upperlower-case/
    //Link to where the code is originally displayed

    return input;
}

void ConsoleUI::searchMenu() {
    string input = "";
    bool exitMenu = false;

    string lowline = "--------------------------------------------------------------\n";

    do {
        cout << "Please enter one of these commands" << endl;
        cout << "Name - Search by persons name" << endl;
        cout << "Age - Search by persons age of contribution" << endl;
        cout << "Sex - Search by persons gender" << endl;
        cout << "Birth - Search by persons birth year" << endl;
        cout << "Death - Search by persons death year" << endl;
        cout << "Contribution - Search by persons contribution" << endl;
        cout << "Turing - Search those that have won Turing award" << endl;
        cout << "Back - Go back to the main menu" << endl;

        cout << line << endl;

        input = inputHandling();

        if(input == "name") {
            //cout << string(100, '\n');
            cout << lowline;
            cout << "Enter the name here: " << endl;
            input = inputHandling();
            cout << _process.showPeople(_process.searchByName(input));
        }
        else if(input == "unicorn"){
            cout << unicorn();
        }
        else if(input == "age") {
            //cout << string(100, '\n');
            cout << lowline;
            cout << "Please enter the age you want" << endl;
            input = inputHandling();
            cout << _process.showPeople(_process.searchByAge(input));
        }
        else if(input == "sex") {
            //cout << string(100, '\n');
            cout << lowline;
            cout << "Please enter the gender" << endl;
            input = inputHandling();
            cout << _process.showPeople(_process.searchBySex(input));
        }
        else if(input == "birth") {
            //cout << string(100, '\n');
            cout << lowline;
            cout << "Enter the birth year please" << endl;
            input = inputHandling();
            cout << _process.showPeople(_process.searchByBirth(input));
        }
        else if(input == "death") {
            //cout << string(100, '\n');
            cout << lowline;
            cout << "Enter the death year (0 if still alive)" << endl;
            input = inputHandling();
            cout << _process.showPeople(_process.searchByDeath(input));
        }
        else if(input == "contribution") {
            //cout << string(100, '\n');
            cout << lowline;
            cout << "Enter the contribution you're looking for" << endl;
            input = inputHandling();
            cout << _process.showPeople(_process.searchByContribution(input));
        }
        else if(input == "turing") {
            //cout << string(100, '\n');
            cout << lowline;
            cout << "If you're looking for people who have won a turing award, enter yes, otherwise enter no" << endl;
            input = inputHandling();
            cout << _process.showPeople(_process.searchByTuring(input));
        }
        else if(input == "back"){
            //cout << string(100, '\n');
            cout << lowline;
            cout << "Thank you, taking you back to the main menu" << endl;
            exitMenu = true;
        }
        else {
            cout << "Wrong Input! Please try again." << endl;
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
//        cout << "Age - Sort by persons age" << endl;
        cout << "Sex - Sort by persons gender" << endl;
        cout << "Birth - Sort by persons birth year" << endl;
        cout << "Death - Sort by persons death year" << endl;
        cout << "Turing - Sort those that have won Turing award" << endl;
        cout << "Back - Back to main menu" << endl;
        input = inputHandling();

        if(input == "name") {
            cout << lowline;
            cout << "The list sorted alphabetically: " << endl;
            cout << _process.showPeople(_process.sortByName());
        }
        else if(input == "age") {
            cout << lowline;
            cout << "The list sorted by age of contribution: " << endl;
            cout << _process.showPeople(_process.sortByAge());
        }
        else if(input == "sex") {
            cout << lowline;
            cout << "Enter the gender you want the list to be sorted by" << endl;
            input = inputHandling();
            cout << _process.showPeople(_process.sortBySex(input));
        }
        else if(input == "birth") {
            cout << lowline;
            cout << "Sorted from eldest to youngest" << endl;
            cout << _process.showPeople(_process.sortByBirth());
        }
        else if(input == "death") {
            cout << lowline;
            cout << "Sorted by year died" << endl;
            input = inputHandling();
            cout << _process.showPeople(_process.sortByDeath());
        }
        else if(input == "turing") {
            cout << lowline;
            cout << "Sort by those who won turing award, input yes" << endl;
            input = inputHandling();
            cout << _process.showPeople(_process.sortByTuring(input));
        }
        else if(input == "back"){
            cout << lowline;
            cout << "Thank you, taking you back to the main menu" << endl;
            exitMenu = true;
            cout << lowline;
        }
        else {
            cout << "wrong input! Try again" << endl;
        }

    }while(!exitMenu);
}

void ConsoleUI::createMenu() {
    string name;
    string age;
    string sex;
    string birth;
    string death;
    string contribution;
    string turing;

    cout << "Enter Name: " << endl;
    name = inputHandling();
    cout << "Enter The Age Of Contribution( 0 if unknown): " << endl;
    age = inputHandling();
    cout << "Enter Sex (m/f): " << endl;
    sex = inputHandling();
    cout << "Enter Birth Year: " << endl;
    birth = inputHandling();
    cout << "Enter Death Year (0 if still alive): " << endl;
    death = inputHandling();
    cout << "Enter Contribution: " << endl;
    contribution = inputHandling();
    cout << "Enter Turing Year (0 if unknown or not applicable): " << endl;
    turing = inputHandling();

    char _sex = sex.at(0);
    cout << _process.create(name, age, _sex, birth, death, contribution, turing);
}

void ConsoleUI::runUI() {
    string input = " ";
    bool exitUI = false;
    cout << "Im running!" << endl;
    string lowline = "--------------------------------------------------------------\n";


    do {
        cout << "Please input one of these commands: " << endl;
        cout << "Add" << endl;
        cout << "Search" << endl;
        cout << "Sort" << endl;
        cout << "Delete" << endl;
        cout << "Unicorn" << endl;
        cout << "Exit" << endl;

        input = inputHandling();

        if(input == "add") {
            //cout << string(100, '\n');
            cout << lowline;
            createMenu();
        }
        else if(input == "unicorn"){
            cout << lowline;
            cout << unicorn();
        }
        else if(input == "search") {
            //cout << string(100, '\n');
            cout << lowline;
            searchMenu();
        }
        else if(input == "sort") {
            //cout << string(100, '\n');
            cout << lowline;
            sortMenu();
        }

        else if(input == "delete") {
            //cout << string(100, '\n');
            cout << lowline;
            cout << "Enter the person's name: \n";
            string name = inputHandling();
            cout << "Enter the person's birth year: \n";
            input = inputHandling();
            cout << _process.deletePerson(name, input) << endl;
            cout << line << endl;
        }
        else if(input == "exit") {
            //cout << string(100, '\n');
            cout << lowline;
            cout << "Thank you, have a nice day!" << endl;
            cout << lowline;
            exitUI = true;
        }
        else {
            cout << "Wrong input!" << endl;
        }

    }while(!exitUI);
}
string ConsoleUI::unicorn(){
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
