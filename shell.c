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
	int bytes_path, c_prompt = 1;

	interactive = isatty(STDIN_FILENO);
	if (interactive)
	{	write(1, prompt, 12);
		signal(SIGINT, sighandler);
		signal(EOF, sighandler); }
	while ((bytes = getline(&lineptr, &n, stdin)))
	{
		if (bytes > 0)
		{
			myargv = build_argv(lineptr);
			if (myargv && myargv[0] != NULL)
			{
				bytes_path = build_path(c_prompt, &full_path, myargv[0], envp);
				myexec(lineptr, full_path, myargv, envp);
				free(full_path);
			}
			free(myargv);
		}
		else if (bytes < 0)
		{
			free(lineptr);
			exit(1);
		}
		if (interactive)
			write(1, prompt, 12);
		free(lineptr);
		lineptr = NULL;
		myargv = NULL;
		full_path = NULL;
		c_prompt++;
	}
	return (0);
}
