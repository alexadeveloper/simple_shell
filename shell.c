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
	char *lineptr = NULL, *full_path = NULL;
	char interactive, *prompt = "$jessiFer> ", **myargv;
	size_t n = 0;
	ssize_t bytes;
	int bytes_path;

	interactive = isatty(STDIN_FILENO);
	if (interactive)
	{	write(1, prompt, 12);
		signal(SIGINT, sighandler);
		signal(EOF, sighandler); }
	while ((bytes = _getline(&lineptr, &n, 0)))
	{
		if (bytes > 0)
		{
			myargv = build_argv(lineptr);
			if (myargv && myargv[0] != NULL)
			{
				bytes_path = build_path(&full_path, myargv[0], envp);
				myexec(full_path, myargv, envp);
				if (bytes_path > 0)
				{	free(full_path);
					free(myargv); }
			}
		}
		else if (bytes < 0)
		{	
			write(STDOUT_FILENO, "Error\n", sizeof("Error\n"));
			exit(1);
		}
		else if (bytes == 0)
		{
			write(STDOUT_FILENO, "blah\n",5);
			free(lineptr);
			free(full_path);
		}
		if (interactive)
			write(1, prompt, 12);
		free(lineptr);
		lineptr = NULL;
		myargv = NULL;
		full_path = NULL;
	}
	return (0);
}
