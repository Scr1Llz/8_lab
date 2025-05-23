#pragma once
#include "TAX_RATES.h"

class Property {
	size_t worth;
public:
	Property(size_t worth) : worth(worth) {}
	virtual size_t calculatePropertyTax() const = 0;
	size_t calculateIncomeTax() const {
		return worth * 0.13;
	}
	size_t getWorth() const {
		return worth;
	}
	virtual ~Property() {}
};

