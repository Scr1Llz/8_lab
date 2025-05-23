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