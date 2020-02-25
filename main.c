#include "holberton.h"

/**
 * main - handles singals and runs the shell program
 *
 * Return: returns 0 when successful
 */
int main(void)
{
	signal(SIGINT, signal_handler);
	_shell();
	return (0);
}

/**
 * _shell - The main shell program
 */
void _shell(void)
{
	pid_t process;
	args_t arguments = { NULL, 0 };

	while (1)
	{
		arguments = args();
		if (arguments.argv == NULL || checkBuiltin(arguments) == 1)
			continue;
		process = fork();
		if (process == -1)
		{
			perror("Error:\n");
			freeArgv(arguments.argv);
			exit(1);
		}
		if (process == 0)
		{
			_execev(arguments);
		}
		else
		{
			wait(NULL);
			freeArgv(arguments.argv);
		}
	}
	freeArgv(arguments.argv);
}
