#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <stdbool.h>

typedef struct {
	int *data;
	unsigned int size;
	unsigned int capacity;
} ArrayList;

/**
 * Creates a linked list.
 */
ArrayList ArrayList_init();

/**
 * Insert an element at the front of the list.
 * @param list     List to prepend to.
 * @param value    Value to prepend.
 * @return         True, if the value is inserted successfully.
 */
bool ArrayList_addFront(
	ArrayList *list,
	int value
);

/**
 * Insert an element at the back of the list.
 * @param list     List to append to.
 * @param value    Value to append.
 * @return         True, if the value is inserted successfully.
 */
bool ArrayList_addBack(
	ArrayList *list,
	int value
);

/**
 * Remove the element at the front of the list.
 * @param list     List to remove from.
 * @return         True, if the value is removed successfully.
 */
bool ArrayList_removeFirst(
	ArrayList *list
);

/**
 * Remove the element at the back of the list.
 * @param list     List to remove from.
 * @return         True, if the value is removed successfully.
 */
bool ArrayList_removeLast(
	ArrayList *list
);

/**
 * Insert an element after the one pointed to.
 * @param list     List to add to.
 * @param index    Item to add after.
 * @param value    Value to insert.
 * @return         True, if insertion was successful.
 */
bool ArrayList_insertNext(
	ArrayList *list,
	int index,
	int value
);

/**
 * Insert an element before the one pointed to.
 * @param list     List to add to.
 * @param index    Item to add before.
 * @param value    Value to insert.
 * @return         True, if insertion was successful.
 */
bool ArrayList_insertPrev(
	ArrayList *list,
	int index,
	int value
);

/**
 * Remove an element after the one pointed to.
 * @param list     List to remove from.
 * @param index    Item to remove after.
 * @return         True, if removal was successful.
 */
bool ArrayList_remove(
	ArrayList *list,
	int index
);

#endif
