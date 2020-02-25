#include "holberton.h"

static list_t line;

/**
 * getArguments - makes a struct of arguments from the the data of sublist
 *
 * Return: returns a struct from sublist data
 */
args_t getArguments(void)
{
	size_t index;
	args_t args = { NULL, 0 };
	node_t *node = NULL;
	list_t list = { NULL, NULL, 0 };

	list = tokLine();
	node = list.head;
	if (list.count == 0 || node == NULL)
		return (args);
	args.argv = malloc(sizeof(char *) * (list.count + 1));
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
 * tokLine - tokenizes the string with spaces and stabs and creates a list
 *
 * Return: returns a list of tokenized values
 */
list_t tokLine(void)
{
	node_t *node = NULL;
	char *tok = NULL;
	list_t list = { NULL, NULL, 0 };

	node = line.head;
	if (line.head != NULL && line.count > 0)
	{
		line.head = line.head->next;
		line.count -= 1;
		tok = strtok(node->str, " \t");
		while (tok != NULL)
		{
			if (_strcmp(tok, "#") == 0 || tok[0] == '#')
				break;
			append(&list, tok);
			tok = strtok(NULL, " \t");
		}
		freeNode(node);
	}
	return (list);
}

/**
 * token - tokenizes the input
 * and returns a double array of each token
 *
 * @input: The input that needs to be tokenized
 */
void token(char *input)
{
	char *tok = NULL;

	if (input[0] == '\0')
		return;
	tok = strtok(input, ";");
	while (tok != NULL)
	{
		append(&line, tok);
		tok = strtok(NULL, ";");
	}
}

/**
 * args - Recives input from user
 *
 * Return: returns a double array of input with arguments
 */
args_t  args(void)
{
	int len;
	size_t size;
	char *input = NULL;
	args_t args = { NULL, 0 };

	len = size = 0;
	if (line.count != 0)
	{
		args = getArguments();
		return (args);
	}
	if (isatty(0))
		write(2, "$ ", 3);
	len = getline(&input, &size, stdin);
	if (len == EOF)
	{
		free(input);
		freeList(&line);
		freeEnv();
		if (isatty(0))
			write(2, "\n", 1);
		exit(0);
	}
	if (input[len - 1] == '\n')
		input[len - 1] = '\0';
	token(input);
	free(input);
	args = getArguments();
	return (args);
}
