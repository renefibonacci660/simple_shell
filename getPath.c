#include "holberton.h"

void getPath(char **ex)
{
	char *tok, *thePath;
	char buf[100];
	char *check = NULL;
	size_t i;
	struct stat st;

	for(i = 0; environ[i] != NULL; i++)
	{
		tok = strtok(environ[i], "=");
		
		if(strcmp(tok, "PATH") == 0)
		{
			thePath = strtok(NULL, environ[i]);
			break;
		}
	}
	tok = strtok(thePath, ":");

	while (tok != NULL)
	{
		tok = strtok(NULL, ":");
		strcpy(buf, tok);
		check = filePath(buf, ex[0]);

		if(stat(check, &st) == 0)
			break;
	}
	if (execve(check, ex, NULL) == -1)
		perror("Error"); /** Check how error messages print */
}

char *filePath(char *path, char *command)
{
	struct stat st;
	strcat(path, "/");
	strcat(path, command);

	if(stat(path, &st) == 0)
		return (path);

	return (NULL);
}
