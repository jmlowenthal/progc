#include <stdbool.h>

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

/**
 * Defines the type of the data stored by each node of the linked list.
 * @default    int
 */
#ifndef LinkedList_Type
#define LinkedList_Type int
#endif

/**
 * Concatenates a string to the form <base>_<type>
 */
#define TEMPLATE_(base, type) base ## _ ## type

/**
 * Funky hacks to ensure arguments are evaluated before they are token pasted
 * by TEMPLATE_(base, type).
 */
#define TEMPLATE(...) TEMPLATE_(__VA_ARGS__)

/**
 * A structure which holds a single node in the list.
 * @param LinkedListNode::data    Contains the data for this node.
 * @param LinkedListNode::next    Pointer to the next node in the list.
 */
struct TEMPLATE(LinkedListNode, LinkedList_Type) {
	LinkedList_Type data;
	struct TEMPLATE(LinkedListNode, LinkedList_Type) *next;
};

/**
 * A singly-linked list. This is the main interface for this implementation.
 */
typedef struct {
	struct TEMPLATE(LinkedListNode, LinkedList_Type) *first;
	struct TEMPLATE(LinkedListNode, LinkedList_Type) *last;
} TEMPLATE(LinkedList, LinkedList_Type);

/**
 * Insert an element at the front of the list.
 * @param list     List to prepend to.
 * @param value    Value to prepend.
 * @return         True, if the value is inserted successfully.
 */
bool TEMPLATE(LinkedList, LinkedList_Type) ## _addFront(
	TEMPLATE(LinkedList, LinkedList_Type) *list,
	LinkedList_Type value
) {
	return false;
}

/**
 * Insert an element at the back of the list.
 * @param list     List to append to.
 * @param value    Value to append.
 * @return         True, if the value is inserted successfully.
 */
bool LinkedList_addBack(
	TEMPLATE(LinkedList, LinkedList_Type) *list,
	LinkedList_Type value
) {
	return false;
}

/**
 * Remove the element at the front of the list.
 * @param list     List to remove from.
 * @return         True, if the value is removed successfully.
 */
bool LinkedList_removeFirst(
	TEMPLATE(LinkedList, LinkedList_Type) *list
) {
	return false;
}

/**
 * Remove the element at the back of the list.
 * @param list     List to remove from.
 * @return         True, if the value is removed successfully.
 */
bool LinkedList_removeLast(
	TEMPLATE(LinkedList, LinkedList_Type) *list
) {
	return false;
}

typedef struct {
	struct TEMPLATE(LinkedListNode, LinkedList_Type) *current;
} TEMPLATE(LinkedListIterator, LinkedList_Type);

bool LinkedListIterator_insert(
	TEMPLATE(LinkedListIterator, LinkedList_Type) *list,
	LinkedList_Type value
) {
	return false;
}

bool LinkedListIterator_remove(
	TEMPLATE(LinkedListIterator, LinkedList_Type) *list
) {
	return false;
}

#endif
