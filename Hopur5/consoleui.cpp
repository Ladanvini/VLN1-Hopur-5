#include <iostream>
#include <algorithm>
#include <string>

#include "consoleui.h"
#include "appservice.h"

using namespace std;

ConsoleUI::ConsoleUI()
{

}

string tolower(string inputString)
{
    return std::transform(inputString.begin(), inputString.end(), inputString.begin(), ::tolower);
        //https://notfaq.wordpress.com/2007/08/04/cc-convert-string-to-upperlower-case/
        //Link to where the code is originally displayed
}

string inputHandling()
{
    string input = " ";
    cin >> input;
    tolower(input);
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

        if(name)
        {
            cout << "Your name is not here" << endl;
        }
        else if(age)
        {
            cout << "too old" << endl;
        }
        else if(sex)
        {
            cout << "All the sex here" << endl;
        }
        else if(birth)
        {
            cout << "Not born yet" << endl;
        }
        else if(death)
        {
            cout << "Yup, definetly dead" << endl;
        }
        else if(contribution)
        {
            cout << "your contribution is Zero" << endl;
        }
        else if(turing)
        {
            cout << "congratz, you won!" << endl;
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
    Database* db = new Database("/Users/alexandrawinther/Desktop/VLN1-Hopur-5/Hopur5/database.txt");
    Process* doStuff = new Process(*db);
    // DATABASE HAS TO BE IN CORRECT PLACE OR MENU NO WORK, ASSHOLES
    do
    {
        cout << "Please input one of these commands: " << endl;
        cout << "Add" << endl;
        cout << "Edit" << endl;
        cout << "Search" << endl;
        cout << "Delete" << endl;
        cout << "Exit" << endl;

        input = inputHandling();

       std::transform(input.begin(), input.end(), input.begin(), ::tolower);

        if(input == "add")
        {
            cout << "I'm add"<< endl;
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
            cout << "I'm here to delet you"<< endl;
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
