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
	char line[1024] = {0};
	char *ptr = NULL;
	unsigned int len = 0;
	unsigned int i = 1024;

	if (lineptr == NULL || n == NULL)
	{
		return (-1);
	}
	read(fd, line, i);
	len = _strlen(line);
	if ((len + 1) < i)
	{
		if(line[0] == 0)
		{
			return (-1);
		}
		ptr = malloc(sizeof(char) * len);
		if (ptr == NULL)
			return (-1);
		*lineptr = ptr;
		*n = i;
	}
	_strcpy(*lineptr, line);
	return (len);
}
char *_strtok(char *ptr, const char *delim)
{
	static char    *t;
	char *r;
	int n;

	if (ptr)
		t = ptr;

	r = t + _strspn(t, delim);
	n = _strcspn(r, delim);
	if (!n)
		return (0);
	t = r + n;
	if (*t)
		*t++ = 0;
	return (r);
}
int _strspn(const char *p, const char *s)
{
	int i, j;

	for (i = 0; p[i]; i++)
	{
		for (j = 0; s[j]; j++)
		{
			if (s[j] == p[i])
				break;
		}
		if (!s[j])
			break;
	}
	return (i);
}
int _strcspn(const char *p, const char *s)
{
	int i, j;

	for (i = 0; p[i]; i++)
	{
		for (j = 0; s[j]; j++)
		{
			if (s[j] == p[i])
				break;
		}
		if (s[j])
			break;
	}
	return (i);
}
