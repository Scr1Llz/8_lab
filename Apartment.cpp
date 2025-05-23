#include "Apartment.h"
double Apartment:: calculateTax() const {
	if (square > TAX_RATES::LIMIT_Apartment_SQUARE) return getWorth() * TAX_RATES::Apartment_LUXURY_TAX;
	return getWorth() * TAX_RATES::Apartment_TAX;
}