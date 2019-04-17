#include "holberton.h"
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
	tok = strtok(input, " \t");
	while (tok != NULL)
	{
		len = strLen(tok) + 1;
		args[i] = malloc(sizeof(char) * len);
		if (args[i] == NULL)
			return (NULL);
		_strcpy(args[i], tok);
		i++;
		tok = strtok(NULL, " \t");
	}
	args[i] = NULL;
	return (args);
}
