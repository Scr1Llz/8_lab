#include "PropertySimpleFactory.h"

Property* PropertySimpleFactory::getProperty(string key)
{
	if (key == "Apartment")
	{
		return new Apartment(0, 0);
	}
	else if (key == "Car")
	{
		return new Car(0, 0);
	}
	else if (key == "CountryHouse")
	{
		return new CountryHouse(0, 0);
	}
	else throw invalid_argument("");
}
