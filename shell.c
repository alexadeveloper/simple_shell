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
	return (0);
}
/**
 * myexec - Execute program
 * @exec_path: path to execute program
 * @args: arguments to execute
 * @env_args: enviroment variables
 * Return: retu if was successful or not
 */
int myexec(char *exec_path, char *args[], char *env_args[])
{
	pid_t pid;
	int wstatus = 0;

	pid = fork();
	if (pid == -1)
	{
		write(STDOUT_FILENO, "Error process\n", 14);
		return (-1);
	}
	else if (pid == 0)
	{
		if (execve(exec_path, args, env_args) == -1)
		{
			write(STDOUT_FILENO, "Error execv\n", 12);
			return (-1);
		}
	}
	else
	{
		waitpid(pid, &wstatus, 0);
	}
	return (0);
}
/**
 * str_concat - Duplicate string
 * @s1: string one
 * @s2: string two
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
