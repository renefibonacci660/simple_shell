#include "holberton.h"

/**
 * getPath - gets the path of the executable
 *
 * @cmd: The command that needs to be modified
 */
void getPath(char **cmd)
{
	char *ret = NULL;
	node_t *node = NULL;
	list_t list = { NULL, NULL, 0 };

	list = listPath();
	node = list.head;
	if (node == NULL)
		return;
	while (node != NULL)
	{
		ret = filePath(node->str, (*cmd));
		if (ret != NULL)
		{
			free((*cmd));
			(*cmd) = ret;
			break;
		}
		node = node->next;
	}
	freeList(&list);
}
