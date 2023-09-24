#pragma once
#include "iostream"
#include <cstdint>
#include "functional"

class MenuItem {
	private:
		std::string title;
		uint16_t id;
		std::function<void()> callback;

	public:
		MenuItem(uint16_t, std::string);

		MenuItem(uint16_t, std::string, std::function<void()>);

		std::string getTitle();

		uint16_t getId();

		void executeCallback();

		~MenuItem();
};
