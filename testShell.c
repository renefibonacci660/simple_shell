#include "holberton.h"

void print(char **str)
{
	size_t i;

	for (i = 0; str[i] != NULL; i++)
		printf("Args contains: %s\n", str[i]);
}

size_t countWords(char *str)
{
	size_t i, in;
	size_t wordCount;

	wordCount = 0;
	in = 1;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '\n' || str[i] == '\t' || str[i] == ' ')
			in = 0;
		else if (in == 0)
		{
			in = 1;
			wordCount++;
		}
	}
	return (wordCount + 1);
}

char **token(char *buff)
{
	char *tok;
	size_t i, wordCount;
	char **args;

	wordCount = countWords(buff);
	args = malloc(sizeof (char *) * wordCount + 1);
	if (args == NULL)
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

char *filePath(char *path, char *command)
{
        struct stat st;
	strcat(path, "/");
	strcat(path, command);
	if (stat(path, &st) == 0)
		return (path);
	return (NULL);
}

/*
char *pathCopy()
{
	char *path;

	for (i = 0; environ[i] != NULL; i++)
	{
		tok = strtok(environ[i], "=");
		if (strcmp(tok, 
	}
}
*/
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
		if (strcmp(tok, "PATH") == 0)
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
		if (stat(check, &st) == 0)
			break;
	}
	if (execve(check, ex, NULL) == -1)
		perror("Error");
}

int main()
{
	size_t size;
	int len;
	pid_t process;
	char *input;
	char **args;
	struct stat st;

	while (1)
	{
		if (isatty(0))
			printf("$ ");
		len = getline(&input, &size, stdin);
		if (len == EOF)
			break;
		input[len - 1] = '\0';
		args = token(input);
		process = fork();
		if (process == -1)
		{
			perror("Error:\n");
			return (1);
		}
		if (process == 0)
		{
			if (stat(args[0], &st) == 0)
			{
				if (execve(args[0], args, NULL) == -1)
					perror("Error: ");
			}
			else
				getPath(args);
		}
		else
		{
			wait(NULL);
			free(args);
		}
	}

}
