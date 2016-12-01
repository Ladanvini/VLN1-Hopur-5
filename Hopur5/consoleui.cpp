#include <iostream>
#include <algorithm>
#include <string>

#include "consoleui.h"
#include "appservice.h"

using namespace std;

ConsoleUI::ConsoleUI() {

}

ConsoleUI::ConsoleUI(Process p) {
    _process = p;
}

string ConsoleUI::inputHandling() {
    string input = " ";
    cin >> input;
    transform(input.begin(), input.end(), input.begin(), ::tolower);
    //https://notfaq.wordpress.com/2007/08/04/cc-convert-string-to-upperlower-case/
    //Link to where the code is originally displayed

    return input;
}

void ConsoleUI::searchMenu() {
    string input = "";
    bool exitMenu = false;

    do {
        cout << "Please enter one of these commands" << endl;
        cout << "Name - Search by persons name" << endl;
        cout << "Age - Search by persons age" << endl;
        cout << "Sex - Search by persons gender" << endl;
        cout << "Birth - Search by persons birth year" << endl;
        cout << "Death - Search by persons death year" << endl;
        cout << "Contribution - Search by persons contribution" << endl;
        cout << "Turing - Search those that have won Turing award" << endl;

        input = inputHandling();

        if(input == "name") {
            cout << "Your name is not here" << endl;
            input = inputHandling();
            _process.searchByName(input);
        }
        else if(input == "age") {
            cout << "too old" << endl;
            input = inputHandling();
            _process.searchByAge(input);
        }
        else if(input == "sex") {
            cout << "All the sex here" << endl;
            input = inputHandling();
            _process.searchBySex(input);
        }
        else if(input == "birth") {
            cout << "Not born yet" << endl;
            input = inputHandling();
            _process.searchByBirth(input);
        }
        else if(input == "death") {
            cout << "Yup, definetly dead" << endl;
            input = inputHandling();
            _process.searchByDeath(input);
        }
        else if(input == "contribution") {
            cout << "your contribution is Zero" << endl;
            input = inputHandling();
            _process.searchByContribution(input);
        }
        else if(input == "turing") {
            cout << "congratz, you won!" << endl;
            input = inputHandling();
            _process.searchByTuring(input);
        }
        else {
            cout << "wrong input asshole!" << endl;
        }
    }while(!exitMenu);
}

//sortMenu
void ConsoleUI::sortMenu() {
    string input = "";
    bool exitMenu = false;

    do {
        cout << "Please enter one of these commands" << endl;
        cout << "Name - Sort by persons name" << endl;
        cout << "Age - Sort by persons age" << endl;
        cout << "Sex - Sort by persons gender" << endl;
        cout << "Birth - Sort by persons birth year" << endl;
        cout << "Death - Sort by persons death year" << endl;
        cout << "Contribution - Sort by persons contribution" << endl;
        cout << "Turing - Sort those that have won Turing award" << endl;

        input = inputHandling();

        if(input == "name")
        {
            cout << "Your name is not here" << endl;
            input = inputHandling();
            _process.sortByName();
        }
        else if(input == "age")
        {
            cout << "too old" << endl;
            input = inputHandling();
            _process.sortByAge();
        }
        else if(input == "sex")
        {
            cout << "All the sex here" << endl;
            input = inputHandling();
            _process.sortBySex(input);
        }
        else if(input == "birth")
        {
            cout << "Not born yet" << endl;
            input = inputHandling();
            _process.sortByBirth();
        }
        else if(input == "death")
        {
            cout << "Yup, definetly dead" << endl;
            input = inputHandling();
            _process.sortByDeath();
        }
        else if(input == "turing")
        {
            cout << "congratz, you won!" << endl;
            input = inputHandling();
            _process.sortByTuring(input);
        }
        else
        {
            cout << "wrong input asshole!" << endl;
        }

    }while(!exitMenu);
}

void ConsoleUI::createMenu(){
    string name;
    string age;
    string sex;
    string birth;
    string death;
    string contribution;
    string turing;

    cout << "Enter Name: " << endl;
    name = inputHandling();
    cout << "Enter Age: " << endl;
    age = inputHandling();
    cout << "Enter Sex: " << endl;
    sex = inputHandling();
    cout << "Enter Birth: " << endl;
    birth = inputHandling();
    cout << "Enter Death: " << endl;
    death = inputHandling();
    cout << "Enter Contribution: " << endl;
    contribution = inputHandling();
    cout << "Enter Turing: " << endl;
    turing = inputHandling();

    char _sex = sex.at(0);
    _process.create(name, age, _sex, birth, death, contribution, turing);
}

void ConsoleUI::runUI()
{
    string input = " ";
    bool exitUI = false;
    cout << "Im running!" << endl;

    do
    {
        cout << "Please input one of these commands: " << endl;
        cout << "Add" << endl;
        cout << "Edit" << endl;
        cout << "Search" << endl;
        cout << "Delete" << endl;
        cout << "Exit" << endl;

        input = inputHandling();

        if(input == "add")
        {
            createMenu();
        }
        else if(input == "edit")
        {
            cout << "I'm here"<< endl;
            //todo
        }
        else if(input == "search")
        {
            cout << "Im in search motha facka!" << endl;
            searchMenu();
        }
        else if(input == "delete")
        {
//            cout << "I'm here to delet you"<< endl;
            cout << "Enter the person's name: \n";
            string name = inputHandling();
            cout << "Enter the person's birth year: \n";
            input = inputHandling();
            _process.deletePerson(name, input);
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
