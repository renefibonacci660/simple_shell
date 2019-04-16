#include "holberton.h"
/**
 *countWords - Counts the amount of words in input
 *@str: The input to read the amount of words from
 *Return: returns the number of words counted
 */
size_t countWords(char *str)
{
	size_t i, in;
	size_t wordCount;

	wordCount = 0;
	in = 1;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '\n' || str[i] == '\t' || str[i] == ' ')
			in = 0;
		else if (in == 0)
		{
			in = 1;
			wordCount++;
		}
	}
	return (wordCount + 1);
}
