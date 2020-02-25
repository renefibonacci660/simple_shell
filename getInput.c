#include "holberton.h"

/**
 * token - tokenizes the input
 * and returns a double array of each token
 *
 * @input: The input that needs to be tokenized
 * Return: returns a double array with tokenized input
 */
args_t token(char *input)
{
	char *tok = NULL;
	node_t *node = NULL;
	size_t index = 0;
	list_t list = { NULL, NULL, 0 };
	args_t args = { NULL, 0 };

	if (input[0] == '\0')
		return (args);
	tok = strtok(input, " \t");
	while (tok != NULL)
	{
		append(&list, tok);
		tok = strtok(NULL, " \t");
	}
	if (list.count == 0)
		return (args);
	args.argv = malloc(sizeof(char *) * (list.count + 1));
	node = list.head;
	for (index = 0; index < list.count; index += 1)
	{
		args.argv[index] = _strdup(node->str);
		node = node->next;
	}
	args.argv[index] = NULL;
	args.count = list.count;
	freeList(&list);
	return (args);
}

/**
 * args - Recives input from user
 *
 * Return: returns a double array of input
 * with arguments
 */
args_t  args(void)
{
	int len;
	size_t size;
	char *input = NULL;
	args_t args = { NULL, 0 };

	len = size = 0;
	if (isatty(0))
		write(2, "$ ", 3);
	len = getline(&input, &size, stdin);
	if (len == EOF)
	{
		free(input);
		if (isatty(0))
			write(2, "\n", 1);
		exit(0);
	}
	if (input[len - 1] == '\n')
		input[len - 1] = '\0';
	args = token(input);
	free(input);
	return (args);
}
