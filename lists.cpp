#include <iostream>
#include <string.h>

namespace lst {

typedef struct element {
	int value;
	struct element* next;
} Element;

Element* create_element(int value) {
	Element* ret_element = (Element*)malloc(sizeof(Element));
	ret_element->value	 = value;
	ret_element->next	 = NULL;
	return ret_element;
}

void destroy_list(Element* list) {
	Element* to_destroy;
	while (list->next) {
		// to_destroy = list;
		*list = *list->next;
		// free(to_destroy);
		std::cout << "i";
	}
	return;
}

int get_element_count(Element* list) {
	// int count = 0;
	// while (list) {
	// 	count++;
	// 	list = list->next;
	// }
	// return count;
	return 0;
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

void remove_index(Element* list, int index) { // work in progress
	int counter = 0;
	if (index == 0) {
		*list = *list->next;
		return;
	}
	while (counter < index - 1) {
		counter++;
		list = list->next;
		if (list == NULL) {
			std::cerr << "Error: element " << counter << " not found!\n";
			return;
		}
	}
	if (list->next->next)
		list->next = list->next->next;
	else
		list->next = NULL;
}

void find_remove(Element* list, int value) {
	bool found = (list->value == value);

	if (found) {
		if (list->next)
			*list = *list->next;
		else
			destroy_list(list);
		return;
	}
	while (list->next && !found) {
		list  = list->next;
		found = (list->next->value == value);
	}
	if (!found) {
		std::cerr << "Element with value " << value << " does not exist!";
		return;
	}
	if (list->next->next)
		*list->next = *list->next->next;
	else
		list->next = NULL;
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

void set_value(Element* element, int value) { element->value = value; }

int get_value(Element* element) { return element->value; }

} // namespace lst