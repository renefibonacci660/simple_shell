#include "holberton.h"
/**
 *_shell - Creates and uses process to run specified functions.
 * Calls them in a similar way shell would
 */
void _shell(void)
{
	pid_t process;
	char **args;

	args = NULL;
	while (1)
	{
		if (isatty(0))
			write(2, "$ ", 3);
		args = getInput();
		if (args == NULL)
			continue;
		process = fork();
		if (process == -1)
		{
			perror("Error:\n");
			freeDoub(args);
			exit(1);
		}
		if (process == 0)
		{
			if (getPath(args) == NULL)
			{
				if (execve(args[0], args, NULL) == -1)
				{
					printError(args[0]);
					freeDoub(args);
					exit(1);
				}
			}
		}
		else
		{
			wait(NULL);
			freeDoub(args);
		}
	}
	freeDoub(args);
}
