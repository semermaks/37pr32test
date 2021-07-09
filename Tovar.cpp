#include "Tovar.h"

Tovar::Tovar()
{
	this->name = "Noname";
	this->price = 0.1;
	this->ageExtended = 1;
}

Tovar::Tovar(std::string name, float price, int ageExtended)
{
	if (!name.empty()) this->name = name;
	else this->name = "noname";
	if(price >=0) this->price = price;
	else this->price = 0.1;
	if (ageExtended > 0)this->ageExtended = ageExtended;
	else this->ageExtended = 1;
}

Tovar::~Tovar()
{
}

void Tovar::setName(std::string name)
{
	if (!name.empty()) this->name = name;
}

void Tovar::setPrice(float price)
{
	if (price >= 0) this->price = price;
}

void Tovar::setAgeExtended(int ageExtended)
{
	if (ageExtended > 0)this->ageExtended = ageExtended;
}

std::string Tovar::getName()
{
	return name;
}

float Tovar::getPrice()
{
	return price;
}

int Tovar::getAgeExtended()
{
	return ageExtended;
}
