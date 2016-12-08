#include "comps.h"

    Comps::Comps(){
        _name = "";
        _type = "";
        _yearBuilt = 0;
        _id = 0;
        _built = false;
    }

    Comps::Comps(int id, string name, string type, int yearBuilt, bool built){
        _id = id;
        _name = name;
        _type = type;
        _built = built;
        _yearBuilt = yearBuilt;
    }
    void Comps::setId(int id){
        _id = id;
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
    int Comps::getId(){

        return _id;

    }
    int Comps::getYearBuilt(){


        return _yearBuilt;
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
        temp = temp + "ID: " + std::to_string(_id) + '\n';
        temp = temp +"Name: " + _name + '\n';
        temp = temp +"Type: " + _type + '\n';
        if (_built)
        {
            temp = temp + "Built\n";
        temp = temp + "Built Year: " + std::to_string(_yearBuilt);
        }
        else
        {
            temp = temp + "Not Built\n";
        }

        temp = temp + "\n";


        return temp;

    }
