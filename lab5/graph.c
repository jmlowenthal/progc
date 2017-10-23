#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "graph.h"

Node *empty = NULL;

Node *node(int value, Node *left, Node *right) { 
  Node *r = malloc(sizeof(Node));
  r->marked = false;
  r->value = value;
  r->left = left;
  r->right = right;
  return r;
}


/* Basic Problems */

int size(Node *node) { 
	if (NULL == node) {
		return 0;
	}
	else if (node->marked) {
		return 0;
	}
	node->marked = true;
	int s = size(node->left) + size(node->right) + 1;
	return s;
}


void unmark(Node *node) { 
	if (NULL == node) {
		return;
	}
	else if (!node->marked) {
		return;
	}
	node->marked = false;
	unmark(node->left);
	unmark(node->right);
}

bool path_from(Node *node1, Node *node2) {
	if (NULL == node1 || NULL == node2) {
		return false;
	}
	else if (node1 == node2) {
		return true;
	}
	else {
		return path_from(node1->left, node2) || path_from(node1->right, node2);
	}
}

bool cyclic(Node *node) { 
	if (NULL == node) {
		return false;
	}
	return path_from(node->left, node) || path_from(node->right, node);
} 


/* Challenge problems */

void get_nodes_(Node *node, Node ***dest) {
	if (NULL == node || node->marked) {
		return;
	}
	**dest = node;
	++(*dest);
	get_nodes_(node->left, dest);
	get_nodes_(node->right, dest);
}

void get_nodes(Node *node, Node **dest) { 
	get_nodes_(node, &dest);
}

void graph_free(Node *node) { 
	int s = size(node);
	if (0 >= s) {
		return;
	}

	Node **arr = (Node**) malloc(s * sizeof(Node*));
	get_nodes(node, arr);
	for (int i = 0; i < s; ++i) {
		free((void*)arr[i]);
	}
	free((void*)arr);
}


