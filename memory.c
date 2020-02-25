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
		if (node->str != NULL)
			free(node->str);
		free(node);
		node = next;
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
