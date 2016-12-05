#include "comps.h"

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

