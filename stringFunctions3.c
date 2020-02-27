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
	write(1, "\n", 1);
}

/**
 *_isdigit - Checks if c has ascii value is of digit character
 *
 *@c: The ascii value to recieve and check if ascii
 * value is of digit character.
 *
 *Return: Returns 1 if c is a digit character. Otherwise
 *it returns 0.
 */
int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/**
 * isPositiveInt - checks if string is a positive integer
 *
 * @str: The string to verify for positive integer
 * Return: returns -1 if string is not a positive integer, else 0 for success
 */
int isPositiveInt(char *str)
{
	size_t index;

	for (index = 0; str[index] != '\0'; index += 1)
		if (_isdigit(str[index]) == 0)
			return (-1);
	return (0);
}
