#include "appservice.h"
#include <iostream>
#include <algorithm>
using namespace std;

Process::Process()
{

}
Process::Process(Database _db){
   db = _db;
   people = _db.getList();
   // person = NULL;
}
//####################ADD NEW###################//
string Process::create(string name, string age, char sex, string birth, string death, string contribution, string turingYear)
{
    Person* p = new Person(name, age, sex, birth, death, contribution, turingYear);
    bool flag = false;
    if(
            (age.size() > 3 || age.size()<1 || age == "0")
            || (sex != 'm' && sex != 'f')
            || (birth.size() < 4 || birth.size()>4)
            || (death.size()>4 ||!(death.size()==4 || death.find("0") != std::string::npos))
            )
        return "unacceptable value in one of the fields\n";

    if(db.exists(*p)){
        flag = true;
    }
    if(flag){
       return "Person already exists\n";
    }
    people.push_back(*p);

    db.update(people);
    db.writeToDB(*p);
    return "Added successfully\n";
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
vector<Person> Process::searchBySex(string _sex)
{
    vector<Person> result;
    char sex = _sex.at(0);
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
vector<Person> Process::searchByTuring(string _flag)
{
    vector<Person> result;
    bool flag;
    if(_flag.find("yes") != std::string::npos)
    {
        flag = true;
    }
    else
    {
        flag = false;
    }
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

    return sorted;


}
vector<Person> Process::sortByAge(){
    vector<string> ages;
    vector<Person> sorted;
    for(int i=0; i<people.size(); i++)
        ages.push_back(people.at(i).getAge());

    std::sort(ages.begin(), ages.end());

    for(int i=0; i<ages.size(); i++){
        for(int j=0; j<people.size(); j++)
            if(ages.at(i) == people.at(j).getAge())
                sorted.push_back(people.at(j));
    }

    return sorted;
}
vector<Person> Process::sortBySex(char sex){
    vector<Person> result;

    for(size_t i = 0; i < people.size(); i++)
    {
        if(people.at(i).getSex() == (sex))
        {
            result.push_back(people.at(i));
        }
    }

    for(size_t i = 0; i < people.size(); i++)
    {
        if(people.at(i).getSex() != (sex))
        {
            result.push_back(people.at(i));
        }
    }

    return result;
}
vector<Person> Process::sortByBirth(){
    vector<string> birth;
    vector<Person> sorted;
    for(int i=0; i<people.size(); i++)
        birth.push_back(people.at(i).getBirth());

    std::sort(birth.begin(), birth.end());

    for(int i=0; i<birth.size(); i++){
        for(int j=0; j<people.size(); j++)
            if(birth.at(i) == people.at(j).getBirth())
                sorted.push_back(people.at(j));
    }

    return sorted;
}
vector<Person> Process::sortByDeath(){
    vector<string> death;
    vector<Person> sorted;
    for(int i=0; i<people.size(); i++)
        death.push_back(people.at(i).getDeath());

    std::sort(death.begin(), death.end());

    for(int i=0; i<death.size(); i++){
        for(int j=0; j<people.size(); j++)
            if(death.at(i) == people.at(j).getDeath())
                sorted.push_back(people.at(j));
    }

    return sorted;
}
vector<Person> Process::sortByTuring (bool flag){
    vector<Person> result;

    for(size_t i = 0; i < people.size(); i++)
    {
        if((people.at(i).getTuring()) == flag)
        {
            result.push_back(people.at(i));
        }
    }
    for(size_t i = 0; i < people.size(); i++)
    {
        if((people.at(i).getTuring()) != flag)
        {
            result.push_back(people.at(i));
        }
    }

    return result;
}


//####################Delete####################//
string Process::deletePerson(Person p){
    bool flag = false;
    for(int i=0; i<people.size(); i++)
    {
        if(people.at(i) == p){

            people.erase(people.begin() + i);
            flag = true;
        }
    }

    db.update(people);
    db.reWriteDb();
    if(flag)
        return "Erased successfully";
    return "Person not found";
}

//####################Edit####################//
