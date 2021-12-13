#ifndef LISTS_H // header guards
#define LISTS_H

namespace lst {
// Element type. Right now the value must be an integer, might change in future
typedef struct element Element;

// Returns an empty Element pointer
Element* create_element(int value);

// Destroys the given list
void destroy_list(Element** list);

// Returns element count of a list
int get_list_size(Element* list);

// Adds a new element with the given value to the start of the list
void push(Element** list, int value);

// Inserts a new element with the given value at the given index
void insert(Element* list, int value, int index);

// Adds a new element with the given value to the end of the list
void append(Element* list, int value);

// Removes an element in the list at the given index
void remove_index(Element* list, int index);

// Removes an element in the list that has the given value
void find_remove(Element** list, int value);

// Prints the value of all the elements of the list
void print_list(Element* list);

// Sets the value of a given element
void set_value(Element* element, int value);

// Returns the value of an element, right now index is useless
int get_value(Element* element);

} // namespace lst

#endif // LISTS_H