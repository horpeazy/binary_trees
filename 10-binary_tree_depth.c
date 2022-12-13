#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a ndeo in a binary tree
 * @tree: pointer to the node to measure it's depth
 * Return: depth of the node
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	int depth;

	if (!tree || !tree->parent)
		return (0);

	depth = binary_tree_depth(tree->parent);
	return (depth + 1);
}
