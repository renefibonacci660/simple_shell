#include "holberton.h"

/**
 *_puts - Recived a string from str, uses _putchar
 * to print every character on the screen. With a new line after
 *
 *@str: The string that will be recived from
 */
void _puts(char *str)
{
	int strLen;

	strLen = _strlen(str);
	write(1, str, strLen);
	write(1, "\n", 2);
}
