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
	binary_tree_t *new;

	node = malloc(sizeof(binary_tree_t));
	new = malloc(sizeof(binary_tree_t));
	if (node == NULL || parent == NULL || new == NULL)
		return (NULL);

	node->n = value;
	node->parent = parent;

	if (parent->right)
	{
		new->n = parent->right->n;
		new->parent = node;
		new->left = parent->right->left;
		new->right = parent->right->right;
		free(parent->right);
		node->right = new;
	}
	parent->right = node;

	return (node);
}
