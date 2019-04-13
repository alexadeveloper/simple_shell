#include "holberton.h"
/**
 * _strcpy - function copy the string pointed
 * @dest: destination pointer
 * @src: source ponter
 * Return: destination pointer
 */
char *_strcpy(char *dest, char *src)
{
	int cont = 0;

	do {
		*(dest + cont) = *(src + cont);
		cont++;
	} while (*(src + cont - 1) != '\0');
	return (dest);
}
/**
 * _strlen - Calculate size of string
 * @s: string to becalculated
 * Return: size of string
 */
int _strlen(char *s)
{
	int cont = 0;

	while (*(s + cont) != '\0')
		cont++;
	return (cont);
}
/**
  *str_concat - Duplicate string
  *@s1: string one
  *@s2: string two
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
