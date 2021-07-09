#include "Toy.h"

Toy::Toy()
{
	this->material = "Unnown";
}

Toy::Toy(std::string name, float price, int ageExtended,
	std::string manufacturer, std::string material)
	:Inventory(name,price,ageExtended,manufacturer)
{
	if (!this->material.empty()) this->material = material;
	else this->material = "Unnown";
}

Toy::~Toy()
{
}

void Toy::setMaterial(std::string material)
{
	if (!this->material.empty()) this->material = material;
}

std::string Toy::getMaterial() const&
{
	return material;
}

std::string Toy::toString() const&
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
	tmp += " ";
	tmp += material;
	return tmp;
}

std::string Toy::type() const&
{
	return "Toy";
}

void Toy::show() const&
{
	std::cout << "Type: " << type()
		<< "\nName: " << name
		<< "\nPrice: " << price
		<< "\nAge Extended: " << ageExtended
		<< "\nManufacter: " << manufacturer
		<< "\nMaterial: "<< material<< "\n";
}

std::istream& operator>>(std::istream& is, Toy& t)
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
	std::cout << "\nInput material: ";
	std::cin >> sTmp;
	t.material = sTmp;
	return is;
}
