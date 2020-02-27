#ifndef holberton_h
#define holberton_h

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

/**
 * struct node - a node
 * that will store a string
 *
 * @str: The string value to store
 * @next: A pointer to the next node
 */
typedef struct node
{
	char *str;
	struct node *next;
} node_t;

/**
 * struct list - A linked list
 * with count of nodes
 *
 * @head: The head of the linked list
 * @tail: The tail of the linked list
 * @count: The number of nodes in the linked list
*/
typedef struct list
{
	struct node *head;
	struct node *tail;
	size_t count;
} list_t;

/**
 * struct args - a structure that
 * contains data of arguments and argument count
 *
 * @argv: An array of strings from the user
 * @count: The number of arguments made
 */
typedef struct args
{
	char **argv;
	size_t count;
} args_t;

/* builtInEnv.c */
void populateEnv(void);
list_t getEnvList(void);
void freeEnv(void);
void _setenv(char *key, char *value);
void _unsetenv(char *key);

/* builtins.c */
void _exit_(args_t args);
void printEnv(void);
int checkBuiltin(args_t args);

/* enviroment.c */
char *_getenv(char *name);
list_t listPath(void);

/* _execev.c */
void _execev(args_t args);
int checkCurrent(char *path);

/* filePath.c */
char *filePath(char *path, char *command);
char *newPath(char *key, char *symbol, char *value);

/* getInput.c */
args_t getArguments(void);
list_t tokLine(void);
args_t args(int status);
void token(char *input);

/* getPath.c */
void getPath(char **cmd);

/* linkedList.c */
node_t *makeNode(char *str);
void printLinkedList(list_t list);
void append(list_t *list, char *str);

/* main.c */
void _shell(void);

/* memory.c */
void freeList(list_t *list);
void freeArgv(char **argv);
void freeNode(node_t *tmp);
void freeArgs(args_t *arg);

/* signalHander.c */
void signal_handler(int sig __attribute__((unused)));

/* stringFunctions2.c */
int _strncmp(char *s1, char *s2, int len);
char *_strdup(char *str);
int _atoi(char *str);
int is_digit(char s);
int is_space(char s);

/* stringFunctions.c */
char *_strncpy(char *dest, char *src, int n);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);

/* stringFunctions3.c */
void _puts(char *str);
int isPositiveInt(char *str);
int _isdigit(int c);


int checkBuiltin2(args_t args);
char *getDir(args_t args);

int checkExec(args_t args);


#endif /* holberton_h */
