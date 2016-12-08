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
    int Comps::getYearBuilt() {

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
    void Comps::setYearBuilt(int yearBuilt) {
        _yearBuilt = yearBuilt;
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
    string Comps::showComputerTable(){

        string temp = "";
        int cellsize = 15;
        string spTemp;

        spTemp = spaceCalc(cellsize,std::to_string(this->_id));
        temp = temp + "|"+ spTemp ;
        spTemp = spaceCalc(cellsize,this->_name);
        temp = temp + "|" + spTemp ;
        spTemp = spaceCalc(cellsize,(this->_type));
        temp = temp + "|" + spTemp ;
        spTemp = spaceCalc(cellsize,std::to_string(this->_built));
        temp = temp + "|" + spTemp ;
        spTemp = spaceCalc(cellsize,std::to_string(this->_yearBuilt));
        temp = temp + "|" + spTemp  + "|\n";

        return temp;

    }

    string Comps::spaceCalc(int cellsize, string value){

        string idTemp = "";
        int idSize = value.size();

        if(idSize>=cellsize)
        {
            value = value.substr(0, cellsize-3);
            value = value + "... ";
         }
        else{

            unsigned int spaceSize = cellsize - idSize;
            if(spaceSize%2 != 0)
                spaceSize++;

            for(int i=0; i<spaceSize/2; i++)
                idTemp = idTemp + " ";
        }
        return idTemp + value + idTemp;
    }

