#include "lists.h"
#include <iostream>
#include <string.h>

namespace lst {
Element* create_element(int value) {
	Element* ret_element = (Element*)malloc(sizeof(Element));
	ret_element->value	 = value;
	ret_element->next	 = NULL;
	return ret_element;
}

int get_element_count(Element* list) {
	int count = 0;
	while (list) {
		count++;
		list = list->next;
	}
	return count;
}

void append(Element** list, int value) {
	Element* tmp = create_element(value);
	tmp->next	 = *list;
	*list		 = tmp;
}

void insert(Element** list, int value, int index) {
	Element* tmp = create_element(value);
}

void print_list(Element* head) {
	if (head == NULL) {
		std::cout << "[null]\n";
		return;
	}
	std::cout << "[";
	Element* temp = head;
	while (temp) {
		std::cout << temp->value << ", ";
		temp = temp->next;
	}
	std::cout << "\b\b]\n";
}

void set_value(Element* element, int value) {
	element->value = value;
}

int get_value(Element* element) {
	return element->value;
}

} // namespace lst