#include<string>
using namespace std;

class Person
{
private:
	string name;
	int age;
	int birth;
	int death;
	string contribution;
	int turingYear;
	bool turing;
public:
	Person();
	Person(string _name, int _age, int _birth);
	Person(string _name, int _age, int _birth, int _death);
	Person(string _name, int _age, int _birth, int _death, string _contribution);
	Person(string _name, int _age, int _birth, int _death, string _contribution, int _truringYear);
};

