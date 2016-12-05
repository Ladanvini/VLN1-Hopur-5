#include "comps.h"

	string Comps::getName() {
		return _name;
	}
	string Comps::getType() {
		return _type;
	}
	bool getBuilt() {
		return _built;
	}
	void setName(string name) {
		_name = name;
	}
	void setType(string type) {
		_type = type;
	}
	void setBuilt(bool built) {
		_built = built;
	}

