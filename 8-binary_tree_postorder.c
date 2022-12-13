#include "binary_trees.h"

/**
 * binary_tree_postorder - Postorder traversal of binary tree
 * @tree: pointer to the root node
 * @func: pointer to fucntion to call on each node
 * Return: nothing
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func) return;

	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}
