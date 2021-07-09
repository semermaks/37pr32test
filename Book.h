#pragma once
#include "Tovar.h"
class Book :
	public Tovar
{
protected:
	std::string autor;
	std::string publishing;
public:
	Book();
	Book(std::string name, float price, int ageExtended, std::string autor, std::string publishing);
	virtual ~Book();

	void setAutor(std::string autor);
	void setPublishing(std::string publishing);

	std::string getAutor() const&;
	std::string getPiblishing() const&;

	virtual std::string toString() const& override;
	virtual std::string type() const& override;
	virtual void show() const& override;

	friend std::istream& operator >> (std::istream& is, Book& t);
};

