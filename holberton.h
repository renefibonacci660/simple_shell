#ifndef __HOLBERTON__
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

/* checkCurrent.c */
int checkCurrent(char *path);

/* countWords.c */
size_t countWords(char *str);

/* getEnv.c */
char **getEnv();
void freeDoub(char **str);

/* getInput.c */
char **getInput();

/* getPath.c */
char *getPath(char **ex);
char *filePath(char *path, char *command);

/* getVar.c */
char *getVar(char *name);

/* main.c */
void _shell(void);

/* mainshell.c */
int main(void);

/* printEnv.c */
void printEnv(void);
void _exit_(void);

/* printError.c */
void printError(char *str);

/* signalHander.c */
void signal_handler(int sig __attribute__((unused)));

/* strFunc.c */
void _puts(char *str);
int _strncmp(char *s1, char *s2, int len);
char *_strcat(char *dest, char *src);
int strLen(char *str);
char *_strcpy(char *dest, char *src);

/* token.c */
char **token(char *input);

#endif
