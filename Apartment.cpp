#include "Apartment.h"
double Apartment:: calculateTax() const{
	if (square > TAX_RATES::LIMIT_Apartment_SQUARE) return getWorth() * TAX_RATES::Apartment_LUXURY_TAX;
	return getWorth() * TAX_RATES::Apartment_TAX;
}

void Apartment::fromJson(nlohmann::json json)
{
	try
	{
		square = json["Apartment"]["square"];
		setWorth(json["Apartment"]["worth"]);
	}
	catch (nlohmann::json::type_error err)
	{
		throw invalid_argument("error in json format");
	}
}

nlohmann::json Apartment::toJson()
{
	nlohmann::json json;
	json["Apartment"] =
	{
		{
			"tax", calculateTax()
		}
	};
	return json;
}