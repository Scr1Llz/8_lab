#include "CountryHouse.h"
double CountryHouse::calculateTax() const {
	if (distanceFromCity > TAX_RATES::LIMIT_DISTANCE_FROM_CITY) return getWorth() * TAX_RATES::COUNTRY_HOUSE_TAX;
	return getWorth() * TAX_RATES::Apartment_TAX;
}