#include "lists.h"
#include <iostream>

using namespace lst;
int main() {
	Element* list = NULL;
	Element* tmp;
	print_list(list);
	// for (int i = 0; i < 10; i++) append(&list, i);
	append(&list, 9);
	print_list(list);
	remove_index(&list, 3);
	// find_remove(&list, 9);
	print_list(list);
	return 0;
}