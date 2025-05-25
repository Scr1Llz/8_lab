#pragma once
#include "TAX_RATES.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "json.hpp"
#include <windows.h>
#include "Ijsonio.h"

using namespace std;

class Property : public Ijsonio {
	size_t worth;
public:
	Property(size_t worth) : worth(worth) {}

	virtual double calculateTax() const = 0;
	double calculateIncomeTax() const {
		return worth * 0.13;
	}

	size_t getWorth() const {
		return worth;
	}

	void setWorth(const double& worthi) {
		worth = worthi;
	}

	virtual ~Property() {}
};

