#include "Inventory.h"

Inventory::Inventory()
{
	this->manufacturer = "Noname";
}

Inventory::Inventory(std::string name, float price,
	int ageExtended, std::string manufacturer)
	:Tovar(name, price, ageExtended)
{
	if (!manufacturer.empty()) this->manufacturer = manufacturer;
	else this->manufacturer = "Noname";
}

Inventory::~Inventory()
{
}

void Inventory::setManufacturer(std::string manufacturer)
{
	if (!manufacturer.empty()) this->manufacturer = manufacturer;
}

std::string Inventory::getManufacturer() const&
{
	return manufacturer;
}

std::string Inventory::toString() const&
{
	std::string tmp;
	std::ostringstream SStmp;
	tmp += type();
	tmp += " ";
	tmp += name;
	tmp += " ";
	SStmp << price << " " << ageExtended;
	tmp += SStmp.str();
	tmp += " ";
	tmp += manufacturer;
	return tmp;
}

std::string Inventory::type() const&
{
	return "Inventory";
}

void Inventory::show() const&
{
	std::cout << "Type: " << type()
		<< "\nName: " << name
		<< "\nPrice: " << price
		<< "\nAge Extended: " << ageExtended
		<< "\nManufacter: " << manufacturer << "\n";
}

std::istream& operator>>(std::istream& is, Inventory& t)
{
	std::string sTmp;
	float fTmp;
	int iTmp;
	std::cout << "Input name: ";
	std::cin >> sTmp;
	t.name = sTmp;
	std::cout << "\nInput price: ";
	std::cin >> fTmp;
	t.price = fTmp;
	std::cout << "\nInput age extended: ";
	std::cin >> iTmp;
	t.ageExtended = iTmp;
	std::cout << "\nInput manufacturer: ";
	std::cin >> sTmp;
	t.manufacturer = sTmp;
	return is;
}
