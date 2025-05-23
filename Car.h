#pragma once
#include "Property.h"
class Car : public Property {
	double horsepower;
public:
	Car(size_t worth, double horsepower) : Property(worth), horsepower(horsepower){}
	double calculateTax() const override {}
};

