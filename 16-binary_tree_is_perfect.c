#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_tree_size - calculates the height of a binary tree
 * @tree: pointer to the root node
 * Return: size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t left, right;

	if (!tree)
		return (0);

	left = binary_tree_size(tree->left);
	right = binary_tree_size(tree->right);
	return (left + right + 1);
}

/**
 * height - measure the height of a binary tree
 * @node: pointer to the root node
 * Return: height of tree
 */
size_t height(const binary_tree_t *node)
{
	if (node == NULL)
    		return 0;

  	int leftHeight = height(node->left);
  	int rightHeight = height(node->right);

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
		return (binary_tree_is_perfect(tree->left) && binary_tree_is_perfect(tree->right));
	return (0);
}
