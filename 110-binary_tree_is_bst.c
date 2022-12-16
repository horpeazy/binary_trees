#include "binary_trees.h"

/**
 * binary_tree_is_bst - checks if a tree is a BST
 * @tree: pointer to the tree
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}

	if (tree->left != NULL && tree->n <= tree->left->n)
	{
		return (0);
	}

	if (tree->right != NULL && tree->n > tree->right->n)
	{
	return (0);
	}

	if (!binary_tree_is_bst(tree->left) || !binary_tree_is_bst(tree->right))
	{
		return (0);
	}

	return (1);
}
