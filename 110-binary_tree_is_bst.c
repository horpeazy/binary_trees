#include "binary_trees.h"

/**
 * binary_tree_is_bst - checks if a tree is a BST
 * @tree: pointer to the tree
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int left, right;
	
	if (!tree)
		return (0);

	left = 1;
	right = 1;

	if (tree->left && tree->n <= tree->left->n)
		return (0);
	if (tree->right && tree->n >= tree->right->n)
		return (0);

	left = binary_tree_is_bst(tree->left);
	right = binary_tree_is_bst(tree->right);

	return (left && right);
}
