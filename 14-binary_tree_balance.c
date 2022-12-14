#include "binary_trees.h"

/**
 * re_height - measure the height of a binary tree
 * @node: pointer to the root node
 * Return: hright of tree
 */
/*size_t re_height(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);

	int leftHeight = height(node->left);
	int rightHeight = height(node->right);

	if (leftHeight > rightHeight)
		return (leftHeight + 1);
	return (rightHeight + 1);
}*/

/**
 * binary_tree_balance - calculates the balance tree factor
 * @tree: pointer to the root node
 * Return: balance factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left, right;

	if (!tree)
		return (0);

	left = re_height(tree->left);
	right = re_height(tree->right);

	return (left - right);
}
