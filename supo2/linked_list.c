#include "linked_list.h"
#include <stdlib.h>

LinkedList LinkedList_init() {
	LinkedList l = { NULL, NULL };
	return l;
}

LinkedListNode *LinkedListNode_init(
	int data,
	LinkedListNode *next,
	LinkedListNode *prev
) {
	LinkedListNode *node = malloc(sizeof(LinkedListNode));
	if (NULL == node) {
		return NULL;
	}
	node->data = data;
	node->next = next;
	node->prev = prev;
	return node;
}

void LinkedListNode_free(
	LinkedListNode *node
) {
	free(node);
}

bool LinkedList_addFront(
	LinkedList *list,
	int value
) {

	if (NULL == list) {
		return false;
	}

	LinkedListNode *node = LinkedListNode_init(value, list->first, NULL);
	
	if (NULL != list->first) {
		list->first->prev = node;
	}

	list->first = node;

	if (NULL == list->last) {
		list->last = list->first;
	}

	return true;

}

bool LinkedList_addBack(
	LinkedList *list,
	int value
) {

	if (NULL == list) {
		return false;
	}

	LinkedListNode *node = LinkedListNode_init(value, NULL, list->last);
	
	if (NULL != list->last) {
		list->last->next = node;
	}

	list->last = node;

	if (NULL == list->first) {
		list->first = list->last;
	}

	return true;

}

bool LinkedList_removeFirst(
	LinkedList *list
) {
	
	if (NULL == list || NULL == list->first) {
		return false;
	}

	LinkedListNode *node = list->first->next;
	LinkedListNode_free(list->first);

	if (NULL != node) {
		node->prev = NULL;
	}

	if (list->first == list->last) {
		list->last = NULL;
	}
	list->first = node;

	return true;

}

bool LinkedList_removeLast(
	LinkedList *list
) {

	if (NULL == list || NULL == list->last) {
		return false;
	}

	LinkedListNode *node = list->last->prev;
	LinkedListNode_free(list->last);

	if (NULL != node) {
		node->next = NULL;
	}

	if (list->first == list->last) {
		list->first = NULL;
	}
	list->last = node;

	return true;

}

bool LinkedList_insertNext(
	LinkedList *list,
	LinkedListNode *node,
	int value
) {
	
	if (NULL == node || NULL == list) {
		return false;
	}

	LinkedListNode *newNode = LinkedListNode_init(value, node->next, node);
	node->next = newNode;
	if (NULL == newNode->next) {
		list->last = newNode;
	}
	else {
		newNode->next->prev = newNode;
	}

	return true;

}

bool LinkedList_insertPrev(
	LinkedList *list,
	LinkedListNode *node,
	int value
) {
	
	if (NULL == node || NULL == list) {
		return false;
	}

	LinkedListNode *newNode = LinkedListNode_init(value, node, node->prev);
	node->prev = newNode;
	if (NULL == newNode->prev) {
		list->first = newNode;
	}
	else {
		newNode->prev->next = newNode;
	}

	return true;

}

bool LinkedList_remove(
	LinkedList *list,
	LinkedListNode *node
) {
	
	if (NULL == node || NULL == list) {
		return false;
	}

	if (NULL != node->prev) {
		node->prev->next = node->next;
	}
	else {
		list->first = node->next;
	}

	if (NULL != node->next) {
		node->next->prev = node->prev;
	}
	else {
		list->last = node->prev;
	}

	LinkedListNode_free(node);

	return true;

}
