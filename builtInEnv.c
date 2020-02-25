#include "holberton.h"

static char *_findenv();

/**
 * _setenv - Sets a variable value from the user
 *
 * @name: The name of the variable to overwrite or append
 * @value: The value to give to the enviromental variable
 * @rewrite: The status that will indicate if variable is to be rewritten
 * Return: Returns 0 if successful, else it return -1
 */
int _setenv(const char *name, const char *value, int rewrite)
{
	static int alloced;			/* if allocated space before */
	char *C;
	int l_value, offset;

	if (*value == '=')			/* no `=' in value */
		++value;
	l_value = _strlen((char *)value);
	C = _findenv((char *)name, &offset);
	if (C)
	{
		if (!rewrite)
			return (0);
		if (_strlen(C) >= l_value)  /* old larger; copy over */
		{
			while (C)
			{
				*C++ = *value++;
			}
			return (0);
		}
	}
	else
	{				/* create new slot */
		int	cnt;
		char	**P;

		for (P = environ, cnt = 0; *P; ++P, ++cnt)
			;
		if (alloced)
		{			/* just increase size */
			environ = (char **)realloc((char *)environ,
			    (size_t)(sizeof(char *) * (cnt + 2)));
			if (!environ)
				return (-1);
		}
		else
		{				/* get new space */
			alloced = 1;		/* copy old entries into it */
			P = (char **)malloc((size_t)(sizeof(char *) *
			    (cnt + 2)));
			if (!P)
				return (-1);
			bcopy(environ, P, cnt * sizeof(char *));
			environ = P;
		}
		environ[cnt + 1] = NULL;
		offset = cnt;
	}
	for (C = (char *)name; *C && *C != '='; ++C)
		;	/* no `=' in name */
	environ[offset] =  malloc((size_t)((int)(C - name) + l_value + 2));
	if (!environ)
		return (-1);
	for (C = environ[offset]; (*C = *name++) && *C != '='; ++C)
		;
	for (*C++ = '='; (*C++ = *value++); )
		;
	return (0);
}

/**
 * _unsetenv - removes a variable from the enviroment
 *
 * @name: The enviromental variable to remove
 */
void _unsetenv(const char *name)
{
	char **P;
	int offset;

	while (_findenv((char *)name, &offset)) /* if set multiple times */
	{
		for (P = &environ[offset];; ++P)
		{
			*P = *(P + 1);
			if (!(*P))
				break;
		}
	}
}

/**
 * _findenv - looks for the enviromental
 *
 * @name: The name of the enviromental variable to find
 * @offset: The memory spot
 * Return: returns the found enviromental variable
 */
static char *_findenv(char *name, int *offset)
{
	int len;
	char **P, *C;

	for (C = name, len = 0; *C && *C != '='; ++C, ++len)
		;
	for (P = environ; *P; ++P)
	{
		if (!_strncmp(*P, name, len))
		{
			C = *P + len;
			if (*C == '=')
			{
				*offset = (P - environ);
				return (++C);
			}
		}
	}
	return (NULL);
}
