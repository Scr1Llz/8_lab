#pragma once
#include "Property.h"
class CountryHouse : public Property {
	size_t distanceFromCity;
public:
	CountryHouse(size_t worth, size_t distanceFromCity) : Property(worth), distanceFromCity(distanceFromCity){}
	size_t calculatePropertyTax() const override {}
};

