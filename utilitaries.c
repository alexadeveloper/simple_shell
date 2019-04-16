#include "holberton.h"
/**
 *not_found_command - print comand not found
 *@count: quantity of prompts printed
 *@argv_0: command not found
 */
void not_found_command(int count, char *argv_0)
{
	write(STDOUT_FILENO, argv_0, _strlen(argv_0));
	write(STDOUT_FILENO, ": ", 2);
	print_number(count);
	write(STDOUT_FILENO, ": command not found\n", 20);
}
/**
  *not_found_path - print comand not found
  *@count: quantity of prompts printed
  *@argv_0: command not found
 */
void not_found_path(int count, char *argv_0)
{
	write(STDERR_FILENO, "./hsh", 5);
	write(STDERR_FILENO, ": ", 2);
	print_number_error(count);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, argv_0, _strlen(argv_0));
	write(STDERR_FILENO, ": not found\n", 12);
}
/**
  *read_file - Read a file
  *@filename: the name of the file
  *Return: stdout the content of the file
 */
ssize_t read_file(const char *filename)
{
	char *new;
	int abrir;
	ssize_t leer;
	ssize_t escribir;
	int letters = 1024;

	if (filename == NULL)
		return (0);
	abrir = open(filename, O_RDONLY);
	if (abrir == -1)
	{
		return (0);
	}
	new = malloc(sizeof(char) * letters);
	if (new == NULL)
		return (0);
	while ((leer = read(abrir, new, letters)) > 0)
	{
		escribir = write(STDOUT_FILENO, new, leer);
		if (escribir == -1)
		{
			free(new);
			close(abrir);
			return (0);
		}
		free(new);
		new = malloc(sizeof(char) * letters);
		if (new == NULL)
			return (0);
	}
	if (leer == -1)
	{
		free(new);
		close(abrir);
		return (0);
	}
	free(new);
	close(abrir);
	return (escribir);
}
/**
  *str_copy_index - Copy from 0 to index
  *@original: original string
  *@index: index las position
  * Return: pointer to copy array
 */

char *str_copy_index(char *original, int index)
{
	char *p;
	int i;
	int size_s1;

	if (original == NULL)
		original = "";
	for (size_s1 = 0; *(original + size_s1) && original; size_s1++)
	{
	}
	p =  malloc(sizeof(char) * (index + 2));
	if (p == NULL)
		return (NULL);
	for (i = 0; i <= index; i++)
	{
		if (i < size_s1)
			p[i] = *(original + i);
		else
			p[i] = '\0';
	}
	p[i] = '\0';
	return (p);
}
/**
 * get_index_last_char - find last character
 * @string: string to evaluate
 * @find: char to compare
 * Return: index last char matched -1 if not
 */
int get_index_last_char(char *string, char find)
{
	int index = 0, last_index = -1;

	while (string[index])
	{
		if (string[index] == find)
		{
			last_index = index;
			if (string[index +  1] == '.')
			{
				break;
			}
		}
		index++;
	}
	return (last_index);
}
