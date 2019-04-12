#include "holberton.h"

void printError(char *str)
{
        size_t len;

        len = strLen(str);
        if (errno == ENOTDIR || errno == ENOENT)
        {
                write(2, str, len);
                write(2, ": Command not found\n", 20);
        }
}

void freeDoub(char **str)
{
        size_t i;

        for (i = 0; str[i] != NULL; i++)
                free(str[i]);
        free(str);
}

char **token(char *buff)
{
        char *tok = NULL;
        size_t i, wordCount, len;
        char **args = NULL;

        wordCount = countWords(buff);
        args = malloc(sizeof (char *) * wordCount + 1);
        if (args == NULL)
                return (NULL);
        i = 0;
        tok = strtok(buff, " ");
        while (tok != NULL)
        {
                len = strLen(tok);
                args[i] = malloc(sizeof(char) * len + 1);
                if (args[i] == NULL)
                        return (NULL);
                _strcpy(args[i], tok);
                i++;
                tok = strtok(NULL, " ");
        }
        args[i] = NULL;
        return (args);
}

char **getInput()
{
        char *input = NULL;
        char **args = NULL;
        size_t size;
        int len;

        len = getline(&input, &size, stdin);
        if (len == EOF)
        {
                free(input);
                return (NULL);
        }
        input[len - 1] = '\0';
        args = token(input);
        if (args == NULL)
                return (NULL);
        free(input);
        return (args);
}

void _shell()
{
	pid_t process;
        char **args;

	args = NULL;
        while (1)
        {
                if (isatty(0))
                        write(2, "$ ", 3);
                args = getInput();
                if (args == NULL)
                        exit(1);
                process = fork();
                if (process == -1)
                {
                        perror("Error:\n");
                        freeDoub(args);
                        exit(1);
                }
                if (process == 0)
                {
                        if (getPath(args) == NULL)
                        {
                                if (execve(args[0], args, NULL) == -1)
                                {
                                        printError(args[0]);
                                        freeDoub(args);
                                        exit(1);
                                }
                        }
                }
                else
                {
                        wait(NULL);
                        freeDoub(args);
                }
        }
        freeDoub(args);
}
