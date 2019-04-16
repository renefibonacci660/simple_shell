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
