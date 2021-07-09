#include "Book.h"

Book::Book()
{
	this->autor = "Unnown";
	this->publishing = "Unnown";
}

Book::Book(std::string name, float price, int ageExtended,
	std::string autor, std::string publishing)
	:Tovar(name,price,ageExtended)
{
	if (!autor.empty()) this->autor = autor;
	else this->autor = "Unnown";
	if (!publishing.empty()) this->publishing = publishing;
	else this->publishing = "Unnown";
}

Book::~Book()
{
}

void Book::setAutor(std::string autor)
{
	if (!autor.empty()) this->autor = autor;
}

void Book::setPublishing(std::string publishing)
{
	if (!publishing.empty()) this->publishing = publishing;
}

std::string Book::getAutor() const&
{
	return autor;
}

std::string Book::getPiblishing() const&
{
	return publishing;
}

std::string Book::toString() const&
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
	tmp += autor;
	tmp += " ";
	tmp += publishing;
	return tmp;
}

std::string Book::type() const&
{
	return "Book";
}

void Book::show() const&
{
	std::cout << "Type: " << type()
		<< "\nName: " << name
		<< "\nPrice: " << price
		<< "\nAge Extended: " << ageExtended
		<< "\nAutor: " << autor
		<< "\nPublishing: " << publishing << "\n";
}

std::istream& operator>>(std::istream& is, Book& t)
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
	std::cout << "\nInput autor: ";
	std::cin >> sTmp;
	t.autor = sTmp;
	std::cout << "\nInput publishing: ";
	std::cin >> sTmp;
	t.publishing = sTmp;
	return is;
}
