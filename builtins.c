#include "holberton.h"

/**
 * checkBuiltin - checks if arguments match
 * to execute builins
 *
 * @args: An array of strings containing input from the user
 * Return: Returns 1 if argument is made for builtin, else
 * it returns 0
 */
int checkBuiltin(args_t args)
{
	int status;
	size_t count;
	char **argv = NULL;

	status = 0;
	argv = args.argv;
	count = args.count;
	if (_strcmp(argv[0], "env") == 0 && count == 1)
	{
		freeArgv(argv);
		printEnv();
		return (1);
	}
	else if (_strcmp(argv[0], "exit") == 0)
	{
		if (args.count >= 2)
			status = atoi(argv[1]);
		freeArgv(argv);
		_exit_(status);
	}
	return (0);
}

/**
 *printEnv - prints the enviroments
 */
void printEnv(void)
{
	size_t i;

	for (i = 0; environ[i] != NULL; i++)
		_puts(environ[i]);
}

/**
 *_exit_ - exits with status
 *
 * @status: The status choosen by the user to exit with
 */
void _exit_(int status)
{
	exit(status);
}
