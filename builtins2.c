#include "holberton.h"

/**
 * checkBuiltin2 - helps set up the second
 * set of builtins, specially cd
 *
 * @args: The set of arguments from the user
 * Return: Returns 1 if build is was successfull,
 * else it returns 0
 */
int checkBuiltin2(args_t args)
{
	char *dir = NULL;
	char cwd[256];
	char oldcwd[256];
	char **argv = NULL;
	size_t size = 1000;

	argv = args.argv;
	if (args.count == 0)
		return (1);
	if (_strcmp(argv[0], "cd") == 0)
	{
		if (args.count == 1)
		{
			dir = _getenv("HOME");
		}
		else if (args.count == 2 && _strcmp(argv[1], "-") == 0)
		{
			dir = _getenv("HOME");
			_puts(dir);
		}
		else if (args.count == 2)
		{
			dir = argv[1];
		}
		getcwd(oldcwd, size);
		if (chdir(dir) == -1)
		{
			perror(dir);
			freeArgs(&args);
			return (1);
		}
		getcwd(cwd, size);
		_setenv("OLDPWD", oldcwd);
		_setenv("PWD", cwd);
		freeArgs(&args);
		return (1);
	}
	return (0);
}
