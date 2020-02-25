#include "holberton.h"

static list_t env;

/**
 * populateEnv - Initiates env linked list from environ
 */
void populateEnv(void)
{
	size_t index;

	if (env.count == 0)
	{
		for (index = 0; environ[index] != NULL; index += 1)
			append(&env, environ[index]);
	}
}

/**
 * getEnvList - returns a copy of the current enviroment list
 *
 * Return: returns a copy of the current envoriment list
 */
list_t getEnvList(void)
{
	return (env);
}

/**
 * freeEnv - frees the entire enviroment list
 */
void freeEnv(void)
{
	freeList(&env);
}

/**
 * _setenv - sets a key and value in the enviroment list
 *
 * @key: The key of the enviroment variable
 * @value: The value for the enviromental variable
 */
void _setenv(char *key, char *value)
{
	node_t *node = NULL;
	char *newValue = NULL;
	char *tmp = NULL;
	int place = 0;

	place = _strlen(key);
	newValue = newPath(key, "=", value);
	for (node = env.head; node != NULL; node = node->next)
	{
		if (_strncmp(node->str, key, place) == 0)
			break;
	}
	if (node == NULL)
	{
		append(&env, newValue);
	}
	else
	{
		tmp = node->str;
		node->str = newValue;
		if (tmp != NULL)
			free(tmp);
	}
}

/**
 * _unsetenv - removes an enviroment variable from the
 * enviroment list
 *
 * @key: The enviroment variable to remove from the enviroment list
 */
void _unsetenv(char *key)
{
	node_t *node = NULL;
	node_t *next = NULL;
	int place = 0;

	place = _strlen(key);
	node = env.head;
	if (node == NULL)
		return;
	if (_strncmp(node->str, key, place) == 0)
	{
		env.head = env.head->next;
		freeNode(node);
		return;
	}
	for (next = node->next; next != NULL; next = next->next)
	{
		if (_strncmp(next->str, key, place) == 0)
		{
			node->next = next->next;
			freeNode(next);
			break;
		}
		node = node->next;
	}
}
