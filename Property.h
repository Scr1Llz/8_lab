#pragma once
class Property {
	size_t worth;
public:
	Property(size_t worth) : worth(worth) {}
	virtual size_t calculatePropertyTax() const = 0;
	size_t calculateIncomeTax() const {
		return worth * 0.13;
	}
	virtual ~Property() {}
};

