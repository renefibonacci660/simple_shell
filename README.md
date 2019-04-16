# Simple Shell


## Description
This is a version of a simple shell that utilizes a built UNIX command line interpreter that is able to handle command lines with arguments, execute commands found in the PATH as well as preforms the built-ins exit and env. All input in obtained from stdin and written to stdout.

## Formatting and Examples

Format for user to place in standard input:
command argument

Examples:

/$ ls -lamp
./, ../, .git/, README.md, a.out, countWords.c, getEnv.c, getPath.c, holberton.h 
holberton.h.gch, main.c, mainshell.c, testfolder/, token.c 
/$ 
-----------------------------------------------------------
/$ echo please work
please work
/$ 
-----------------------------------------------------------
/$ tail -3 test.c
These are the
last
three lines of this file
/$ 
-----------------------------------------------------------

## File List

| File Name | Description |
| --- | --- |
| README.md | Provides detailes regarding functionality and creation of (present file) |
| countWords.c | Counts number of words from input string |
| getEnv.c | Gets the environ so we can check for PATH and frees double pointer |
| getPath.c | Finds the executable PATH and finds file path |
| main.c | Runs a copy of shell and determines functionality |
| mainshell.c | Main entrance and exit function |
| token.c | Tokenizes input |
| holberton.h | Header file; contains libaries and function protoypes |

## Compilation
All files where compiled on Ubuntu 14.04 LTS.

All programs and functions were compiled with gcc 4.8.4 using flags -Wall -Werror -Wextra and -pedantic.

## Styling
All files have been written in the Betty Style for a cohesive and readable format.

## Authors
* **Brittney Goertzen** - [renefibonacci660](https://github.com/renefibonacci660)
* **George Solorio** - [GeorgeSolorio](https://github.com/GeorgeSolorio)