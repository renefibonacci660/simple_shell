#include "holberton.h"

/**
 *countWords - Counts the amount of words in input
 *@str: The input to read the amount of words from
 *Return: returns the number of words counted
 */
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

/**
 *filePath - Concantenates path anc command to
 * check if it's an executable
 *@path: The path to check for executable
 *@command: The input command to attach to path
 *Return: If the concantenated path and command are
 *an executable, return it. Otherwise it will be NULL
 */
char *filePath(char *path, char *command)
{
	struct stat st;

	_strcat(path, "/");
	_strcat(path, command);
	if (stat(path, &st) == 0)
		return (path);
	return (NULL);
}

/**
 * getEnv - Creates a replicated copy of environ
 *Return: Returns the copy of the replicated environ
 */
char **getEnv(void)
{
	size_t i, len;
	char **env = NULL;

	for (i = 0; environ[i] != NULL; i++)
		;
	env = malloc(sizeof(char *) * i + 1);
	if (env == NULL)
		return (NULL);
	for (i = 0; environ[i] != NULL; i++)
	{
		len = strLen(environ[i]);
		env[i] = malloc(sizeof(char) * len + 1);
		if (env[i] == NULL)
			return (NULL);
		_strcpy(env[i], environ[i]);
	}
	env[i] = NULL;
	return (env);
}

/**
 * getVar - Returns the directories contained in the variable "name"
 *@name: The variable to look for, ex. PATH
 *Return: returns the variable's directories
 */
char *getVar(char *name)
{
	char **env = NULL; /*For duplicated environ*/
	char *thePath = NULL; /*All variable directories*/
	char *tok = NULL; /*The tokens from env*/
	size_t i;

	env = getEnv(); /*Get the duplicated environ*/
	for (i = 0; env[i] != NULL; i++)
	{
		tok = strtok(env[i], "="); /*Get the Variable name*/
		if (_strcmp(tok, name) == 0) /*Compare variable names*/
		{                /*The name in this case is PATH*/
			thePath = strtok(NULL, env[i]);
			break; /*Break to return the path*/
		}
	}
	freeDoub(env); /*Free duplicated environ*/
	return (thePath);
}

/**
 * getPath - Gets the tokenized input and attempts to find
 * the executable from PATH and executes it if found
 * @ex: The tokenized inptu
 * Return: If the input's excutable path was not found, return NULL
 */
char *getPath(char **ex)
{
	char *tok = NULL;
	char *thePath = NULL;
	char buf[100];
	char *check = NULL;
	struct stat st;

	thePath = getVar("PATH"); /*Recives the directories of PATH*/
	if (thePath == NULL) /*If variable was non existent*/
		thePath = "";
	if (thePath[0] == ':')
		if (stat(ex[0], &st) == 0)
			return (NULL);
	tok = strtok(thePath, ":"); /*Checks for all possiblie directories*/
	while (tok != NULL)
	{
		_strcpy(buf, tok);        /*Makes a copy of*/
		tok = strtok(NULL, ":");  /*to allow leave token alone*/
		if (tok == NULL)
			break;
		check = filePath(buf, ex[0]);
		if (stat(check, &st) == 0) /*If path is an excutable, proceed*/
		{
			if (execve(check, ex, NULL) == -1)
				return (NULL); /*If excutable failed*/
		}
	}
	return (NULL);
}
