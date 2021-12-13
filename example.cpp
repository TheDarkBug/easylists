#include "lists.h"
#include <iostream>

using namespace lst;
int main() {
	Element* list = NULL;
	Element* tmp;
	print_list(list);
	for (int i = 0; i < 10; i++) append(&list, i);
	print_list(list);
	return 0;
}