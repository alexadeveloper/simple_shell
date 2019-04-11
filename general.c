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
		if (line[0] == 0)
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
/**
  *_strtok - extract tokens from strings
  *@ptr: the string
  *@delim: delimitador
  *Return: a pointer to the next token
 */
char *_strtok(char *ptr, const char *delim)
{
	static char    *t;
	char *r;
	int n;

	if (ptr)
		t = ptr;

	r = t + _strspn(t, delim, 1);
	n = _strspn(r, delim, 2);
	if (!n)
		return (0);
	t = r + n;
	if (*t)
		*t++ = 0;
	return (r);
}
/**
  *_strspn - find some char into a string
  *@p: the string to be scanned
  *@s: the characters to match in p
  *@opt: the option
  *Return: the number of characters in the initial segment of p
 */
int _strspn(const char *p, const char *s, int opt)
{
	int i, j;

	for (i = 0; p[i]; i++)
	{
		for (j = 0; s[j]; j++)
		{
			if (s[j] == p[i])
				break;
		}
		if (opt == 1)
		{
			if (!s[j])
				break;
		}
		if (opt == 2)
		{
			if (s[j])
				break;
		}
	}
	return (i);
}
/**
 * str_concat - Duplicate string
 * @s1: string one
 * @s2: string two
 * Return: pointer to copy array
 */
char *str_concat(char *s1, char *s2)
{
	char *p;
	unsigned int i;
	unsigned int size_s1, size_s2;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	for (size_s1 = 0; *(s1 + size_s1) && s1; size_s1++)
	{
	}
	for (size_s2 = 0; *(s2 + size_s2) && s2; size_s2++)
	{
	}
	p =  malloc(sizeof(char) * (size_s1 + size_s2 + 1));
	if (p == NULL)
		return (NULL);
	for (i = 0; i < size_s1 + size_s2; i++)
	{
		if (i < size_s1)
			p[i] = *(s1 + i);
		else
			p[i] = *(s2 + i - size_s1);
	}
	p[i] = '\0';
	return (p);
}
