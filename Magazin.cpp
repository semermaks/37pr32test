#include "Magazin.h"

Magazin::Magazin()
{
	this->amount = 0;
	this->arr = NULL;
}

Magazin::~Magazin()
{
	if (amount) {
		for (int i = 0; i < amount; i++) {
			delete arr[i];
		}
		delete[] arr;
	}
}

void Magazin::addTovar(Tovar* obj)
{
	Tovar** tmp = new Tovar*[++amount];
	for(int i = 0; i<amount-1; i++){
		tmp[i] = arr[i];
	}
	if (arr != NULL) delete[] arr;
	tmp[amount - 1] = obj;
	this->arr = tmp;
}

void Magazin::dellTovar(int pos)
{
	--pos;
	Tovar** tmp = new Tovar * [--amount];
	for (int i = 0; i < amount; i++) {
		if(i != pos) tmp[i] = arr[i];
	}
	if (arr != NULL) delete[] arr;
	this->arr = tmp;
}

void Magazin::showInfo() const&
{
	for (int i = 0; i < amount; i++) {
		std::cout << "Tovar #" << i + 1<< "\n";
		arr[i]->show();
		std::cout << "________\n";
	}
}

void Magazin::saveToFile()
{
	std::ofstream file;
	file.open("Info.txt", std::ofstream::trunc);
	for (int i = 0; i < amount; i++) {
		file << arr[i]->toString();
		file << "\n";
	}
	std::ofstream file2;
	file2.open("Info2.txt", std::ofstream::trunc);
	file2 << amount;
}

void Magazin::readFormFile()
{
	std::ifstream file("Info.txt");
	std::ifstream file2("Info2.txt");
	std::string type, sTmp;
	float fTmp;
	int iTmp;
	int Famount = 0;
	if (file.is_open() && file2.is_open()) {
		file2 >> Famount;
		amount = Famount;
		arr = new Tovar * [Famount];
		for (int i = 0; i < Famount; i++) {
			file >> type;
			if (type == "Inventory") {
				file >> sTmp;
				arr[i] = new Inventory();
				arr[i]->setName(sTmp);
				file >> fTmp;
				arr[i]->setPrice(fTmp);
				file >> iTmp;
				arr[i]->setAgeExtended(iTmp);
				file >> sTmp;
				((Inventory*)arr[i])->setManufacturer(sTmp);
			}
			else if (type == "Toy") {
				file >> sTmp;
				arr[i] = new Toy();
				arr[i]->setName(sTmp);
				file >> fTmp;
				arr[i]->setPrice(fTmp);
				file >> iTmp;
				arr[i]->setAgeExtended(iTmp);
				file >> sTmp;
				((Toy*)arr[i])->setManufacturer(sTmp);
				file >> sTmp;
				((Toy*)arr[i])->setMaterial(sTmp);
			}
			else if (type == "Book") {
				file >> sTmp;
				arr[i] = new Book();
				arr[i]->setName(sTmp);
				file >> fTmp;
				arr[i]->setPrice(fTmp);
				file >> iTmp;
				arr[i]->setAgeExtended(iTmp);
				file >> sTmp;
				((Book*)arr[i])->setAutor(sTmp);
				file >> sTmp;
				((Book*)arr[i])->setPublishing(sTmp);
			}
		}
		std::cout << "Suqqsesfull\n";
	}
}

void Magazin::seitings(int pos)
{
	std::string type, sTmp;
	float fTmp;
	int choose, iTmp;
	type = arr[--pos]->type();
	if (pos >= 0 && pos <= amount) {
		std::cout << "1 - edit name\n"
			<< "2 - edit price\n"
			<< "3 - edit age Extended\n";
		if (type == "Inventory") {
			std::cout << "4 - edit manufacturer\n";
			std::cin >> choose;
			switch (choose)
			{
			case 1:
				std::cout << "Input new name: ";
				std::cin >> sTmp;
				arr[pos]->setName(sTmp);
				break;
			case 2:
				std::cout << "Input new price: ";
				std::cin >> fTmp;
				arr[pos]->setPrice(fTmp);
				break;
			case 3:
				std::cout << "Input new age Extended: ";
				std::cin >> iTmp;
				arr[pos]->setAgeExtended(iTmp);
				break;
			case 4:
				std::cout << "Input new manufacturer: ";
				std::cin >> sTmp;
				((Inventory*)arr[pos])->setManufacturer(sTmp);
				break;
			default:
				std::cout << "Eror choossing\n";
				break;
			}
		}
		else if (type == "Toy") {
			std::cout << "4 - edit manufacturer\n"
				<< "5 - edit material";
			std::cin >> choose;
			switch (choose)
			{
			case 1:
				std::cout << "Input new name: ";
				std::cin >> sTmp;
				arr[pos]->setName(sTmp);
				break;
			case 2:
				std::cout << "Input new price: ";
				std::cin >> fTmp;
				arr[pos]->setPrice(fTmp);
				break;
			case 3:
				std::cout << "Input new age Extended: ";
				std::cin >> iTmp;
				arr[pos]->setAgeExtended(iTmp);
				break;
			case 4:
				std::cout << "Input new manufacturer: ";
				std::cin >> sTmp;
				((Toy*)arr[pos])->setManufacturer(sTmp);
				break;
			case 5:
				std::cout << "Input new material: ";
				std::cin >> sTmp;
				((Toy*)arr[pos])->setMaterial(sTmp);
				break;
			default:
				std::cout << "Eror choossing\n";
				break;
			}
		}
		else if (type == "Book") {
			std::cout << "4 - edit autor\n"
				<< "5 - edit publishing";
			std::cin >> choose;
			switch (choose)
			{
			case 1:
				std::cout << "Input new name: ";
				std::cin >> sTmp;
				arr[pos]->setName(sTmp);
				break;
			case 2:
				std::cout << "Input new price: ";
				std::cin >> fTmp;
				arr[pos]->setPrice(fTmp);
				break;
			case 3:
				std::cout << "Input new age Extended: ";
				std::cin >> iTmp;
				arr[pos]->setAgeExtended(iTmp);
				break;
			case 4:
				std::cout << "Input new autor: ";
				std::cin >> sTmp;
				((Book*)arr[pos])->setAutor(sTmp);
				break;
			case 5:
				std::cout << "Input new publishing: ";
				std::cin >> sTmp;
				((Book*)arr[pos])->setPublishing(sTmp);
				break;
			default:
				std::cout << "Eror choossing\n";
				break;
			}
		}
	}
	else std::cout << "Eror Entering number!\n";
}
