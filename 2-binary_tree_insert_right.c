#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node to the right of a node
 * @parent: parent node
 * @value: value of new node
 * Return: pointer to the new node and NULL on failure
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	if (!parent)
		return (NULL);
	node = malloc(sizeof(binary_tree_t));
	if (node == NULL)
		return (NULL);

	node->n = value;
	node->parent = parent;
	node->right = parent->right;
	node->left = NULL;
	if (parent->right)
		parent->right->parent = node;
	parent->right = node;

	return (node);
}
