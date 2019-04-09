#include "holberton.h"
/**
  *_getline - Delimited a string input
  *@lineptr: pointer the first char inout
  *@n: pointer to the size of lineptr
  *@fd: is 0 for stdin
  *Return: the length of input
 */
ssize_t _getline(char **lineptr, size_t *n, int fd)
{
	static char line[1024];
	char *ptr;
	unsigned int len;
	unsigned int i = 1024;

	if (lineptr == NULL || n == NULL)
	{
		return (-1);
	}
	read(fd, line, i);
	len = _strlen(line);
	if ((len + 1) < i)
	{
		ptr = realloc(*lineptr, i);
		if (ptr == NULL)
			return (-1);
		*lineptr = ptr;
		*n = i;
	}
	_strcpy(*lineptr, line);
return (len);
}
