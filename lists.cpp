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

void insert(Element* list, int value, int index) { // work in progress
	Element* tmp = list;
	int counter	 = 0;
	while (counter < index) {
		counter++;
		tmp = tmp->next;
		if (tmp == NULL) {
			std::cerr << "Error while inserting item: the list ends at " << counter << std::endl;
			return;
		}
	}
	tmp->next = create_element(value);
}

void remove_index(Element** list, int index) { // work in progress
	Element* tmp = *list;
	int counter	 = 0;
	// if (index == 0) {
	// 	*list = list->next;
	// 	return;
	// }
	while (counter < index - 1) {
		counter++;
		tmp = tmp->next;
		if (tmp == NULL) {
			std::cerr << "Error: element " << counter << " not found!\n";
			return;
		}
	}
	if (tmp->next->next)
		tmp->next = tmp->next->next;
	else
		tmp->next = NULL;
}

void find_remove(Element** list, int value) {
	Element* tmp = *list;
	if (tmp->value == value) {
		// if (tmp->next)
		// free(tmp);
		// *tmp = *tmp->next;
		// else
		*list = NULL;
		return;
	}
	while (tmp->next && !(tmp->next->value == value)) tmp = tmp->next;
	if (!(tmp->next->value == value) && tmp == NULL) {
		std::cerr << "Element with value " << value << " not found!";
		return;
	}
	if (tmp->next->next)
		*tmp = *tmp->next->next;
	else
		tmp->next = NULL;
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