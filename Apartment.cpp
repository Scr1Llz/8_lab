#include "Apartment.h"
size_t Apartment:: calculatePropertyTax() const {
	if (square > TAX_RATES::LIMIT_Apartment_SQUARE) return getWorth() * TAX_RATES::Apartment_LUXURY_TAX;
	return getWorth() * TAX_RATES::Apartment_TAX;
}