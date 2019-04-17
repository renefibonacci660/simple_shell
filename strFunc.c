#include "holberton.h"

/**
 *_puts - Recived a string from str, uses _putchar
 * to print every character on the screen. With a new line after
 *
 *@str: The string that will be recived from
 */
void _puts(char *str)
{
	size_t len;

	len = strLen(str);
	write(1, str, len);
	write(1, "\n", 1);
}

/**
 *_strncmp - Compares two strings at a specified length
 *and returns the difference of both strings
 *@s1: A pointer to the address of the given string.
 *@s2: Another pointer to the adress of the given string.
 *@len: The length to compare the strings
 *Return: returns the difference of two ascii character values from the two
 *given strings
 */
int _strncmp(char *s1, char *s2, int len)
{
	int index;
	char let1;
	char let2;

	index = 0;
	let2 = '0';
	let1 = '0';
	while (s1[index] == s2[index] && s1[index] != '\0' && s1[index] != '0')
	{
		if (len - 1 == index)
			break;
		index++;
	}
	let1 = s1[index];
	let2 = s2[index];
	return (let1 - let2);
}

/**
 *_strcat - A function that concatenates both dest
 * and src strings.
 *
 *@dest: The string that we will append src to
 *
 *@src: The string that will be appended to dest
 *
 *Return: returns the pointer dest after being appended to src
 */
char *_strcat(char *dest, char *src)
{
	int destLen;
	int index;

	index = 0;
	destLen = strLen(dest);
	while (src[index] != '\0')
	{
		dest[index + destLen] = src[index];
		index++;
	}
	dest[destLen + index] = '\0';
	return (dest);
}


/**
 *strLen - Measures the string from pointer str.
 *
 *@str: The pointer the points to the adress of the given string.
 *
 *Return: returns the length of the given string.
 */
int strLen(char *str)
{
	int len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

/**
 *_strcpy - Contains a string from source, which
 *will then be copied to pointer dest. It will then
 *return the same pointer that points to dest
 *
 *@dest: The pointer that will copy the string from src
 *@src: The pointer that contain's the string's address
 *Return: Returns the pointer that points to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (src)
	{
		while (src[i] != '\0')
			i++;
		while (j <= i)
		{
			dest[j] = src[j];
			j++;
		}
	}
	return (dest);
}
