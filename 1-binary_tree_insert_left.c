#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node to the left of a node
 * @parent: parent node
 * @value: value of new node
 * Return: pointer to the new node and NULL on failure
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	node = malloc(sizeof(binary_tree_t));
	if (node == NULL || parent == NULL)
		return (NULL);

	node->n = value;
	node->parent = parent;
	node->right = NULL;
	node->left = parent->left;
	if (parent->left)
		parent->left->parent = node;
	parent->left = node;

	return (node);
}
