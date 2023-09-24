#include "List.h"
#include "ListItem.h"
#include "Menu.h"
#include "MenuItemFactory.h"
#include "fstream"
#include "iostream"
#include "Log.h"

using namespace std;

void save_to_file(List<int32_t> *list, string filename) {
	ofstream stream(filename, ios::binary);
	uint64_t buffl = list->getLength();
	stream.write((char *)&buffl, sizeof(uint64_t));
	while (list->getLength()) {
		int32_t buff = (*list)[0].getValue();
		stream.write((char *)&buff, sizeof(int32_t));
		list->remove(0);
	}
	stream.close();
}

void load_from_file(List<int32_t> *list, string filename) {
	ifstream stream(filename, ios::binary);

	uint64_t length;
	stream.read((char *)&length, sizeof(uint64_t));
	cout << "Length: " << length << endl;
	while (length) {
		int32_t buff;
		stream.read((char *)&buff, sizeof(uint32_t));
		list->append(buff);
		length--;
	}

	stream.close();
}

int main(int argc, char *argv[]) {
	List<int32_t> *list = new List<int32_t>();

	list->append(1);
	list->append(-4);
	list->append(2);
	list->append(4);
	list->append(-1);
	list->append(-2);
	list->append(5);
	list->append(-3);
	list->append(3);
	list->append(0);
	list->append(-5);
	list->append(0);

	Menu *menu = new Menu();

	MenuItemFactory *menuItemFactory = new MenuItemFactory();

	std::string output_filename;
	std::string source_filename;
	std::string *error_filename = &Log::filename;

	if (argc == 4) {
		source_filename = argv[1];
		output_filename = argv[2];
		*error_filename = argv[3];
	}

	menu->append(menuItemFactory->create("append", [&]() {
		uint32_t newValue = 0;
		cout << "Input newValue: ";
		cin >> newValue;
		cout << endl;
		list->append(newValue);
	}));

	menu->append(menuItemFactory->create("append to", [&]() {
		uint32_t newValue = 0;
		uint64_t position = 0;

		cout << "Input newValue: ";
		cin >> newValue;
		cout << endl;

		cout << "Input position: ";
		cin >> position;
		cout << endl;

		list->append(newValue, position);
	}));

	menu->append(menuItemFactory->create("remove", [&]() {
		uint32_t index = 0;
		cout << "Input index to be removed: ";
		cin >> index;
		cout << endl;
		list->remove(index);
	}));
	menu->append(menuItemFactory->create("replace", [&]() {
		uint32_t newValue = 0;
		uint32_t index = 0;
		cout << "Input index to be removed: ";
		cin >> index;
		cout << endl;
		cout << "Input newValue: ";
		cin >> newValue;
		cout << endl;
		list->remove(index);
		list->append(newValue, index);
	}));

	menu->append(menuItemFactory->create("print", [&]() {
		cout << list << endl;
		cout << &list << endl;
		for (ListItem item : (*list)) {
			cout << item.getValue() << endl;
		}
	}));

	menu->append(menuItemFactory->create("sort", [&]() {
		list->sort();
	}));

	menu->append(menuItemFactory->create("sort reverse", [&]() {
		list->sort(1);
	}));

	int number;
	menu->append(menuItemFactory->create("sort by task", [&]() {
		List<int32_t> *negatives = new List<int32_t>();
		List<int32_t> *positives = new List<int32_t>();
		List<int32_t> *newList = new List<int32_t>();
		number++;

		cout << number << endl;
		cout << list << endl;
		cout << &list << endl;

		for (ListItem item : (*list)) {
			if (item.getValue() < 0) {
				negatives->append(item.getValue());
			} else {
				positives->append(item.getValue());
			}
		}

		negatives->sort(1);
		positives->sort();

		for (ListItem item : (*negatives)) {
			newList->append(item.getValue());
		}

		for (ListItem item : (*positives)) {
			newList->append(item.getValue());
		}

		delete list;
		list = newList;
		delete negatives;
		delete positives;
	}));

	menu->append(menuItemFactory->create("sort reverse", [&list]() {
		list->sort(1);
	}));

	menu->append(menuItemFactory->create("load from file", [&]() {
		char keep_name = 'n';
		cout << "do y wanny change filename?(y/n)"; cin >> keep_name;
		if (keep_name != 'y') {
			cout << "Input file name: ";
			cin >> source_filename;
		}
		load_from_file(&(*list), source_filename);
	}));

	menu->append(menuItemFactory->create("save to file", [&]() {
		char keep_name = 'n';
		cout << "do y wanny change filename?(y/n)"; cin >> keep_name;
		if (keep_name != 'y') {
			cout << "Input file name: ";
			cin >> output_filename;
		}
		save_to_file(&(*list), output_filename);
	}));

	menu->awaitUserInput();

	delete menuItemFactory;
	delete menu;
	delete list;

	return 0;
}
