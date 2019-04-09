#include "holberton.h"
/**
 * main - Entry point of shell
 * @ac: argument counter
 * @argv: argument values
 * @envp: enviroments
 * Return: 0 if success
 */
int main(int ac, char *argv[], char *envp[])
{
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t bytes;
	char *prompt = "$jessiFer> ";

	write(1, prompt, 12);
	while ((bytes = getline(&lineptr, &n, stdin)) != -1)
	{
		if (bytes > 0)
		{
			lineptr = strtok(lineptr, " \n");
			while (lineptr != NULL)
			{
				printf("%s\n", lineptr);
				lineptr = strtok(NULL, " ");

			}
			write(STDOUT_FILENO, lineptr, bytes);
		}
		else if (bytes < 0)
		{
			write(STDOUT_FILENO, "Error\n", sizeof("Error\n"));
			exit(1);
		}
		write(1, prompt, 12);
	}
	return(0);
}
