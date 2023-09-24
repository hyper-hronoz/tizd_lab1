#include "List.h"
#include "Log.h"

List_r::List() {
	this->length = 0;
};

List_Template void List_t::append(ListItem_t *current, uint64_t index) {
	try {
		if (index < 0 || index > this->length - 1) {
			throw std::out_of_range("Out of range in method append");
		}
		ListItem_t *next = this->root;
		ListItem_t *prev = this->root;

		if (index == 0 && this->length >= 1) {
			current->setNext(this->root);
			this->root = current;
		}

		for (uint64_t i = 0; i < index; i++) {
			if (i == index - 1) {
				prev = next;
			}
			next = next->getNext();
		}

		if ((0 < index && index < this->length - 1) || (index == this->length - 1 && index != 0)) {
			current->setNext(next);
			prev->setNext(current);
		}

		this->length++;
	} catch (std::out_of_range e) {
		std::cout << e.what() << std::endl;
		Log::writeLog(e.what());
	}
}

List_Template void List_t::append(ListItem_t *item) {
	if (this->length == 0) {
		this->root = item;
		this->length++;
		return;
	}
	this->length++;
	ListItem_t *current = root;
	while (current->getNext()) {
		current = current->getNext();
	}
	current->setNext(item);
}

List_Template
	int8_t
	List_t::remove(uint64_t index) {
	try {

		if (index < 0 || index > this->length - 1) {
			cout << "throwing error" << endl;
			throw std::out_of_range("index out of range when removing");
		}

		ListItem_t *prev = root;
		ListItem_t *current = root;
		ListItem_t *next = root;

		if (index == 0 && this->length > 1) {
			next = current->getNext();
			delete current;
			this->root = next;
		}

		for (uint64_t i = 0; i < index; i++) {
			if (i == index - 1) {
				prev = current;
			}
			current = current->getNext();
		}

		if (0 < index && index <= this->length - 1) {
			next = current->getNext();
			delete current;
			prev->setNext(next);
		}

		this->length--;

		return 1;
	} catch (std::out_of_range e) {
		std::cout << e.what() << std::endl;
		Log::writeLog(e.what());
		return 0;
	}
}

List_Template
	uint64_t
	List_t::getLength() {
	return this->length;
}

List_Template
	ListItem_t *
	List_t::getRoot() {
	return this->root;
}

List_Template
	typename List_t::Iterator
	List_t::begin() {
	return Iterator(0, this);
}

List_Template
	typename List_t::Iterator
	List_t::end() {
	return Iterator(this->length, this);
}

List_Template ListItem_t &List_t::operator[](uint64_t index) {
	if (index >= this->length) {
		exit(0);
	}
	ListItem_t *current = this->root;
	for (int i = 0; i < index; i++) {
		current = current->getNext();
	}
	return *current;
}

List_Template
	typename List_t::Iterator &
	List_t::Iterator::operator++() {
	this->iterator++;
	return *this;
};

List_Template
	typename List_t::Iterator
	List_t::Iterator::operator++(int) {
	Iterator tmp = *this;
	++(*this);
	return tmp;
};

List_Template
List_t::Iterator::Iterator(uint64_t iterator, List_t *parent) : iterator(iterator), parent(parent){};

List_Template
	ListItem_t &
	List_t::Iterator::operator*() {
	return (*this->parent)[iterator];
};

List_Template bool List_t::Iterator::operator==(const Iterator &rhs) {
	return this->iterator == rhs.iterator;
}

List_Template bool List_t::Iterator::operator!=(const Iterator &rhs) {
	return !(this->iterator == rhs.iterator);
}

List_Template void List_t::append(T item) {
	ListItem_t *newItem = new ListItem_t(item);
	this->append(newItem);
}

List_Template void List_t::append(T item, uint64_t index) {
	ListItem_t *newItem = new ListItem_t(item);
	this->append(newItem, index);
}

List_Template
	ListItem_t *
	swap(ListItem_t *ptr1, ListItem_t *ptr2) {
	ListItem_t *tmp = ptr2->getNext();
	ptr2->setNext(ptr1);
	ptr1->setNext(tmp);
	return ptr2;
}
