#include "holberton.h"

/**
 *_strncpy - The function copies the string pointed to src, including the null
 *terminator, to the buffer pointed to by dest. It copies at most n byes of src
 *
 *@dest: The pointer to the given string's address
 *@src: The pointer to the given string's address
 *@n: The first n bytes of src
 *Return: It returns the pointer to the destination string dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		if (src[i] != '\0')
			dest[i] = src[i];
		else
			while (i < n)
				dest[i++] = '\0';
		i++;
	}
	return (dest);
}

/**
 *_strcmp - Compares two strings and returns the difference of both strings
 *
 *@s1: A pointer to the address of the given string.
 *@s2: Another pointer to the adress of the given string.
 *Return: returns the difference of two ascii character values from the two
 *given strings
 */
int _strcmp(char *s1, char *s2)
{
	int index;
	char let1;
	char let2;

	index = 0;
	let2 = '0';
	let1 = '0';
	while (s1[index] == s2[index] && s1[index] != '\0' && s1[index] != '\0')
		index++;
	let1 = s1[index];
	let2 = s2[index];
	return (let1 - let2);
}

/**
 *_strcat - A function that concatenates both dest
 * and src strings.
 *
 *@dest: The string that we will append src to
 *@src: The string that will be appended to dest
 *Return: returns the pointer dest after being appended to src
 */
char *_strcat(char *dest, char *src)
{
	int destLen;
	int index;

	index = 0;
	destLen = _strlen(dest);
	while (src[index] != '\0')
	{
		dest[index + destLen] = src[index];
		index++;
	}
	dest[destLen + index] = '\0';
	return (dest);
}

/**
 *_strlen - Takes in a string and counts
 * the string length of s.
 *
 *@s: The string that will be recived and counted
 *Return: Returns the string length of s
 */
int _strlen(char *s)
{
	int len;

	len = 0;
	while (s[len] != '\0')
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
	int i, j;

	if (src != NULL)
	{
		i = _strlen(src);
		for (j = 0; j <= i; j++)
			dest[j] = src[j];
	}
	return (dest);
}
