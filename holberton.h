#ifndef ___HOLBERTON__
#define __HOLBERTON__

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;
void checking(char **args);
void freeDouble(char **db, size_t len);
size_t countWords(char *str);
char **token(char *buff);
char *filePath(char *path, char *command);
void getPath(char **ex);

#endif
