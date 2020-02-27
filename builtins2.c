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
	char cwd[1000];
	char **argv = NULL;

	argv = args.argv;
	if (args.count == 0)
		return (1);
	if (_strcmp(argv[0], "cd") == 0)
	{
		dir = getDir(args);
		if (dir == NULL || dir[0] == '\0')
		{
			freeArgs(&args);
			return (1);
		}
		if (chdir(dir) == -1)
		{
			fprintf(stderr, "./hsh: 1: cd: can't cd to %s\n", dir);
			freeArgs(&args);
			return (1);
		}
		_setenv("OLDPWD", _getenv("PWD"));
		_setenv("PWD", getcwd(cwd, 1000));
		freeArgs(&args);
		return (1);
	}
	return (0);
}

/**
 * getDir - gets directory info for cd
 *
 * @args: The arguments to check
 * Return: Returns a directory that chdir can handle, else NULL
 */
char *getDir(args_t args)
{
	char *dir = NULL;

	if (args.count == 1)
		dir = _getenv("HOME");
	else if (args.count >= 2)
	{
		if (_strcmp(args.argv[1], "-") == 0)
		{
			if (_getenv("OLDPWD") == NULL)
				_setenv("OLDPWD", _getenv("PWD"));
			dir = _getenv("OLDPWD");
			_puts(dir);
			return (dir);
		}
		dir = args.argv[1];
	}
	return (dir);
}
