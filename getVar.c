#include "holberton.h"
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
