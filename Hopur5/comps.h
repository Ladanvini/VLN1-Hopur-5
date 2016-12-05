#ifndef COMPS_H
#define COMPS_H

/*Name
* Year Built
* Type of computer (Mechanical, Electronic, (ie those using transistors), etc.)
* Was built or not?
*/

#include <string>
using namespace std;

class Comps{
private:
    string _name;
    string _type;
    bool _built;
public:
	string getName();
	string getType();
	bool getBuilt();
	void setName(string name);
	void setType(string type);
	void setBuilt(bool built);
};


#endif // COMPS_H
