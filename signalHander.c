#include "holberton.h"
/**
 *signal_handler - When cntrl-c is used, it will
 * reset the buffer
 *@sig: The sig to recieve from SIGINT
 */
void signal_handler(int sig __attribute__((unused)))
{
	signal(SIGINT, signal_handler);
	write(2, "\n", 2);
	write(2, "$ ", 3);
	fflush(stdout);
}
