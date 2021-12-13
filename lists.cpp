#include <iostream>
#include <string.h>

namespace lst {

typedef struct element {
	int value;
	struct element* next;
} Element;

Element* create_element(int value) {
	Element* new_element = (Element*)malloc(sizeof(Element));
	new_element->value	 = value;
	new_element->next	 = NULL;
	return new_element;
}

void destroy_list(Element** list) {
	if (*list == NULL) {
		std::cerr << "List is already void!\n";
		return;
	}
	Element** to_destroy = list;
	while (*list) {
		*to_destroy = *list;
		*list		= (*list)->next;
		*to_destroy = NULL;
	}
	return;
}

int get_list_size(Element* list) {
	int count = 0;
	while (list) {
		count++;
		list = list->next;
	}
	return count;
}

void push(Element** list, int value) {
	Element* new_element = create_element(value);
	new_element->next	 = *list;
	*list				 = new_element;
}

void insert(Element* list, int value, int index) { // work in progress
	int counter = 0;
	while (counter < index - 1) {
		counter++;
		list = list->next;
		if (list == NULL) {
			std::cerr << "Error while inserting item: the list ends at " << counter << std::endl;
			return;
		}
	}
	Element* new_element = create_element(value);
	new_element->next	 = list->next;
	list->next			 = new_element;
}

void append(Element* list, int value) {
	Element* new_element = create_element(value);
	insert(list, value, get_list_size(list));
}

void remove_index(Element* list, int index) { // work in progress
	int counter = 0;
	if (index == 0) {
		*list = *list->next;
		return;
	}
	while (counter < index - 1) {
		counter++;
		if (list == NULL) {
			std::cerr << "Error: element " << counter + 1 << " not found!\n";
			return;
		}
		list = list->next;
	}
	if (list->next->next)
		list->next = list->next->next;
	else
		list->next = NULL;
}

void find_remove(Element** list, int value) {
	Element* plist = *list;
	bool found	   = (plist->value == value);
	if (found) {
		if (plist->next)
			*plist = *plist->next;
		else {
			destroy_list(list);
			return;
		}
	}
	while (plist->next && !found) {
		plist = plist->next;
		found = (plist->next->value == value);
	}
	if (!found) {
		std::cerr << "Element with value " << value << " does not exist!\n";
		return;
	}
	if (plist->next->next)
		*plist->next = *plist->next->next;
	else
		plist->next = NULL;
}

void print_list(Element* head) {
	if (head == NULL) {
		std::cout << "[null]\n";
		return;
	}
	std::cout << "[";
	while (head) {
		std::cout << head->value << ", ";
		head = head->next;
	}
	std::cout << "\b\b]\n";
}

void set_value(Element* element, int value) { element->value = value; }

int get_value(Element* element) { return element->value; }

} // namespace lst