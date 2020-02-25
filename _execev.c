#include "holberton.h"

/**
 * checkCurrent - checks if path requires the
 * executable to be executed in the current path
 *
 * @path: The path to read for signs of current path
 * Return: returns 1 if signs have been found, else 0
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
			if (strncmp(&path[i + 2], "/bin:", 5) == 0)
				return (1);
		}
	}
	return (0);
}

/**
 * _execev - executes arguemnts from argv
 *
 * @args: The arguments to execute
 */
void _execev(args_t args)
{
	char **argv;

	argv = args.argv;
	if (checkCurrent(argv[0]) == 0)
		getPath(&argv[0]);
	if (execve(argv[0], argv, NULL) == -1)
	{
		perror(argv[0]);
		freeArgs(&args);
		exit(1);
	}
}
