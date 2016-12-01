#include "appservice.h"
#include <iostream>
#include <algorithm>

using namespace std;

Process::Process() {

}

Process::Process(Database _db) {
   db = _db;
   people = _db.getList();
   // person = NULL;
}

//####################ADD NEW###################//

string Process::create(string name, string age, char sex, string birth, string death, string contribution, string turingYear) {
    Person* p = new Person(name, age, sex, birth, death, contribution, turingYear);
    bool flag = false;
    if(
            (age.size() > 3 || age.size() < 1 || age == "0")
            || (sex != 'm' && sex != 'f')
            || (birth.size() < 4 || birth.size() > 4)
            || (death.size() > 4 ||!(death.size() == 4 || death.find("0") != std::string::npos))
            )
        return "unacceptable value in one of the fields\n";

    if(db.exists(*p)) {
        flag = true;
    }
    if(flag) {
       return "Person already exists\n";
    }
    people.push_back(*p);

    db.update(people);
    db.writeToDB(*p);
    return "Added successfully\n";
}

//####################SEARCH###################//

vector<Person> Process::searchByName(string name) {
    transform(name.begin(), name.end(), name.begin(), ::tolower);
    string _name = "";

    vector<Person> result;

    for(size_t i = 0; i < people.size(); i++) {

        _name = people.at(i).getName();
        transform(_name.begin(), _name.end(), _name.begin(), ::tolower);
        if(_name.find(name) != std::string::npos) {
            result.push_back(people.at(i));
        }
    }

    return result;
}
vector<Person> Process::searchByAge(string age) {
    vector<Person> result;
    string _age;
    for(size_t i = 0; i < people.size(); i++) {
        _age = (people.at(i).getAge());
        transform(_age.begin(), _age.end(), _age.begin(), ::tolower);

        if(_age.find(age) != std::string::npos) {
            result.push_back(people.at(i));
        }
    }

    return result;
}
vector<Person> Process::searchBySex(string _sex) {
    vector<Person> result;
    char sex = _sex.at(0);
    for(size_t i = 0; i < people.size(); i++) {
        if(people.at(i).getSex() == (sex)) {
            result.push_back(people.at(i));
        }
    }

    return result;
}
vector<Person> Process::searchByDeath(string death) {
    vector<Person> result;
    string _death;
    for(size_t i = 0; i < people.size(); i++) {
        _death = people.at(i).getDeath();
        transform(_death.begin(), _death.end(), _death.begin(), ::tolower);
        if(_death.find(death) != std::string::npos) {
            result.push_back(people.at(i));
        }
    }

    return result;
}
vector<Person> Process::searchByBirth(string birth) {
    vector<Person> result;
    string _birth;
    for(size_t i = 0; i < people.size(); i++) {
        _birth = people.at(i).getBirth();
        transform(_birth.begin(), _birth.end(), _birth.begin(), ::tolower);
        if(_birth.find(birth) != std::string::npos) {
            result.push_back(people.at(i));
        }
    }

    return result;
}
vector<Person> Process::searchByContribution(string contribution) {
    vector<Person> result;
    string _cont;
    for(size_t i = 0; i < people.size(); i++) {
        _cont = people.at(i).getContribution();
        transform(_cont.begin(), _cont.end(), _cont.begin(), ::tolower);
        if(_cont.find(contribution) != std::string::npos) {
            result.push_back(people.at(i));
        }
    }

    return result;
}
vector<Person> Process::searchByTuring(string _flag) {
    vector<Person> result;
    bool flag;
    if(_flag.find("yes") != std::string::npos) {
        flag = true;
    }
    else {
        flag = false;
    }
    for(size_t i = 0; i < people.size(); i++) {
        if((people.at(i).getTuring()) == flag) {
            result.push_back(people.at(i));
        }
    }

    return result;
}

//####################Sort#####################//

