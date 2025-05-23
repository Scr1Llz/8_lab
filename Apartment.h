#pragma once
#include "Property.h"
class Apartment : public Property{
	double square;
public:
	Apartment(size_t worth, double square) : Property(worth), square(square){}
	size_t calculatePropertyTax() const override {}
};

