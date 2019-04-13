#ifndef ___HOLBERTON__
#define __HOLBERTON__

#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

extern char **environ;

/*----------------main.c-----------------*/
void sign(int signal);
void signal_handler(int sig __attribute__((unused)));

/*----------------shell.c----------------*/
void freeDoub(char **str);
char **token(char *buff);
void printError(char *str);
char **getInput();
void _shell();

/*-------------getVariables.c--------------*/
char *filePath(char *path, char *command);
char *getPath(char **ex);
char *getVar(char *name);
size_t countWords(char *str);
char **getEnv(void);

/*------------strFunc.c------------------*/
int _strcmp(char *s1, char *s2);
int strLen(char *str);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);

#endif
