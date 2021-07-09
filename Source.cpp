#include "Magazin.h"

int main() {
	Magazin Ali;
	Inventory invent;
	Book boo;
	Toy tou;
	int menu = 0, tovar;
	std::cout << "Welcome to our magazin!\n";
	do {
		std::cout << "What you want to do?\n";
		std::cout << "1 - add tovar\n"
			<< "2 - delete tovar\n"
			<< "3 - show info about all tovars\n"
			<< "4 - save tovars to file\n"
			<< "5 - read from file\n"
			<< "6 - seitings\n"
			<< "0 - exit\n";
		std::cin >> menu;
		switch (menu)
		{
		case 1:
			std::cout << "What kind of tovar you want to add?\n";
			std::cout << "1 - Inventory\n"
				<< "2 - Book\n"
				<< "3 - Toy\n";
			std::cin >> tovar;
			switch (tovar)
			{
			case 1:
				std::cin >> invent;
				Ali.addTovar(new Inventory(invent));
				break;
			case 2:
				std::cin >> boo;
				Ali.addTovar(new Book(boo));
				break;
			case 3:
				std::cin >> tou;
				Ali.addTovar(new Toy(tou));
				break;
			default:
				std::cout << "Eror choosing!\n";
				break;
			}
			break;
		case 2:
			Ali.showInfo();
			std::cout << "What number you want to delete?\n";
			std::cin >> tovar;
			Ali.dellTovar(tovar);
			break;
		case 3:
			Ali.showInfo();
			break;
		case 4:
			Ali.saveToFile();
			break;
		case 5:
			Ali.readFormFile();
			break;
		case 6:
			std::cout << "What number you want to edit?\n";
			std::cin >> tovar;
			Ali.seitings(tovar);
			break;
		case 0:
			break;
		default:
			std::cout << "Eror choosing!\n";
			break;
		}
		system("pause");
		system("cls");
	} while (menu);
	system("pause");
	return 0;
}