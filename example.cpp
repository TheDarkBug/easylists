#include "lists.h"
#include <iostream>

using namespace lst;
int main() {
	Element* list = NULL;
	print_list(list);
	for (int i = 0; i < 10; i++) push(&list, i);
	print_list(list);
	for (int i = 0; i < 10; i++) append(list, i);
	print_list(list);
	remove_index(list, 17);
	print_list(list);
	find_remove(&list, 3);
	print_list(list);
	insert(list, 3, 2);
	print_list(list);
	destroy_list(&list);
	print_list(list);
	return 0;
}