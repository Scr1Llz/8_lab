#pragma once
#include "Property.h"

using namespace std;

class Owner {
	string fullname;
	string inn;
	vector<Property*> properties;
public:
	Owner(string fullname, string inn) : fullname(fullname), inn(inn){}
	void addProperty(Property* property);
};

