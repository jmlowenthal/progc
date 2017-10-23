#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

/**
 * Shorthand XOR-able pointer type.
 */
typedef uintptr_t ptr_t;

/**
 * Doubly-linked list using the XOR function to eliminate the need for seperate
 * forward and reverse pointers.
 *
 * @var XorList::xorPtr
 * XOR of pointers to the previous and next elements
 * 
 * @var XorList::data
 * Pointer to the data of this node.
 */
typedef struct {
	ptr_t xorPtr;
	void *data;
} XorList;

/**
 * An iterator for XorList which keeps track of the XOR of the previous element
 * and the next one so that we can calculate the next element.
 *
 * @var XorList_Iterator::predXorCurr
 * XOR of the predecessor and the current pointers.
 *
 * @var XorList_Iterator::current
 * Pointer to the current element that the iterator is considering.
 */
typedef struct {
	ptr_t predXorCurr;
	XorList *current;
} XorList_Iterator;

/**
 * Create an iterator over list `l`, which must either point to the first or
 * the last element of a list; the iterator will then iterate the whole list
 * from the given end.
 * @param l    The end of list to iterate from.
 * @return     An iterator over the list going either formward or backward
 *             depending on the input end.
 */
XorList_Iterator *XorList_Iterator_create(XorList *l) {
	XorList_Iterator *itr = (XorList_Iterator*) malloc(sizeof(XorList_Iterator));
	itr->predXorCurr = (ptr_t)l ^ (ptr_t)NULL; // We are either at the start or the end
	itr->current = l;
}

/**
 * Move the iterator forward by one element.
 * @param itr    Iterator to move forward.
 * @return       Whether the iterator is valid, and hence points to an element
 *               in the list.
 */
bool XorList_Iterator_next(XorList_Iterator *itr) {
	if (NULL == itr) {
		return false;
	}
	ptr_t next = itr->predXorCurr ^ itr->current->xorPtr ^ (ptr_t)itr->current;
	itr->predXorCurr = next ^ (ptr_t)itr->current;
	itr->current = (XorList*)next;
	return (XorList*)next != NULL;
}

/**
 * Insert a new element in the list and move the iterator to the newly created
 * element. The element is inserted after the iterator's current element, hence
 * if the iterator is a forward iterator (started at the beginning of the list)
 * then the element comes after the current on, whereas if the iterator is a
 * reverse iterator (started at the back of the array) then the new element
 * comes before the current one by the laid-out naming convention.
 * @param itr     Iterator to follow with the new item.
 * @param head    New value to insert.
 * @return        True, if the element was inserted succesfully.
 */
bool XorList_insert(XorList_Iterator *itr, void *head) {

	XorList *newEl = (XorList*) malloc(sizeof(XorList));
	if (newEl == NULL) {
		return false;
	}

	newEl->data = head;

	if (itr->current) {
		ptr_t prev = itr->predXorCurr ^ (ptr_t)itr->current;
		ptr_t next = itr->current->xorPtr ^ prev;
		if (next) {
			ptr_t nextNext = ((XorList*)next)->xorPtr ^ (ptr_t)itr->current;
			((XorList*)next)->xorPtr = (ptr_t)newEl ^ nextNext;
		}
		newEl->xorPtr = next ^ (ptr_t)itr->current;
		itr->current->xorPtr = prev ^ (ptr_t)newEl;

		XorList_Iterator_next(itr);
	}
	else {
		newEl->xorPtr = (ptr_t)NULL;
		itr->current = newEl;
		itr->predXorCurr = (ptr_t)newEl ^ (ptr_t)NULL;
	}

	return true;

}

/**
 * Call function `f` for all values that follow as the iterator is moved
 * through the list.
 * @param itr    Iterator to use (this will be modified).
 * @param f      Function to call for each element in the list.
 */
void XorList_Iterator_iterate(XorList_Iterator *itr, void f(void*)) {
	do {
		f(itr->current->data);
	}
	while (XorList_Iterator_next(itr));
}

/**
 * Test function for `XorList_Iterator_iterate`.
 * @param d    Pointer to data from list, which is intepretted as a pointer to
 * an integer.
 */
void f(void *d) {
	printf("%i\n", *(int*)d);
}

/**
 * Main entry point.
 */
void main() {

	int data[] = { 1, 2, 3, 4, 5 };
	
	XorList_Iterator *itr = XorList_Iterator_create(NULL);

	XorList_insert(itr, data);
	XorList *list = itr->current;
	
	XorList_insert(itr, data + 1);
	XorList_insert(itr, data + 2);
	XorList_insert(itr, data + 3);
	XorList_insert(itr, data + 4);

	XorList_Iterator *forwarditr = XorList_Iterator_create(list);
	XorList_Iterator_iterate(forwarditr, f);

	// itr is on the last element so the new iterator will be backwards
	XorList_Iterator *backwarditr = XorList_Iterator_create(itr->current);
	XorList_Iterator_iterate(backwarditr, f);

}
