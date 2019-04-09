#include "holberton.h"

int main()
{
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t bytes;
	char *prompt = "$jessiFer> ";

	write(1, prompt, 12);
	while ((bytes =_getline(&lineptr, &n, stdin)) != -1)
	{
		if (bytes > 0)
		{
			if(bytes != 1 || lineptr[0] != '\n')
				write(STDOUT_FILENO, lineptr, bytes);
		}
		else if (bytes < 0)
		{
			write(STDOUT_FILENO, "Error\n", sizeof("Error\n"));
			exit(1);
		}
		write(1, prompt, 12);
	}
	return (0);
}
