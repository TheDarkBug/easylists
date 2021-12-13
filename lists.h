#ifndef LISTS_H // header guards
#define LISTS_H

namespace lst {
// Element type. Right now the value must be an integer, might change in future
typedef struct Element;

// Function to create a list, returns a List pointer with only one element
Element* create_element();

} // namespace lst

#endif // LISTS_H