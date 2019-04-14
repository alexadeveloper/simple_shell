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
  *read_file - Read a file
  *@filename: the name of the file
  *@letters: cant of letters
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
	new = malloc(sizeof(char) * letters);
	if (new == NULL)
		return (0);
	abrir = open(filename, O_RDONLY);
	if (abrir == -1)
	{
		free(new);
		return (0);
	}
	leer = read(abrir, new, letters);
	if (leer == -1)
	{
		free(new);
		close(abrir);
		return (0);
	}
	escribir = write(STDOUT_FILENO, new, leer);
	if (escribir == -1)
	{
		free(new);
		close(abrir);
		return (0);
	}
	close(abrir);
	free(new);
	return (escribir);
}