vector<Person> Process::sortByName() {
    vector<string> names;
    vector<Person> sorted;
    for(unsigned int i = 0; i < people.size(); i++)
        names.push_back(people.at(i).getName());

    std::sort(names.begin(), names.end());

    for(unsigned int i = 0; i < names.size(); i++) {
        for(unsigned int j = 0; j < people.size(); j++)
            if(names.at(i) == people.at(j).getName())
                sorted.push_back(people.at(j));
    }

    return sorted;
}
vector<Person> Process::sortByAge() {
    vector<string> ages;
    vector<Person> sorted;
    for(unsigned int i = 0; i < people.size(); i++)
    {
        ages.push_back(people.at(i).getAge());
    }
    std::sort(ages.begin(), ages.end());

    for(unsigned int i = 0; i < ages.size(); i++) {
        for(unsigned int j = 0; j < people.size(); j++)
            if(ages.at(i) == people.at(j).getAge())
                sorted.push_back(people.at(j));
    }

    return sorted;
}
vector<Person> Process::sortBySex(string _sex) {
    vector<Person> result;
    char sex = _sex.at(0);
    for(size_t i = 0; i < people.size(); i++) {
        if(people.at(i).getSex() == (sex)) {
            result.push_back(people.at(i));
        }
    }

    for(size_t i = 0; i < people.size(); i++) {
        if(people.at(i).getSex() != (sex)) {
            result.push_back(people.at(i));
        }
    }

    return result;
}
vector<Person> Process::sortByBirth() {
    vector<string> birth;
    vector<Person> sorted;
    for(unsigned int i = 0; i < people.size(); i++)
        birth.push_back(people.at(i).getBirth());

    std::sort(birth.begin(), birth.end());

    for(unsigned int i = 0; i < birth.size(); i++) {
        for(unsigned int j = 0; j < people.size(); j++) {
            if(birth.at(i) == people.at(j).getBirth())
                sorted.push_back(people.at(j));
        }
    }

    return sorted;
}
vector<Person> Process::sortByDeath() {
    vector<string> death;
    vector<Person> sorted;
    for(unsigned int i = 0; i < people.size(); i++)
        death.push_back(people.at(i).getDeath());

    std::sort(death.begin(), death.end());

    for(unsigned int i = 0; i < death.size(); i++) {
        for(unsigned int j = 0; j < people.size(); j++) {
            if(death.at(i) == people.at(j).getDeath())
                sorted.push_back(people.at(j));
        }
    }

    return sorted;
}
vector<Person> Process::sortByTuring (string _flag) {
    vector<Person> result;

    bool flag;
    if(_flag.find("yes") != std::string::npos) {
        flag = true;
    }
    else {
        flag = false;
    }
    for(size_t i = 0; i < people.size(); i++) {
        if((people.at(i).getTuring()) == flag) {
            result.push_back(people.at(i));
        }
    }
    for(size_t i = 0; i < people.size(); i++) {
        if((people.at(i).getTuring()) != flag) {
            result.push_back(people.at(i));
        }
    }

    return result;
}

//####################Delete####################//

string Process::deletePerson(string _name, string birth) {
    bool flag = false;
    string p_name;
    Person result;

    for(unsigned int i=0; i<people.size(); i++) {
        p_name = people.at(i).getName();
        //transform(_name.begin(), _name.end(), _name.begin(), ::tolower);

        if(p_name.find(_name) != std::string::npos && people.at(i).getBirth().find(birth) != std::string::npos) {
            result = people.at(i);
            people.erase(people.begin() + i);
            flag = true;
        }
    }

    if(flag) {
        db.update(people);
        db.reWriteDb();
        return result.showPerson() +
                "Erased successfully\n";
    }

    return "Person: \n" + result.getName() + "\n not found\n";
}

//####################Showing#################//

string Process::showPeople(vector<Person> results) {

    string temp = "";

    for(unsigned int i = 0; i < results.size(); i++) {
        temp = temp + "--------------------------------------------------------------\n";
        temp = temp + results.at(i).showPerson();
    }
    if(results.size() == 0) {
        temp = "#########################################################################\n";
        temp = temp + "No Results Found!\n";
    }
    temp =  temp + "--------------------------------------------------------------\n";
    return temp;
}
//####################Checking if string is a number#############################//
bool Process::checkIfDigit(char c){
    return !std::isdigit(c);

    //http://stackoverflow.com/questions/4622516/sorting-stdstrings-with-numbers-in-them
}
//###################Compering numeric strings##################//
bool Process::numericStringCompare(const std::string& s1, const std::string& s2){
    std::string::const_iterator it1 = s1.begin(), it2 = s2.begin();

    if (std::isdigit(s1[0]) && std::isdigit(s2[0])) {
        int n1, n2;
        std::stringstream ss(s1);
        ss >> n1;
        ss.clear();
        ss.str(s2);
        ss >> n2;

        if (n1 < n2)
            return n1 < n2;
        else if(n2 < n1)
            return n2 < n1;

//        it1 = std::find_if(s1.begin(), s1.end(), checkIfDigit);
 //       it2 = std::find_if(s2.begin(), s2.end(), checkIfDigit);
    }

    return std::lexicographical_compare(it1, s1.end(), it2, s2.end());

    //http://stackoverflow.com/questions/4622516/sorting-stdstrings-with-numbers-in-them
}



//####################Edit####################//
