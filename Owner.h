#pragma once
#include "Property.h"
#include "Apartment.h"
#include "Car.h"
#include "CountryHouse.h"
#include "PropertySimpleFactory.h"
#include "Ijsonio.h"

class Owner : public Ijsonio {
	string fullname;
	string inn;
	vector<Property*> properties;
public:
	Owner(const string& name, const string& innn) : fullname(name), inn(innn) {
		int count = 0;
		if (innn.length() != 12) throw invalid_argument("ИНН должен содержать 12 цифр.");
		for (int i = 0; i < innn.length(); i++) {
			if (!(isdigit(innn[i]))) throw invalid_argument("ИНН содержит не только цифры.");
		}
		/*if (!(isupper(name[0]))) throw invalid_argument("ФИО записано неверно.");
		for (int i = 0; i < name.length() - 1; i++) {
			if (name[i] == ' ' && !(isupper(name[i + 1]))) throw invalid_argument("Слово начинается не с заглавной буквы.");
			else if (name[i] == ' ') count++;
			else if (!(isalpha(name[i]))) throw invalid_argument("ФИО содержит не только буквы.");
		}
		if (count != 2) throw invalid_argument("В ФИО меньше 3 слов.");*/
	}

	void addProperty(Property* property);
	void removeProperty(const size_t& index);

	void fromJson(nlohmann::json json) override;
	nlohmann::json toJson() override;

	double calculateTotalTax() const;

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

