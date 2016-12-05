#include "comps.h"

    Comps::Comps(){
        _name = "";
        _type = "";
        _built = false;
    }

    Comps::Comps(string name, string type, bool built){
        _name = name;
        _type = type;
        _built = built;
    }

	string Comps::getName() {
		return _name;
	}
	string Comps::getType() {
		return _type;
	}
    bool Comps::getBuilt() {
		return _built;
	}
    void Comps::setName(string name) {
		_name = name;
	}
    void Comps::setType(string type) {
		_type = type;
	}
    void Comps::setBuilt(bool built) {
		_built = built;
	}

    string Comps::showComputer(){
        string temp = "";
        temp = temp +"Name: " + _name + '\n';
        temp = temp +"Type: " + _type + '\n';
        if (_built)
        {
            temp = temp + "Built\n";
        }
        else
        {
            temp = temp + "Not Built\n";
        }

        temp = temp + "#\n";

        return temp;

    }
