#include "holberton.h"

/**
 * freeList - frees an entire list of nodes
 *
 * @list: The list to free from the heap
 */
void freeList(list_t *list)
{
	node_t *node = NULL;
	node_t *next = NULL;

	if (list == NULL)
		return;
	node = list->head;
	while (node != NULL)
	{
		next = node->next;
		freeNode(node);
		node = next;
	}
}

/**
 * freeNode - frees the given node
 *
 * @node: the node to free and delete
 */
void freeNode(node_t *node)
{
	node_t *tmp = node;

	if (tmp != NULL)
	{
		if (tmp->str != NULL)
			free(tmp->str);
		free(tmp);
	}
}

/**
 * freeArgv - frees argv from the heap
 *
 * @argv: The arguments from the user
 */
void freeArgv(char **argv)
{
	size_t index;

	if (argv == NULL)
		return;
	for (index = 0; argv[index] != NULL; index++)
		free(argv[index]);
	free(argv);
}

/**
 * freeArgs - frees argv and sets count to 0
 *
 * @arg: The agument to free
 */
void freeArgs(args_t *arg)
{
	freeArgv(arg->argv);
	arg->count = 0;
}
