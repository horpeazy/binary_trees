#include "binary_trees.h"

/**
 * binary_tree_height - measure the height of a binary tree
 * @tree: pointer to the root node
 * Return: hright of tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	int left_height = 0;
	int right_height = 0;

	if (!tree)
		return (0);

	if (tree->left)
		left_height = 1 + binary_tree_height(tree->left);
	else
		left_height = 0;
	if (tree->right)
		right_height = 1 + binary_tree_height(tree->right);
	else
		right_height = 0;
	if (left_height > right_height)
		return (left_height);
	return (right_height);
}
