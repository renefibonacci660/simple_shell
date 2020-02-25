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
	if (args.count == 0)
		return (1);
	if (_strcmp(argv[0], "env") == 0)
	{
		freeArgs(&args);
		printEnv();
		return (1);
	}
	else if (_strcmp(argv[0], "exit") == 0)
	{
		if (args.count >= 2)
			status = atoi(argv[1]);
		freeEnv();
		freeArgs(&args);
		_exit_(status);
	}
	else if (_strcmp(argv[0], "setenv") == 0)
	{
		if (count >= 3)
			_setenv(argv[1], argv[2]);
		freeArgs(&args);
		return (1);
	}
	else if (_strcmp(argv[0], "unsetenv") == 0)
	{
		if (count >= 2)
			_unsetenv(argv[1]);
		freeArgs(&args);
		return (1);
	}
	return (0);
}

/**
 *_exit_ - exits with status
 *
 * @status: The status choosen by the user to exit with
 */
void _exit_(int status)
{
	_exit(status);
}

/**
 * printEnv - prints the enviroment list
 */
void printEnv(void)
{
	node_t *node = NULL;
	list_t env = { NULL, NULL, 0 };

	env = getEnvList();
	node = env.head;
	for (node = env.head; node != NULL; node = node->next)
		_puts(node->str);
}
