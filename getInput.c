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
	if (_strcmp(args[0], "env") == 0 && args[1] == NULL)
		printEnv();
	if (_strcmp(args[0], "exit") == 0 && args[1] == NULL)
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


/**
 *_strcmp - Compares two strings and returns the difference of both strings
 *
 *@s1: A pointer to the address of the given string.
 *
 *@s2: Another pointer to the adress of the given string.
 *
 *Return: returns the difference of two ascii character values from the two
 *given strings
 */
int _strcmp(char *s1, char *s2)
{
	int index;
	char let1;
	char let2;

	index = 0;
	let2 = '0';
	let1 = '0';
	while (s1[index] == s2[index] && s1[index] != '\0' && s1[index] != '\0')
		index++;
	let1 = s1[index];
	let2 = s2[index];
	return (let1 - let2);
}
