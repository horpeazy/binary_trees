#include "binary_trees.h"

/**
 * binary_tree_is_leaf - checks if a node is a leaf node
 * @node: pointer to the node
 * Return: 1 if it is node , ) otherwise
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (!node || node->right || node->left)
		return (0);

	return (1);
}
