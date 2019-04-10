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
