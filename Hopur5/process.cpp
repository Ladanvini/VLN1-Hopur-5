#include "process.h"


Process::Process(Database _db){
   db = _db;
   people = _db.getList();
   // person = NULL;
}
void Process::create(string name, string age, string sex, string birth, string death, string contribution, string turingYear)
{
    Person p = new Person(name, age, sex, birth, death, contribution, turingYear);
    people.push_back(p);

    db.update(people);
}
vector<Person> Process::searchByName(string name)
{
    vector<Person> result;

    for(size_t i = 0; i < people.size(); i++)
    {
        if(people.at(i).getName() == name)
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
        if(people.at(i).getAge() == age)
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
        if(people.at(i).geSex() == sex)
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
        if(people.at(i).getBirth() == birth)
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
        if(people.at(i).getDeath() == death)
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
        if(people.at(i).getBirth() == birth)
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
        if(people.at(i).getContribution() == contribution)
        {
            result.push_back(people.at(i));
        }
    }

    return result;
}
vector<Person> Process::searchByTuring(string turing)
{
    vector<Person> result;

    for(size_t i = 0; i < people.size(); i++)
    {
        if(people.at(i).getTuring() == turing)
        {
            result.push_back(people.at(i));
        }
    }

    return result;
}

// Sort
// Edit

