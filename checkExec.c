#include "holberton.h"

/**
 * checkExec - checks if arguments are proper for executing
 *
 * @args: The arguments that need to be checked
 * Return: returns 0 if argument is executable, else it returns 2
 */
int checkExec(args_t args)
{
	struct stat st;
	char **argv = NULL;

	if (args.count == 0)
		return (0);
	argv = args.argv;
	if (_getenv("PATH=") == NULL)
	{
		if (argv[0][0] == '/' && stat(argv[0], &st) == 0)
		{
			return (0);
		}
		else
		{
			fprintf(stderr, "./hsh: 1: %s: not found\n", argv[0]);
			freeArgs(&args);
			return (127);
		}
	}
	if (checkCurrent(argv[0]) == 0)
	{
		getPath(&argv[0]);
	}
	if (stat(argv[0], &st) != 0)
	{
		fprintf(stderr, "./hsh: 1: %s: not found\n", argv[0]);
		freeArgs(&args);
		return (127);
	}
	return (0);
}
