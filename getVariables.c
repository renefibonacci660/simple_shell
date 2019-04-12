#include "holberton.h"

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

char *filePath(char *path, char *command)
{
	struct stat st;
	_strcat(path, "/");
	_strcat(path, command);
	if (stat(path, &st) == 0)
		return (path);
	return (NULL);
}

char **getEnv()
{
	size_t i, len;
        char **env = NULL;

        for (i = 0; environ[i] != NULL; i++)
                ;
        env = malloc(sizeof(char *) * i + 1);
        if (env == NULL)
                return (NULL);
        for (i = 0; environ[i] != NULL; i++)
        {
		len = strLen(environ[i]);
		env[i] = malloc(sizeof(char) * len + 1);
		if (env[i] == NULL)
			return (NULL);
		_strcpy(env[i], environ[i]);
        }
        env[i] = NULL;
        return(env);
}


char *getVar(char *name)
{
        char **env = NULL;
        char *thePath = NULL;
        char *tok = NULL;
        size_t i;

        env = getEnv();
        for (i = 0; env[i] != NULL; i++)
        {
                tok = strtok(env[i], "=");
                if (_strcmp(tok, name) == 0)
                {
                        thePath = strtok(NULL, env[i]);
                        break;
                }
        }
        freeDoub(env);
        return (thePath);
}

char *getPath(char **ex)
{
        char *tok = NULL;
        char *thePath = NULL;
        char buf[100];
        char *check = NULL;
        struct stat st;

        thePath = getVar("PATH");
        if (thePath[0] == ':')
                return (NULL);
        tok = strtok(thePath, ":");
        while (tok != NULL)
        {
                _strcpy(buf, tok);
                tok = strtok(NULL, ":");
                if (tok == NULL)
                        break;
                check = filePath(buf, ex[0]);
                if (stat(check, &st) == 0)
                {
                        if (execve(check, ex, NULL) == -1)
                                perror(ex[0]);
                }
        }
        return (NULL);
}
