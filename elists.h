#ifndef LISTS_H // header guards
#define LISTS_H

namespace lst {
// List type. Right now the value must be an integer, might change in future
typedef struct list List;

// Returns an empty List pointer
List* create_list(int value);

// Destroys the given list
void destroy_list(List** list);

// Returns list count of a list
int get_list_size(List* list);

// Adds a new list with the given value to the start of the list
void push(List** list, int value);

// Inserts a new list with the given value at the given index
void insert(List* list, int value, int index);

// Adds a new list with the given value to the end of the list
void append(List* list, int value);

// Removes an list in the list at the given index
void remove_index(List* list, int index);

// Removes an list in the list that has the given value
void find_remove(List** list, int value);

// Prints the value of all the lists of the list
void print_list(List* list);

// Sets the value of a given list
void set_value(List* list, int value);

// Returns the value of an list, right now index is useless
int get_value(List* list);

} // namespace lst

#endif // LISTS_H