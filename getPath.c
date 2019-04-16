#include "holberton.h"
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

/**
 *filePath - Concatenates path and command to
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
