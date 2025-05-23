#pragma once
#include "Property.h"
class CountryHouse : public Property {
	size_t distanceFromCity;
public:
	CountryHouse(size_t worth, size_t distanceFromCity) : Property(worth), distanceFromCity(distanceFromCity){}

	double calculateTax() const override;

	size_t getDistance() const {
		return distanceFromCity;
	}

	~CountryHouse() {};
};

