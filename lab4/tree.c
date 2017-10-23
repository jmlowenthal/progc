#include <stdlib.h>
#include "tree.h"

#include <stdio.h>

Tree *empty = NULL;

/* BASE EXERCISE */

int tree_member(int x, Tree *tree) { 
	if (tree == NULL) {
		return 0;
	}
	if (x == tree->value) {
		return 1;
	}
	if (tree_member(x, tree->left)) {
		return 1;
	}
	if (tree_member(x, tree->right)) {
		return 1;
	}
	return 0;
}

Tree *tree_insert(int x, Tree *tree) { 

	Tree *n = (Tree*) malloc(sizeof(Tree));
	n->value = x;

	if (tree == NULL) {
		return n;
	}

	if (x < tree->value) {
		if (tree->left == NULL) {
			tree->left = n;
		}
		else {
			tree_insert(x, tree->left);
		}
	}
	else {
		if (tree->right == NULL) {
			tree->right = n;
		}
		else {
			tree_insert(x, tree->right);
		}
	}

	return tree;

}

void tree_free(Tree *tree) { 

	if (tree->left != NULL) {
		tree_free(tree->left);
	}

	if (tree->right != NULL) {
		tree_free(tree->right);
	}

	free(tree);

}

/* CHALLENGE EXERCISE */ 

void pop_minimum(Tree *tree, int *min, Tree **new_tree) { 
	if (tree->left == NULL) {
		*min = tree->value;
		*new_tree = tree->right;
		free(tree);
	}
	else {
		Tree *t = tree;
		while (t->left->left != NULL) {
			t = t->left;
		}
		*min = t->left->value;
		if (t->left->right != NULL) {
			Tree *tmp = t->left->right;
			free(t->left);
			t = tmp;
		}
		else {
			t->left = NULL;
		}
		*new_tree = tree;
	}
}

Tree *tree_remove(int x, Tree *tree) { 
	if (tree == NULL) {
		return tree;
	}
	else if (tree->value == x) {
		if (tree->right != NULL) {
			pop_minimum(tree->right, &tree->value, &tree->right);
		}
		else {
			Tree *tmp = tree->left;
			if (tmp != NULL) {
				free(tree);
			}
			tree = tmp;
		}
		return tree;
	}
	else {
		tree->left = tree_remove(x, tree->left);
		tree->right = tree_remove(x, tree->right);
		return tree;
	}
	return empty;
}
