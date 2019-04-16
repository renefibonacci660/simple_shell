#include "holberton.h"
/**
 * getEnv - gets the environ so we can check for PATH
 * Return: copy of environ
 **/

char **getEnv()
{
	size_t i, len;
	char **env;

	for (i = 0; environ[i] != NULL; i++)
	{}

	env = malloc(sizeof(char *) * i + 1);

	if (env == NULL)
		return (NULL);

	for (i = 0; environ[i] != NULL; i++)
	{
		len = strlen(environ[i]);
		env[i] = malloc(sizeof(char) * len + 1);

		if (env[i] == NULL)
			return (NULL);

		strcpy(env[i], environ[i]);
	}
	env[i] = NULL;
	return (env);
}
/**
 *freeDoub - frees a double pointer that was allocated
 *@str: The pointer that needs to be freed
 */
void freeDoub(char **str)
{
	size_t i;

	if (str != NULL)
	{
		for (i = 0; str[i] != NULL; i++)
			free(str[i]);
		if (str != NULL)
			free(str);
	}
}
