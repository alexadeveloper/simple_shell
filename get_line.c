#include "holberton.h"

int main()
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
			write(STDOUT_FILENO, lineptr, bytes);
			write(1, prompt, 12);
		}
		else if (bytes < 0)
		{
			write(STDOUT_FILENO, "Error\n", sizeof("Error\n"));
			exit(1);
		}
	}
	return (0);
}
