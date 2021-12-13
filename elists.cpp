#include <iostream>
#include <string.h>

namespace lst {

typedef struct list_s {
	int value;
	struct list_s* next;
} List;

List* create_list(int value) {
	List* new_list	= (List*)malloc(sizeof(List));
	new_list->value = value;
	new_list->next	= NULL;
	return new_list;
}

void destroy_list(List** list) {
	if (*list == NULL) {
		std::cerr << "List is already NULL!\n";
		return;
	}
	List** to_destroy = list;
	while (*list) {
		*to_destroy = *list;
		*list		= (*list)->next;
		*to_destroy = NULL;
	}
	return;
}

int get_list_size(List* list) {
	int count = 0;
	while (list) {
		count++;
		list = list->next;
	}
	return count;
}

void push(List** list, int value) {
	List* new_list = create_list(value);
	new_list->next = *list;
	*list		   = new_list;
}

void insert(List* list, int value, int index) { // work in progress
	int counter = 0;
	while (counter < index - 1) {
		counter++;
		list = list->next;
		if (list == NULL) {
			std::cerr << "Error while inserting item: the list ends at " << counter << std::endl;
			return;
		}
	}
	List* new_list = create_list(value);
	new_list->next = list->next;
	list->next	   = new_list;
}

void append(List* list, int value) {
	List* new_list = create_list(value);
	insert(list, value, get_list_size(list));
}

void remove_index(List* list, int index) { // work in progress
	int counter = 0;
	if (index == 0) {
		*list = *list->next;
		return;
	}
	while (counter < index - 1) {
		counter++;
		if (list == NULL) {
			std::cerr << "Error: element " << index << " not found!\n";
			return;
		}
		list = list->next;
	}
	if (list->next->next)
		list->next = list->next->next;
	else
		list->next = NULL;
}

void find_remove(List** list, int value) {
	List* plist = *list;
	bool found	= (plist->value == value);
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

void print_list(List* head) {
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

List* get_element(List* list, int index) {
	if (list == NULL) {
		std::cerr << "List is empty, you must fill it!\n";
		return NULL;
	}
	while (index > 0 && list) {
		index--;
		list = list->next;
	}
	return list;
}

int find(List* list, int value) {
	int index = 0;
	if (list == NULL) {
		std::cerr << "List is empty, you must fill it!\n";
		return -1;
	}
	while (list && !(list->value == value)) {
		index++;
		list = list->next;
	}
	if (list == NULL) {
		std::cerr << "Element with value " << value << " does not exist!\n";
		return -1;
	}
	return index;
}

void set_value(List* element, int value) {
	if (element == NULL) {
		std::cerr << "Error: impossible to set a value to a NULL pointer!\n";
		return;
	}
	element->value = value;
}

int get_value(List* element) {
	if (element == NULL) {
		std::cerr << "Error: impossible to get a value from a NULL pointer!\n";
		return 0;
	}
	return element->value;
}

} // namespace lst