#ifndef COMPS_H
#define COMPS_H

/*Name
* Year Built
* Type of computer (Mechanical, Electronic, (ie those using transistors), etc.)
* Was built or not?
*/
#include "database.h"
#include <string>
using namespace std;

class Comps{
private:
    string _name;
    string _type;
    bool _built;
public:
    Comps ();
    Comps(string name, string type, bool built);

	string getName();
	string getType();
	bool getBuilt();
	void setName(string name);
	void setType(string type);
	void setBuilt(bool built);
    string showComputer();
};


#endif // COMPS_H
