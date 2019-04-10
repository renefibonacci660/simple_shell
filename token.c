#include "holberton.h"

char **token(char *buff)
{
	char *tok;
	size_t i, wordCount;
	char **args;

	wordCount = countWords(buff);
	args = malloc(sizeof(char *) * wordCount + 1);
	
	if(args == NULL)
		exit(98);

	i = 0;

	tok = strtok(buff, " ");
	
	while (tok != NULL)
	{
		args[i] = tok;
		i++;
		tok = strtok(NULL, " ");
	}
	args[i] = NULL;
	return (args);
}
