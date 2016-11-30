#include "process.h"
#include <iostream>
#include <algorithm>
using namespace std;

Process::Process(Database _db){
   db = _db;
   people = _db.getList();
   // person = NULL;
}
void Process::create(string name, string age, char sex, string birth, string death, string contribution, string turingYear)
{
    Person* p = new Person(name, age, sex, birth, death, contribution, turingYear);
    people.push_back(*p);

    db.update(people);
}
//####################SEARCH###################//
vector<Person> Process::searchByName(string name)
{
    vector<Person> result;

    for(size_t i = 0; i < people.size(); i++)
    {
        if((people.at(i).getName()).find(name) != std::string::npos)
        {

            result.push_back(people.at(i));
        }
    }

    return result;
}
vector<Person> Process::searchByAge(string age)
{
    vector<Person> result;

    for(size_t i = 0; i < people.size(); i++)
    {
        if((people.at(i).getAge()).find(age) != std::string::npos)
        {
            result.push_back(people.at(i));
        }
    }

    return result;
}
vector<Person> Process::searchBySex(char sex)
{
    vector<Person> result;

    for(size_t i = 0; i < people.size(); i++)
    {
        if(people.at(i).getSex() == (sex))
        {
            result.push_back(people.at(i));
        }
    }

    return result;
}
vector<Person> Process::searchByDeath(string death)
{
    vector<Person> result;

    for(size_t i = 0; i < people.size(); i++)
    {
        if((people.at(i).getDeath()).find(death) != std::string::npos)
        {
            result.push_back(people.at(i));
        }
    }

    return result;
}
vector<Person> Process::searchByBirth(string birth)
{
    vector<Person> result;

    for(size_t i = 0; i < people.size(); i++)
    {
        if((people.at(i).getBirth()).find(birth) != std::string::npos)
        {
            result.push_back(people.at(i));
        }
    }

    return result;
}
vector<Person> Process::searchByContribution(string contribution)
{
    vector<Person> result;

    for(size_t i = 0; i < people.size(); i++)
    {
        if((people.at(i).getContribution()).find(contribution) != std::string::npos)
        {
            result.push_back(people.at(i));
        }
    }

    return result;
}
vector<Person> Process::searchByTuring(bool flag)
{
    vector<Person> result;

    for(size_t i = 0; i < people.size(); i++)
    {
        if((people.at(i).getTuring()) == flag)
        {
            result.push_back(people.at(i));
        }
    }

    return result;
}

//####################Sort#####################//

vector<Person> Process::sortByName(){
    vector<string> names;
    vector<Person> sorted;
    for(int i=0; i<people.size(); i++)
        names.push_back(people.at(i).getName());

    std::sort(names.begin(), names.end());

    for(int i=0; i<names.size(); i++){
        for(int j=0; j<people.size(); j++)
            if(names.at(i) == people.at(j).getName())
                sorted.push_back(people.at(j));
    }


    cout << endl;
    return sorted;


}
vector<Person> sortByAge(string age){}
vector<Person> sortBySex(char sex){}
vector<Person> sortByBirth(string birth){}
vector<Person> sortByDeath(string death){}
vector<Person> sortByContribution(string contribution){}
vector<Person> sortByTuring(bool flag){}


//####################Edit####################//

