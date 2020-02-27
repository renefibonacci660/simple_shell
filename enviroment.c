#include "holberton.h"

/**
 * _getenv - gets the value of the
 * envormental variable
 *
 * @name: The key of the enviromental variable
 * Return: returns the value of the enviromental variable
 */
char *_getenv(char *name)
{
	char *thePath = NULL;
	list_t env = { NULL, NULL, 0 };
	node_t *node = NULL;
	int place;

	place = _strlen(name);
	env = getEnvList();
	for (node = env.head; node != NULL; node = node->next)
	{
		if (_strncmp(node->str, name, place) == 0)
		{
			thePath = node->str + place + 1;
			break;
		}
	}
	return (thePath);
}

/**
 * listPath - creates a list of paths from PATH
 *
 * Return: returns a list of paths from PATH
 */
list_t listPath(void)
{
	char *env = NULL;
	char *tok = NULL;
	list_t list = { NULL, NULL, 0 };

	env = _strdup(_getenv("PATH"));
	tok = strtok(env, ":");
	while (tok != NULL)
	{
		append(&list, tok);
		tok = strtok(NULL, ":");
	}
	free(env);
	return (list);
}
