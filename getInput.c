#include "holberton.h"

/**
 *getInput - Asks the user for input, the input will be used to
 *check for executables
 *
 *Return: returns a double pointer of tokenized input
 */
char **getInput()
{
	char *input = NULL;
	char **args = NULL;
	size_t size;
	int len;

	len = getline(&input, &size, stdin);
	if (len == EOF)
	{
		free(input);
		if (isatty(0))
			write(2, "\n", 1);
		exit(0);
	}
	if (input[len - 1] == '\n')
		input[len - 1] = '\0';
	args = token(input);
	if (args[0] == NULL)
	{
		if (args != NULL)
			free(args);
		if (input != NULL)
			free(input);
		return (NULL);
	}
	if (strcmp(args[0], "env") == 0 && args[1] == NULL)
		printEnv();
	if (strcmp(args[0], "exit") == 0 && args[1] == NULL)
	{
		if (input != NULL)
			free(input);
		freeDoub(args);
		_exit_();
	}
	if (args == NULL)
		return (NULL);
	if (input != NULL)
		free(input);
	return (args);
}
