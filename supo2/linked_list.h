#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>

/**
 * A structure which holds a single node in the list.
 * @param LinkedListNode::data    Contains the data for this node.
 * @param LinkedListNode::next    Pointer to the next node in the list.
 */
struct s_LinkedListNode {
	int data;
	struct s_LinkedListNode *next;
	struct s_LinkedListNode *prev;
};
typedef struct s_LinkedListNode LinkedListNode;

/**
 * A singly-linked list. This is the main interface for this implementation.
 */
typedef struct {
	LinkedListNode *first;
	LinkedListNode *last;
} LinkedList;

/**
 * Creates a linked list.
 */
LinkedList LinkedList_init();

/**
 * Insert an element at the front of the list.
 * @param list     List to prepend to.
 * @param value    Value to prepend.
 * @return         True, if the value is inserted successfully.
 */
bool LinkedList_addFront(
	LinkedList *list,
	int value
);

/**
 * Insert an element at the back of the list.
 * @param list     List to append to.
 * @param value    Value to append.
 * @return         True, if the value is inserted successfully.
 */
bool LinkedList_addBack(
	LinkedList *list,
	int value
);

/**
 * Remove the element at the front of the list.
 * @param list     List to remove from.
 * @return         True, if the value is removed successfully.
 */
bool LinkedList_removeFirst(
	LinkedList *list
);

/**
 * Remove the element at the back of the list.
 * @param list     List to remove from.
 * @return         True, if the value is removed successfully.
 */
bool LinkedList_removeLast(
	LinkedList *list
);

/**
 * Insert an element after the one pointed to.
 * @param list     List to add to.
 * @param node     Item to add after.
 * @param value    Value to insert.
 * @return         True, if insertion was successful.
 */
bool LinkedList_insertNext(
	LinkedList *list,
	LinkedListNode *iterator,
	int value
);

/**
 * Insert an element before the one pointed to.
 * @param list     List to add to.
 * @param node     Item to add before.
 * @param value    Value to insert.
 * @return         True, if insertion was successful.
 */
bool LinkedList_insertPrev(
	LinkedList *list,
	LinkedListNode *iterator,
	int value
);

/**
 * Remove an element after the one pointed to.
 * @param list     List to remove from.
 * @param node     Item to remove after.
 * @return         True, if removal was successful.
 */
bool LinkedList_remove(
	LinkedList *list,
	LinkedListNode *iterator
);

#endif
