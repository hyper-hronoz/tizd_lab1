#pragma once
#include "ListItem.h"
#include "iostream"
#include <cstdlib>

#define List_Template template <class T>

#define List_c List_Template class List
#define List_r List_Template \
	List<T>
#define List_t List<T>

List_c {
private:
	ListItem_t *root;

	ListItem_t *prev;

	uint64_t length;

	class Iterator {
		private:
			uint64_t iterator;
			List_t *parent;

		public:
			Iterator(uint64_t, List *);

			Iterator &operator++();

			Iterator operator++(int);

			ListItem_t &operator*();

			bool operator==(const Iterator &);

			bool operator!=(const Iterator &);
	};

public:
	Iterator begin();
	Iterator end();

	ListItem_t &operator[](uint64_t);

	explicit List_t();

	void append(T);

	void append(T, uint64_t);

	void append(ListItem_t *);

	void append(ListItem_t *, uint64_t);

	int8_t remove(uint64_t);

	void clear();

	void sort(uint8_t invert = 0) {
		for (uint64_t i = 0; i < this->length; i++) {

			for (uint64_t j = 0; j < this->length - i - 1; j++) {
				ListItem_t *current = &(*this)[j];
				ListItem_t *next = &(*this)[j + 1];

				if (current->getValue() > next->getValue() && !invert) {
					T temp = current->getValue();
					current->setValue(next->getValue());
					next->setValue(temp);
				}

				if (current->getValue() < next->getValue() && invert) {
					T temp = current->getValue();
					current->setValue(next->getValue());
					next->setValue(temp);
				}
			}
		}
	};

	ListItem_t *getRoot();

	uint64_t getLength();
};

template class List<int32_t>;
