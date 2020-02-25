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

node_t *makeNode(char *str);
void freeList(list_t *list);
args_t token(char *input);
void freeArgv(char **argv);

void append(list_t *list, char *str);
args_t args(void);
char *_getenv(char *name);

char *filePath(char *path, char *command);
void printLinkedList(list_t list);
void printPath(void);

void _execev(args_t args);
void getPath(char **cmd);
list_t listPath(void);


char *_strncpy(char *dest, char *src, int n);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);


int _strncmp(char *s1, char *s2, int len);
char *_strdup(char *str);
int _atoi(char *str);
int is_digit(char s);
int is_space(char s);


void _exit_(int status);
void printEnv(void);
int checkBuiltin(args_t args);

void signal_handler(int sig __attribute__((unused)));
void _shell(void);

char *newPath(char *key, char *symbol, char *value);

void _puts(char *str);

int _setenv(const char *name, const char *value, int rewrite);
void _unsetenv(const char *name);

#endif /* holberton_h */
