#pragma once
#include "Book.h"
#include "Toy.h"
#include <fstream>
class Magazin
{
protected:
	int amount;
	Tovar** arr;
public:
	Magazin();
	~Magazin();

	void addTovar(Tovar* obj);
	void dellTovar(int pos);

	void showInfo() const&;
	void saveToFile();
	void readFormFile();
	void seitings(int pos);
};

