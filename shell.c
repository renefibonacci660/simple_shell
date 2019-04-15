#include "holberton.h"

/**
 *printError - prints erros in shell format
 *@str: The command that will be printed in the error
*/
void printError(char *str)
{
	size_t len;

	len = strLen(str); /*errno is a number that is assigned my erros*/
	if (errno == ENOTDIR || errno == ENOENT)
	{
		write(2, str, len);
		write(2, ": Command not found\n", 20);
	}
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

/**
 *token - tokenizes the buffer and returns a double pointer
 *@input: The input from shell
 *Return: returns an allocated double poiter that contains the inputs token
*/
char **token(char *input)
{
	char *tok = NULL;
	size_t i, wordCount, len;
	char **args = NULL;

	wordCount = countWords(input) + 1;
	args = malloc(sizeof(char *) * wordCount); /*Allocate double array*/
	if (args == NULL)
		return (NULL);
	i = 0;
	tok = strtok(input, " ");
	while (tok != NULL)
	{
		len = strLen(tok) + 1;
		args[i] = malloc(sizeof(char) * len);
		if (args[i] == NULL)
			return (NULL);
		_strcpy(args[i], tok);
		i++;
		tok = strtok(NULL, " ");
	}
	args[i] = NULL;
	return (args);
}

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
		exit(1);
	}
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
	if (args == NULL)
		return (NULL);
	if (input != NULL)
		free(input);
	return (args);
}

/**
 *_shell - Creates and uses process to run specified functions.
 * Calls them in a similar way shell would
 */
void _shell(void)
{
	pid_t process;
	char **args;

	args = NULL;
	while (1)
	{
		if (isatty(0))
			write(2, "$ ", 3);
		args = getInput();
		if (args == NULL)
			continue;
		process = fork();
		if (process == -1)
		{
			perror("Error:\n");
			freeDoub(args);
			exit(1);
		}
		if (process == 0)
		{
			if (getPath(args) == NULL)
			{
				if (execve(args[0], args, NULL) == -1)
				{
					printError(args[0]);
					freeDoub(args);
					exit(1);
				}
			}
		}
		else
		{
			wait(NULL);
			freeDoub(args);
		}
	}
	freeDoub(args);
}
