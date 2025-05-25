#include "CountryHouse.h"
double CountryHouse::calculateTax() const {
	if (distanceFromCity > TAX_RATES::LIMIT_DISTANCE_FROM_CITY) return getWorth() * TAX_RATES::COUNTRY_HOUSE_TAX;
	return getWorth() * TAX_RATES::Apartment_TAX;
}

void CountryHouse::fromJson(nlohmann::json json)
{
	try
	{
		distanceFromCity = json["CountryHouse"]["distanceFromCity"];
		setWorth(json["CountryHouse"]["worth"]);
	}
	catch (nlohmann::json::type_error err)
	{
		throw invalid_argument("error in json format");
	}
}

nlohmann::json CountryHouse::toJson()
{
	nlohmann::json json;
	json["CountryHouse"] =
	{
		{
			"tax", calculateTax()
		}
	};
	return json;
}