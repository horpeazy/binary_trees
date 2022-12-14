#include "binary_trees.h"

/**
 * binary_tree_nodes - cpunts the number of nodes with at least one child
 * @tree: pointer to the root node
 * Return: number of nodes
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t left, right;

	if (!tree)
		return (0);

	left = binary_tree_nodes(tree->left);
	right = binary_tree_nodes(tree->right);

	if (tree->left || tree->right)
		return (left + right + 1);
	return (left + right);
}
