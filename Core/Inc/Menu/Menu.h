#pragma once

#include "MenuItem.h"
#include "iostream"
#include "vector"

class Menu {
	private:
		std::string title;
		std::vector<MenuItem *> menuItems;

	public:
		explicit Menu();

		Menu(std::string name);

		~Menu();

		void append(MenuItem *menuItem);

		void print();

		void setName(std::string name);

		std::string getName();

		void awaitUserInput();
};
