#ifndef COMPS_H
#define COMPS_H

/*Name
* Year Built
* Type of computer (Mechanical, Electronic, (ie those using transistors), etc.)
* Was built or not?
*/

#include <string>
using namespace std;

class Comps {
private:
    string _name;
    string _type;
    int _yearBuilt;
    bool _built;
    int _id;
public:
    Comps ();
    Comps(int id, string name, string type, int yearBuilt, bool built);

    //Getters
	string getName();
	string getType();
	bool getBuilt();
    int getYearBuilt();
    int getId();

    //Setters
    void setName(string name);
	void setType(string type);
	void setBuilt(bool built);
    void setYearBuilt(int yearBuilt);
    void setId(int id);

    //Showing
    string showComputer();
    string showComputerTable();
    string spaceCalc(int cellsize, string value);
    //SearchComp

};

#endif // COMPS_H
