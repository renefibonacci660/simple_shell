#include "holberton.h"

/**
 *checkCurrent - Checks for specified conditions to execute current directory
 *@path: The directories in path
 *Return: returns 1 if condition is true, else returns 0
 */
int checkCurrent(char *path)
{
	size_t i;

	for (i = 0; path[i] != '\0'; i++)
	{
		if (path[0] == ':')
			return (1);
		if (path[i] == ':' && path[i + 1] == ':')
		{
			if (_strncmp(&path[i + 2], "/bin:", 5) == 0)
				return (1);
		}
	}
	return (0);
}
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

	if (path == NULL || command == NULL)
		return (NULL);
	_strcat(path, "/");
	_strcat(path, command);
	if (stat(path, &st) == 0)
		return (path);
	return (NULL);
}

/**
 * getVar - Returns the directories contained in the variable "name"
 *@name: The variable to look for, ex. PATH
 *Return: returns the variable's directories
 */
char *getVar(char *name)
{
	char *thePath = NULL; /*All variable directories*/
	size_t i;
	int place;

	place = strLen(name);
	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strncmp(environ[i], name, place) == 0)
		{                /*The name in this case is PATH*/
			thePath = environ[i] + place + 1;
			break; /*Break to return the path*/
		}
	}
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
	size_t i;
	char *check = NULL;
	struct stat st;

	if (ex == NULL)
		return (NULL);
	thePath = getVar("PATH"); /*Recives the directories of PATH*/
	if (thePath == NULL) /*If variable was non existent*/
		thePath = "";
	if (checkCurrent(thePath) == 1)
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
		if (check != NULL && stat(check, &st) == 0)
		{
			if (execve(check, ex, NULL) == -1)
				return (NULL); /*If excutable failed*/
		}
		for (i = 0; i < 100; i++)
			buf[i] = 0;
	}
	return (NULL);
}
