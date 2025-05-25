#pragma once
#include "Property.h"
#include "Ijsonio.h"
class CountryHouse : public Property {
	size_t distanceFromCity;
public:
	CountryHouse(size_t worth, size_t distanceFromCity) : Property(worth), distanceFromCity(distanceFromCity){}

	double calculateTax() const override;

	void fromJson(nlohmann::json json) override;
	nlohmann::json toJson() override;

	size_t getDistance() const {
		return distanceFromCity;
	}

	~CountryHouse() {};
};

