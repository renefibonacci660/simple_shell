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
	size_t count;
	char **argv = NULL;

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
		_exit_(args);
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
 * @args: The argument that will contain the staus for exit
 */
void _exit_(args_t args)
{
	if (args.count >= 2)
	{
		if (isPositiveInt(args.argv[1]) == -1)
		{
			fprintf(stderr, "./hsh: 1: exit: Illegal number: %s\n", args.argv[1]);
			args.status = 2;
		}
		else
		{
			args.status = _atoi(args.argv[1]);
		}
	}
	if (args.status == 512)
		args.status = 2;
	freeEnv();
	freeArgs(&args);
	exit(args.status);
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
