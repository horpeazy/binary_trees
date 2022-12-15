#include "binary_trees.h"

/**
 * is_child - checks if a node is a child of another
 * @parent - parent node
 * @child - child node to check
 * Return: 1 if true, 0 otherwise
 */
int is_child(binary_tree_t *parent, binary_tree_t *child)
{
	int left, right;

	if (!parent || !child)
		return (0);

	if (parent == child || parent->left == child || parent->right == child)
		return (1);

	left = is_child(parent->left, child);
	right = is_child(parent->right, child);

	if (left || right)
		return (1);

	return (0);
}
/**
 * binary_trees_ancestor - finds the loweset common ancestors of two nodes
 * @first: pointer to the first node
 * @second: pointer tothe second node
 * Return: pointer to the LCA
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	binary_tree_t *first_node, *second_node;

	first_node = (binary_tree_t *)first;
	second_node = (binary_tree_t *)second;
	if (!first_node || !second_node)
		return (NULL);

	while (first_node->parent && first_node != second_node)
	{
		if (is_child(first_node, second_node))
			return (first_node);
		if (is_child(second_node, first_node))
			return (second_node);
		first_node = first_node->parent;
		second_node = second_node->parent;
	}

	if (first_node == second_node)
		return (first_node);
	return (NULL);
}
