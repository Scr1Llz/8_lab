#pragma once
#include "Property.h"
class Apartment : public Property{
	double square;
public:
	Apartment(size_t worth, double square) : Property(worth), square(square){}

	double calculateTax() const override;

	void fromJson(nlohmann::json json) override;
	nlohmann::json toJson() override;

	double getSquare() const {
		return square;
	}

	~Apartment() {};
};

