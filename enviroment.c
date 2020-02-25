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
	size_t i;
	int place;

	place = _strlen(name);
	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strncmp(environ[i], name, place) == 0)
		{
			thePath = environ[i] + place + 1;
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

	env = _getenv("PATH");
	tok = strtok(env, ":");
	while (tok != NULL)
	{
		append(&list, tok);
		tok = strtok(NULL, ":");
	}
	return (list);
}
