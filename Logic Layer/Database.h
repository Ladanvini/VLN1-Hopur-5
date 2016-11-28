#include "Person.h"
#include <vector>
class Database{
private:
	Person person;
	vector<Person> people;
public:
	Person getPerson();
	vector<Person> getList();	
};
