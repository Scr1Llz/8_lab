#pragma once
#include "Owner.h"
class PropertySimpleFactory {
public:
	static Property* getProperty(std::string key);
};

