#include "ListItem.h"

template<class T>
ListItem<T>::ListItem(T value) {
	this->value = value;
	this->next = nullptr;
}

template<class T>
void ListItem<T>::setValue(T value) {
	this->value = value;
}

template<class T>
T ListItem<T>::getValue() {
	return this->value;
}

template<class T>
ListItem<T> *ListItem<T>::getNext() {
	return this->next;
}

template<class T>
void ListItem<T>::setNext(ListItem<T> *item) {
	this->next = item;
}

template class ListItem<int32_t>;
