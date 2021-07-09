#pragma once
#include <iostream>
#include <string>
#include <sstream>
class Tovar
{
protected:
	std::string name;
	float price;
	int ageExtended;
public:
	Tovar();
	Tovar(std::string name, float price, int ageExtended);
	virtual ~Tovar();

	void setName(std::string name);
	void setPrice(float price);
	void setAgeExtended(int ageExtended);

	std::string getName();
	float getPrice();
	int getAgeExtended();

	virtual std::string toString() const& = 0;
	virtual std::string type() const& = 0;
	virtual void show() const& = 0;
};