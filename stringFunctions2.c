#include "holberton.h"

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
 *_strdup - This function recives a string and adds the
 *string value into and allocated string. Later returning
 *the allocated string's address
 *
 *@str:A pointer to the string to copy from
 *Return: returns the address of the newly and copied allocated string
 */
char *_strdup(char *str)
{
	char *ret;
	int strLen, i;

	if (str == NULL)
		return (NULL);
	strLen = _strlen(str) + 1;
	ret = malloc(strLen * sizeof(char));
	if (ret == NULL)
		return (NULL);
	for (i = 0; i < strLen; i++)
		ret[i] = str[i];
	return (ret);
}


/**
 *is_space - Will check if given character is of whitespce ascii value
 *
 *@s: The character to recive and check for whitespace value
 *Return: returns 1 if its a while space, else it returns a 0
 */
int is_space(char s)
{
	if (s == ' ' || s == '\t' || s == '\n'
	    || s == '\r' || s == '\v' || s == '\f')
		return (1);
	return (0);
}

/**
 *is_digit - Will check if given character is of digit ascii value
 *
 *@s: The character to recieve and check for digit value
 *
 *Return: returns 1 if character has digit value, else it returns 0
 */
int is_digit(char s)
{
	if (s >= '0' && s <= '9')
		return (1);
	return (0);
}

/**
 *_atoi - Recives a string and stores numbers into integers
 *
 *@str: The string to recive from and scan for any given numbers
 *Return: returns the integer from the string str
 */
int _atoi(char *str)
{
	int num;
	int sign;
	int i;

	i = 0;
	num = 0;
	sign = 1;
	if (!str)
		return (0);
	while (is_digit(str[i]) == 0 && str[i] != '\0' && i <= 2147483647)
		i++;
	if (str[i - 1] == '-' && is_space(str[i - 2]) != 1)
		sign = -1;
	while (is_digit(str[i]) && str[i] != '\0')
	{
		num = 10 * num + (str[i] - '0');
		if (i <= 2147483647)
			i++;
	}
	return (sign * num);
}
