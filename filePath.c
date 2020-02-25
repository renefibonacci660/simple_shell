#include "holberton.h"

/**
 * filePath - concatenates path and command
 * and checks if the executable exist
 *
 * @path: The path from PATH
 * @command: The command that the user demands
 * Return: returns the path of the executable if found,
 * else it returns null
 */
char *filePath(char *path, char *command)
{
	struct stat st;
	char *newP = NULL;

	if (path == NULL || command == NULL)
		return (NULL);
	newP = newPath(path, "/", command);
	if (stat(newP, &st) == 0)
		return (newP);
	free(newP);
	return (NULL);
}

/**
 * newPath - Creates a full path by concatenating
 * three strings together
 *
 * @key: The key value to concatenate
 * @symbol: The symbol to concatenate with the key
 * @value: The value to concatenate with the key and symbol
 * Return: Returns a string with all three given values concatenated together
 */
char *newPath(char *key, char *symbol, char *value)
{
	int total = 0;
	char *newPath = NULL;

	if (key == NULL || symbol == NULL || value == NULL)
		return (NULL);
	total = _strlen(key) + _strlen(symbol) + _strlen(value) + 1;
	newPath = malloc(sizeof(char) * total);
	if (newPath == NULL)
		return (NULL);
	_strcpy(newPath, key);
	_strcat(newPath, symbol);
	_strcat(newPath, value);

	return (newPath);
}
