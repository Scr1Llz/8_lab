#include "Car.h"
double Car::calculateTax() const {
	if (horsepower > TAX_RATES::LOW_HORSEPOWER) {
		if (horsepower > TAX_RATES::HIGH_HORSEPOWER) {
			return getWorth() * TAX_RATES::CAR_LUXURY_TAX;
		}
		return getWorth() * TAX_RATES::CAR_TRUCK_TAX;
	}
	return getWorth() * TAX_RATES::CAR_TAX;
}

void Car::fromJson(nlohmann::json json)
{
	try
	{
		horsepower = json["Car"]["horsepower"];
		setWorth(json["Car"]["worth"]);
	}
	catch (nlohmann::json::type_error err)
	{
		throw invalid_argument("error in json format");
	}
}

nlohmann::json Car::toJson()
{
	nlohmann::json json;
	json["Car"] =
	{
		{
			"tax", calculateTax()
		}
	};
	return json;
}