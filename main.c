#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
/**
 * 
 * 
 **/

int main(int argc, char *argv[], char *envp[])
{
	pid_t parent;
	pid_t child;
	int status;
	int command;
	char *buffer;
	size_t buffersize;
	char *argv1[] = {"", NULL};

	

	while(1)
	{
		printf("$ ");
		buffer = malloc(sizeof(char) * buffersize);
		command = getline(&buffer, &buffersize, stdin);
		buffer[command - 1] = '\0';
		//command will recive -1 if cntrl-d is used by user. ctrl-d is EOF/-1
		if (command == -1)
			break;
		child = fork();

		if (child == -1)
		{
			printf("Failure to create child\n");
			return (-1);
		}
		if (child == 0)
		{			
			if (!buffer)
				return (-1);
			if (execve(buffer, argv1, NULL) == -1)
				exit(98);
			sleep(2);
		}
		else
		{
			wait(&status);
			printf("We are the parent\n");
			free(buffer);
		}
	}
}
