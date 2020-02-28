#include "holberton.h"

static args_t arguments;

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
	int status = 0;

	populateEnv();
	while (1)
	{
		status = argument();
		if (status == 1)
			continue;
		forkChild();
	}
	freeArgs(&arguments);
}

/**
 * argument - populates arguments that will be executed
 *
 * Return: returns 0 if argument is meant to be dealt with execve else
 * returns 1
 */
int argument(void)
{
	arguments = args(arguments.status);
	if (arguments.argv == NULL || checkBuiltin(arguments) == 1 ||
	    checkBuiltin2(arguments) == 1)
		return (1);
	arguments.status = checkExec(arguments);
	if (arguments.status == 127)
		return (1);
	return (0);
}

/**
 * forkChild - Forks a child to execute the argument
 */
void forkChild(void)
{
	pid_t process;

	process = fork();
	if (process == -1)
	{
		perror("Error:\n");
		freeArgs(&arguments);
		exit(1);
	}
	if (process == 0)
	{
		_execev(arguments);
	}
	else
	{
		wait(&arguments.status);
		freeArgs(&arguments);
	}
}
