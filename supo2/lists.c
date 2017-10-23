#include "linked_list.h"
#include "array_list.h"

#include <stdio.h>

void printList(LinkedList l) {
	for (
		LinkedListNode *node = l.first;
		node != NULL;
		node = node->next
	) {
		printf("%i ", node->data);
	}
	printf("\n");
}

void printArrayList(ArrayList l) {
	for (int *p = l.data; p < l.data + l.size; ++p) {
		printf("%i ", *p);
	}
	printf("\n");
}

int main() {
	
	LinkedList list = LinkedList_init();
	LinkedList_addFront(&list, 1);
	printList(list);
	LinkedList_addBack(&list, 2);
	printList(list);
	LinkedList_removeFirst(&list);
	printList(list);
	LinkedList_removeLast(&list);
	printList(list);

	ArrayList alist = ArrayList_init();
	ArrayList_addFront(&alist, 1);
	printArrayList(alist);
	ArrayList_addBack(&alist, 2);
	printArrayList(alist);
	ArrayList_removeFirst(&alist);
	printArrayList(alist);
	ArrayList_removeLast(&alist);
	printArrayList(alist);
	
	return 0;
}
