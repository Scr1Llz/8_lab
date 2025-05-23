#pragma once
#include "Property.h"
#include "Apartment.h"
#include "Car.h"
#include "CountryHouse.h"

class Owner {
	string fullname;
	string inn;
	vector<Property*> properties;
public:
	Owner(const string& name, const string& innn) : fullname(name), inn(innn) {
		if (innn.length() != 12) throw invalid_argument("ИНН должен содержать 12 цифр.");
		for (int i = 0; i < innn.length(); i++) {
			if (!(isdigit(innn[i]))) throw invalid_argument("ИНН содержит не только цифры.");
		}
	}

	void addProperty(Property* property);
	void removeProperty(const size_t& index);

	size_t calculateTotalTax() const;

	string getFullname() const{
		return fullname;
	}
	string getInn() const {
		return inn;
	}

	vector<Property*> getProperties() const {
		return properties;
	}

	void setProperties(const vector<Property*> propertiess) {
		properties = propertiess;
	}

	friend ostream& operator<<(ostream& os, const Owner& owner);

	~Owner() {};
};

