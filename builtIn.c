#include "holberton.h"

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
 *_exit_ - exits with status 0
 */
void _exit_(void)
{
	exit(0);
}
