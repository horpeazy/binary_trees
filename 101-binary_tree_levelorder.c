#include "binary_trees.h"

/**
 * enqueue - add to a queue
 * @queue: pointer to the queue
 * @node: pointer to the node to insert
 * Return: 1 on success, 0 on failure
 */
int enqueue(queue_t *queue, binary_tree_t *node)
{
	queue_node_t *q_node;

	if (!queue || !node)
		return (0);

	q_node = malloc(sizeof(queue_node_t));
	if (!q_node)
		return (0);
	q_node->node = node;
	q_node->next = NULL;
	if (!queue->head)
	{
		queue->head = q_node;
		queue->tail = q_node;
		queue->is_empty = 0;
		return (1);
	}
	queue->tail->next = q_node;
	queue->tail = q_node;
	return (1);
}

/**
 * dequeue - removes from the queue
 * @queue: pointer to the queue
 * Return: pointer to the removes node
 */
binary_tree_t *dequeue(queue_t *queue)
{
	queue_node_t *q_node;
	binary_tree_t *node;

	if (!queue->head)
		return (NULL);
	q_node = queue->head;
	node = q_node->node;
	queue->head = queue->head->next;
	if (!queue->head)
	{
		queue->is_empty = 1;
	}
	free(q_node->node);
	free(q_node);
	return (node);
}

/**
 * binary_tree_levelorder - binary tree level order traversal
 * @tree: pointer to the root node
 * @func: pointer to the function to call on nodes
 * Return: nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	queue_t *queue;
	binary_tree_t *node;

	queue = malloc(sizeof(queue_t));
	if (!queue)
		return;
	queue->head = NULL;
	queue->tail = NULL;
	queue->is_empty = 1;
	if (!enqueue(queue, (binary_tree_t *)tree))
		return;

	while (!queue->is_empty)
	{
		node = dequeue(queue);
		func(node->n);
		if (node->left)
			if (!enqueue(queue, node->left))
				return;
		if (node->right)
			if (!enqueue(queue, node->right))
				return;
	}
	free(queue);
}
