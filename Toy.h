#pragma once
#include "Inventory.h"
class Toy :
	public Inventory
{
protected:
	std::string material;
public:
	Toy();
	Toy(std::string name, float price, int ageExtended, std::string manufacturer, std::string material);
	virtual ~Toy();

	void setMaterial(std::string material);
	std::string getMaterial() const&;

	virtual std::string toString() const& override;
	virtual std::string type() const&  override;
	virtual void show() const& override;

	friend std::istream& operator >> (std::istream& is, Toy& t);
};

