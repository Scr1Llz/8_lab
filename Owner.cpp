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

void Owner::fromJson(nlohmann::json json)
{
	vector<Property*> properties;
	try
	{
		fullname = json["fullname"];
		inn = json["inn"];
		for (auto propJson : json["properties"])
		{
			string key = propJson.begin().key();
			Property* property = PropertySimpleFactory::getProperty(key);
			property->fromJson(propJson);
			properties.push_back(property);
		}
	}
	catch (nlohmann::json::type_error err)
	{
		throw invalid_argument("error in json format");
	}
	this->properties = properties;
}

nlohmann::json Owner::toJson()
{
	nlohmann::json json;
	json =
	{
		{ "fullname", fullname },
		{ "inn", inn },
		{ "sumtax", calculateTotalTax() },
		{ "properties", nlohmann::json::array() }
	};
	for (auto prop : properties)
	{
		json["properties"].push_back(prop->toJson());
	}
	return json;
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
				os << k << ". Квартира: " << fixed << setprecision(2) << apt->getWorth() << " Площадь: " << fixed << setprecision(2) << apt->getSquare() << " Налог: " << fixed << setprecision(2) << apt->calculateTax() << endl;
			}
			else if (const Car* car = dynamic_cast<const Car*>(prop)) {
				os << k << ". Машина: " << fixed << setprecision(2) << car->getWorth() << " Лошадиных сил: " << fixed << setprecision(2) << car->getHorsePower() << " Налог: " << fixed << setprecision(2) << car->calculateTax() << endl;
			}
			else if (const CountryHouse* house = dynamic_cast<const CountryHouse*>(prop)) {
				os << k << ". Загородный дом: " << fixed << setprecision(2) << house->getWorth() << " Расстояние от города: " << fixed << setprecision(2) << house->getDistance() << " Налог: " << fixed << setprecision(2) << house->calculateTax() << endl;
			}
			k++;
		}
		os << "Общий налог: " << setprecision(2) << owner.calculateTotalTax();
	} 
	return os;
}
