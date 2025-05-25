#include "Owner.h"

void Owner::addProperty(Property* property) {
	if (property != nullptr) {
		properties.push_back(property);
	}
}

void Owner::removeProperty(const size_t& index) {
	if (index >= properties.size()) throw out_of_range("Индекс выходит за границы.");
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
	os << " Собственник:" << endl;
	os << "ФИО: " << owner.fullname << " ИНН: " << owner.inn;
	os << endl << "Имущество: " << endl;
	if (owner.properties.size() == 0) {
		os << "    Имущества нет :(";
	}
	else {
		for (Property* prop : owner.properties) {
			if (const Apartment* apt = dynamic_cast<const Apartment*>(prop)) {
				os << k << ". Квартира: " << apt->getWorth() << " Площадь: " << apt->getSquare() << " Налог: " << apt->calculateTax() << endl;
			}
			else if (const Car* car = dynamic_cast<const Car*>(prop)) {
				os << k << ". Машина: " << car->getWorth() << " Лошадиных сил: " << car->getHorsePower() << " Налог: " << car->calculateTax() << endl;
			}
			else if (const CountryHouse* house = dynamic_cast<const CountryHouse*>(prop)) {
				os << k << ". Загородный дом: " << house->getWorth() << " Расстояние от города: " << house->getDistance() << " Налог: " << house->calculateTax() << endl;
			}
			k++;
		}
		os << "Общий налог: " << owner.calculateTotalTax();
	} 
	return os;
}
