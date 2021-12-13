#ifndef LISTS_H // header guards
#define LISTS_H

namespace els {
// List type. Right now the value must be an integer, might change in future
typedef struct list_s List;

// Returns an empty List pointer
List* create_list(int value);

// Destroys the given list
void destroy_list(List** list);

// Returns list count of a list
int get_list_size(List* list);

// Adds a new element with the given value to the start of the list
void push(List** list, int value);

// Inserts a new element with the given value at the given index
void insert(List* list, int value, int index);

// Adds a new element with the given value to the end of the list
void append(List* list, int value);

// Removes an element in the list at the given index
void remove_index(List* list, int index);

// Removes an element of the list that has the given value
void find_remove(List** list, int value);

// Prints the value of all the elements of the list
void print_list(List* list);

// Returns a pointer to the element at the given index
List* get_element(List* list, int index);

// tries to find the element via the given value
int find(List* list, int value);

// Sets the value of a given element of a list
void set_value(List* element, int value);

// Returns the value of an element
int get_value(List* element);

} // namespace els

#endif // LISTS_H