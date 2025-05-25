#include "Owner.h"

void Owner::addProperty(Property* property) {
	if (property != nullptr) {
		properties.push_back(property);
	}
}

void Owner::removeProperty(const size_t& index) {
	if (index >= properties.size()) throw out_of_range("������ ������� �� �������.");
	properties.erase(properties.begin() + index);
}

double Owner::calculateTotalTax() const {
	double total_tax = 0.0;
	for (Property* prop : properties) {
		total_tax += prop->calculateTax();
	}
	return total_tax;
}


ostream& operator<<(ostream& os, const Owner& owner) {
	int k = 1;
	os << " �����������:" << endl;
	os << "���: " << owner.fullname << " ���: " << owner.inn;
	os << endl << "���������: " << endl;
	if (owner.properties.size() == 0) {
		os << "    ��������� ��� :(";
	}
	else {
		for (Property* prop : owner.properties) {
			if (const Apartment* apt = dynamic_cast<const Apartment*>(prop)) {
				os << k << ". ��������: " << apt->getWorth() << " �������: " << apt->getSquare() << " �����: " << apt->calculateTax() << endl;
			}
			else if (const Car* car = dynamic_cast<const Car*>(prop)) {
				os << k << ". ������: " << car->getWorth() << " ��������� ���: " << car->getHorsePower() << " �����: " << car->calculateTax() << endl;
			}
			else if (const CountryHouse* house = dynamic_cast<const CountryHouse*>(prop)) {
				os << k << ". ���������� ���: " << house->getWorth() << " ���������� �� ������: " << house->getDistance() << " �����: " << house->calculateTax() << endl;
			}
			k++;
		}
		os << "����� �����: " << owner.calculateTotalTax();
	} 
	return os;
}
