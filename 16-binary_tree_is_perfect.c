#include "binary_trees.h"

/**
 * height - measure the height of a binary tree
 * @node: pointer to the root node
 * Return: height of tree
 */
int height(const binary_tree_t *node)
{
	int leftHeight, rightHeight;

	if (node == NULL)
		return (0);

	leftHeight = height(node->left);
	rightHeight = height(node->right);

	if (leftHeight > rightHeight)
		return (leftHeight + 1);
	return (rightHeight + 1);
}

/**
 * binary_tree_is_perfect - checks if a tree is perfect
 * @tree: pointer to the root node
 * Return: 1 or 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (!tree)
		return (0);

	left_height = height(tree->left);
	right_height = height(tree->right);

	if (left_height != right_height)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	if (tree->left && tree->right)
		return (binary_tree_is_perfect(tree->left) &&
			binary_tree_is_perfect(tree->right));
	return (0);
}
