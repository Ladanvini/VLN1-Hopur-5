#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <vector>


using namespace std;

class Person {
private:
    string _name;
    int _id;
    int _age;
    char _sex;
    int _birth;
    int _death;

    string _contribution;
    int _turingYear;
    bool _turing;
public:
    Person();
    Person(int id, string name, char sex, int birth, int death, string contribution, int truringYear);
    string showPerson();
    int getId() { return _id; }
    string getName() { return _name; }
    int getAge() { return _age; }
    char getSex() { return _sex; }
    int getBirth() { return _birth; }
    int getDeath() { return _death; }
    void setId(int id) { _id = id; }
    string getContribution() { return _contribution; }
    int getTuringYear() { return _turingYear; }
    bool getTuring() { return _turing; }
    bool isSame(Person p);
    friend bool operator==(const Person p, const Person p2);
};

#endif // PERSON_H
