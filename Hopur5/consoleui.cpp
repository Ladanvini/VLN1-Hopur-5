#include <iostream>
#include <algorithm>
#include <string>

#include "consoleui.h"
#include "appservice.h"

using namespace std;
 ConsoleUI::ConsoleUI()
 {

 }

ConsoleUI::ConsoleUI(Process p)
{
    _process = p;
}


string ConsoleUI::inputHandling()
{
    string input = " ";
    cin >> input;
    transform(input.begin(), input.end(), input.begin(), ::tolower);
    //https://notfaq.wordpress.com/2007/08/04/cc-convert-string-to-upperlower-case/
    //Link to where the code is originally displayed
    return input;
}


void ConsoleUI::searchMenu()
{
    string input = "";
    bool exitMenu = false;

    do
    {
        cout << "Please enter one of these commands" << endl;
        cout << "Name - Search by persons name" << endl;
        cout << "Age - Search by persons age" << endl;
        cout << "Sex - Search by persons gender" << endl;
        cout << "Birth - Search by persons birth year" << endl;
        cout << "Death - Search by persons death year" << endl;
        cout << "Contribution - Search by persons contribution" << endl;
        cout << "Turing - Search those that have won Turing award" << endl;

        input = inputHandling();

        if(input == "name")
        {
            cout << "Your name is not here" << endl;
            input = inputHandling();
            _process.searchByName(input);
        }
        else if(input == "age")
        {
            cout << "too old" << endl;
            input = inputHandling();
            _process.searchByAge(input);
        }
        else if(input == "sex")
        {
            cout << "All the sex here" << endl;
            input = inputHandling();
            _process.searchBySex(input);
        }
        else if(input == "birth")
        {
            cout << "Not born yet" << endl;
            input = inputHandling();
            _process.searchByBirth(input);
        }
        else if(input == "death")
        {
            cout << "Yup, definetly dead" << endl;
            input = inputHandling();
            _process.searchByDeath(input);
        }
        else if(input == "contribution")
        {
            cout << "your contribution is Zero" << endl;
            input = inputHandling();
            _process.searchByContribution(input);
        }
        else if(input == "turing")
        {
            cout << "congratz, you won!" << endl;
            input = inputHandling();
            _process.searchByTuring(input);
        }
        else
        {
            cout << "wrong input asshole!" << endl;
        }

    }while(!exitMenu);
}
//sortMenu
void ConsoleUI::sortMenu()
{
    string input = "";
    bool exitMenu = false;

    do
    {
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
        else if(input == "contribution")
        {
            cout << "your contribution is Zero" << endl;
            input = inputHandling();
            _process.sortByContribution(input);
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


void ConsoleUI::runUI()
{
    string input = " ";
    bool exitUI = false;
    cout << "Im running!" << endl;
    Database* db = new Database("database.txt");
    Process* doStuff = new Process(*db);

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
            cout << "I'm add"<< endl;
            input = inputHandling();
            _process.create(input);
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
            cout << "I'm here to delet you"<< endl;
            input = inputHandling();
            _process.deletePerson();
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
