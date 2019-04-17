#include "holberton.h"

/**
 *main - runs the shell program
 *Return: returns 0 if successfull
 */
int main(void)
{
	signal(SIGINT, signal_handler);
	_shell();
	return (0);
}
