#pragma once
#include "Tovar.h"

class Inventory :
	public Tovar
{
protected:
	std::string manufacturer;
public:
	Inventory();
	Inventory(std::string name, float price, int ageExtended, std::string manufacturer);
	virtual ~Inventory();

	void setManufacturer(std::string manufacturer);
	std::string getManufacturer() const&;

	virtual std::string toString() const& override;
	virtual std::string type() const& override;
	virtual void show() const& override;

	friend std::istream& operator >> (std::istream& is, Inventory& t);
};

