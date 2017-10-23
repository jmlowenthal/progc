#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * A simple stack implementation.
 * 
 * @var Stack::base
 * A pointer to the beginning of the allocated memory.
 *
 * @var Stack::limit
 * A pointer to the first element that is beyond the bounds of the allocated
 * memory.
 *
 * @var Stack::current
 * A pointer to the element where data will be inserted on the next call of
 * Stack_push.
 */
struct Stack {
	int *base;
	int *limit;
	int *current;
};

/** 
 * Factory function that builds a stack with capacity `size` integers.
 * @param size    Integer capacity.
 */
struct Stack Stack_create(unsigned int size) {
	int *base = (int*) malloc(size * sizeof(int));
	struct Stack s = {
		.base = base,
		.limit = base + size,
		.current = base
	};
	return s;
}

/**
 * Calculates the size of the stack.
 * @param s    A pointer to the stack to use.
 * @return     Number of integers on the stack.
 */
int Stack_size(struct Stack *s) {
	return s->current - s->base;
}

/**
 * Adds a new item to the stack.
 * @oaram s        A pointer to the stack to add to.
 * @param value    The value to add to the stack.
 * @return         True, if the value was added succesfully.
 */
bool Stack_push(struct Stack *s, int value) {
	if (s->current <= s->limit) {
		*s->current = value;
		++(s->current);
		return true;
	}
	else {
		return false;
	}
}

/**
 * Removes an item from the stack.
 * @param s         A pointer to the stack to remove from.
 * @param output    A pointer to the location to fill with the popped value.
 * @return          True, if a value was removed successfully.
 */
bool Stack_pop(struct Stack *s, int *output) {
	if (s->current > s->base) {
		--(s->current);
		*output = *(s->current);
		return true;
	}
	else {
		return false;
	}
}

/**
 * Outputs the stack to stdout in a space seperated list of values.
 * @param s    A pointer to the stack to print.
 */
void Stack_print(struct Stack *s) {
	for (int *c = s->base; c < s->current; ++c) {
		printf("%i ", *c);
	}
	printf("\n");
}

/**
 * Main entry point
 * @param argc    Number of arguments provided (including program name).
 * @param argv    Array of strings containing arguments (the first being the
 *                program name).
 */
void main(int argc, const char **argv) {
	
	// Upper-bound of the stack size is argc
	struct Stack stack = Stack_create(argc);
	
	// Iterate arguments (excluding program name)
	for (int i = 1; i < argc; ++i) {
	
		const char *token = argv[i];
		char command = token[0];
		int operand1, operand2;
		
		// Assume command operators will appear on their own; switch on the
		// first character of the read token
		switch (command) {
			case '+':
				Stack_pop(&stack, &operand1);
				Stack_pop(&stack, &operand2);
				Stack_push(&stack, operand1 + operand2);
				break;
			case '-':
				Stack_pop(&stack, &operand1);
				Stack_pop(&stack, &operand2);
				Stack_push(&stack, operand1 - operand2);
				break;
			case '*':
				Stack_pop(&stack, &operand1);
				Stack_pop(&stack, &operand2);
				Stack_push(&stack, operand1 * operand2);
				break;
			case '/':
				Stack_pop(&stack, &operand1);
				Stack_pop(&stack, &operand2);
				Stack_push(&stack, operand1 / operand2);
				break;
			default:
				// Assume this must be a numerical value, and parse it
				operand1 = atoi(token);
				Stack_push(&stack, operand1);
				break;
		}
		
	}
	
	// Output the stack, which in a simple expression will contain one value, the
	// result
	Stack_print(&stack);

}
