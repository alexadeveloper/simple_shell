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
