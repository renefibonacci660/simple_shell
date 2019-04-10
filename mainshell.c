#include "holberton.h"

int main()
{
	size_t size;
	int len;
	pid_t process;
	char *input;
	char **args;
	struct stat st;

	while(1)
	{
		if (isatty(0))
			printf("$ ");

		len = getline(&input, &size, stdin);

		if(len == EOF)
			break;

		input[len - 1] = '\0'; /** test whether needed because token later */
		args = token(input);
		process = fork();
		
		if (process == -1)
		{
			perror("Error:\n");
			return (1);
		}

		if (process == 0)
		{
			if (stat(args[0], &st) == 0)
			{
				if (execve(args[0], args, NULL) == -1)
					perror("Error: ");
			}
			else
			{
					getPath(args);
			}
		}
		else
		{
			wait(NULL);
			free(args);
		}
	}
}
