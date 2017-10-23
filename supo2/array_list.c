#include "array_list.h"
#include <stdlib.h>
#include <string.h>

ArrayList ArrayList_init() {
	ArrayList l = { NULL, 0, 0 };
	return l;
}

bool ArrayList_resize(
	ArrayList *list
) {
	if (NULL == list) {
		return false;
	}

	if (NULL == list->data) {
		list->data = malloc(16 * sizeof(int));
		if (NULL == list->data) {
			list->size = 0;
			list->capacity = 0;
			return false;
		}
		else {
			list->capacity = 16;
			return true;
		}
	}
	else {
		list->data = realloc(list->data, list->capacity * 2);
		if (NULL == list->data) {
			list->size = 0;
			list->capacity = 0;
			return false;
		}
		else {
			list->capacity *= 2;
			return true;
		}
	}
}

bool ArrayList_addFront(
	ArrayList *list,
	int value
) {

	if (NULL == list) {
		return false;
	}

	if (list->size + 1 > list->capacity) {
		ArrayList_resize(list);
	}

	memcpy(list->data + 1, list->data, list->size * sizeof(int));

	*list->data = value;
	++list->size;

	return true;

}

bool ArrayList_addBack(
	ArrayList *list,
	int value
) {

	if (NULL == list) {
		return false;
	}

	if (list->size + 1 > list->capacity) {
		ArrayList_resize(list);
	}

	list->data[list->size++] = value;

	return true;

}

bool ArrayList_removeFirst(
	ArrayList *list
) {
	
	if (NULL == list) {
		return false;
	}

	memcpy(list->data, list->data + 1, --list->size);

	return true;

}

bool ArrayList_removeLast(
	ArrayList *list
) {

	if (NULL == list) {
		return false;
	}

	--list->size;

	return true;

}

bool ArrayList_insertNext(
	ArrayList *list,
	int index,
	int value
) {
	
	if (NULL == list || index < 0 || index >= list->size) {
		return false;
	}

	if (list->size + 1 > list->capacity) {
		ArrayList_resize(list);
	}

	memcpy(list->data + index + 2, list->data + index + 1, list->size - index - 1);
	list->data[index + 1] = value;
	++list->size;

	return true;

}

bool ArrayList_insertPrev(
	ArrayList *list,
	int index,
	int value
) {
	
	if (NULL == list || index < 0 || index >= list->size) {
		return false;
	}

	if (list->size + 1 > list->capacity) {
		ArrayList_resize(list);
	}

	memcpy(list->data + index + 1, list->data + index, list->size - index);
	list->data[index] = value;
	++list->size;

	return true;

}

bool ArrayList_remove(
	ArrayList *list,
	int index
) {
	
	if (NULL == list || index < 0 || index >= list->size) {
		return false;
	}

	memcpy(list->data + index, list->data + index + 1, list->size - index - 1);
	--list->size;

	return true;

}
