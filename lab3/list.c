#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

List *cons(int head, List *tail) { 
  /* malloc() will be explained in the next lecture! */
  List *cell = malloc(sizeof(List));
  cell->head = head;
  cell->tail = tail;
  return cell;
}

/* Functions for you to implement */

int sum(List *list) {
	int sum = 0;
	while (list != NULL) {
		sum += list->head;
		list = list->tail;
	}
	return sum;
}

void iterate(int (*f)(int), List *list) {
  	while (list != NULL) {
  		list->head = f(list->head);
		list = list->tail;
  	}
}

void print_list(List *list) { 
	printf("[ ");
	while (list != NULL) {
		printf("%i ", list->head);
		list = list->tail;
	}
	printf("]\n");
}

/**** CHALLENGE PROBLEMS ****/

List *merge(List *list1, List *list2) { 
  	List *l = NULL;
	List *last = NULL;
	
	while (list1 != NULL && list2 != NULL) {
  		if (list1->head < list2->head) {
			if (last) {
				last->tail = list1;
			}
			else {
				l = list1;
			}
			last = list1;
			list1 = list1->tail;
			
		}
		else {
			if (last) {
				last->tail = list2;
			}
			else {
				l = list2;
			}
			last = list2;
			list2 = list2->tail;
		}
	}

	while (list1 != NULL) {
		if (last) {
			last->tail = list1;
		}
		else {
			l = list1;
		}
		last = list1;
		list1 = list1->tail;
	}

	while (list2 != NULL) {
		if (last) {
			last->tail = list2;
		}
		else {
			l = list2;
		}
		last = list2;
		list2 = list2->tail;
	}

  	return l;
}

void split(List *list, List **list1, List **list2) { 
	
	List *l1 = NULL;
	List *l2 = NULL;

	bool assignL1 = true;
	while (list != NULL) {
		
		if (assignL1) {
			l1 = cons(list->head, l1);
		}
		else {
			l2 = cons(list->head, l2);
		}
		
		assignL1 = !assignL1;
		list = list->tail;

	}

	*list1 = l1;
	*list2 = l2;

}

/* You get the mergesort implementation for free. But it won't
   work unless you implement merge() and split() first! */

List *mergesort(List *list) { 
  if (list == NULL || list->tail == NULL) { 
    return list;
  }
  else { 
    List *list1;
    List *list2;
    split(list, &list1, &list2);
    list1 = mergesort(list1);
    list2 = mergesort(list2);
    return merge(list1, list2);
  }
}
