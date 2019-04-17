#include "holberton.h"

/**
 *printError - prints errors in shell format
 *@str: The command that will be printed in the error
*/
void printError(char *str)
{
	size_t len;

	len = strLen(str); /*errno is a number that is assigned my erros*/
	if (errno == ENOENT)
	{
		write(2, str, len);
		write(2, ": Command not found\n", 20);
	}
}
