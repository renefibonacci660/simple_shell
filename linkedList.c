#include "holberton.h"

/**
 * makeNode - makes a node with allocated string value
 *
 * @str: The string to allocate and store in the node
 * Return: Returns an allocated node with string value
 */
node_t *makeNode(char *str)
{
	node_t *node = NULL;

	node = malloc(sizeof(node_t));
	if (node == NULL)
		return (NULL);
	node->next = NULL;
	node->str = _strdup(str);
	return (node);
}

/**
 * printLinkedList - helper function that helps
 * prints linked list value
 *
 * @list: The linked list to print
 */
void printLinkedList(list_t list)
{
	node_t *node;

	node = list.head;
	printf("printing linked list:\n");
	printf("******\n");
	while (node != NULL)
	{
		printf("%s\n", node->str);
		node = node->next;
	}
	printf("*******\n");
}

/**
 * append - appends a node to the linked list
 *
 * @list: The linked list to append the node
 * @str: The string value to add to the node
 */
void append(list_t *list, char *str)
{
	node_t *node = NULL;

	node = makeNode(str);
	if (list->head == NULL)
	{
		list->head = node;
		list->tail = node;
		list->count = 1;
	}
	else
	{
		list->tail->next = node;
		list->tail = list->tail->next;
		list->count += 1;
	}
}
