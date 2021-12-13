#include <iostream>
#include <string.h>

namespace lst {
typedef struct {
	int value;
	Element* next;
} Element;

Element* create_element() {
	Element* ret_element;
	ret_element->next = NULL;
	return ret_element;
}

} // namespace lst