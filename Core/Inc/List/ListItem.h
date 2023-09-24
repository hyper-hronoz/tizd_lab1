#pragma once

#include <cstdint>

#define ListItem_c template <class T> \
class ListItem
#define ListItem_t ListItem<T>

ListItem_c {
private:
	ListItem_t *next;
	T value;

public:
	ListItem(T);

	void setValue(T);

	T getValue();

	ListItem_t *getNext();

	void setNext(ListItem_t *);
};
