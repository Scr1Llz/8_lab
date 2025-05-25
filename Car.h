#pragma once
#include "Property.h"
#include "Ijsonio.h"
class Car : public Property {
	double horsepower;
public:
	Car(size_t worth, double horsepower) : Property(worth), horsepower(horsepower){}

	double calculateTax() const override;

	void fromJson(nlohmann::json json) override;
	nlohmann::json toJson() override;

	double getHorsePower() const {
		return horsepower;
	}

	~Car() {};
};

