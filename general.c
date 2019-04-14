#include "holberton.h"
/**
  *_getline - Delimited a string input
  *@lineptr: pointer the first char inout
  *@n: pointer to the size of lineptr
  *@fd: is 0 for stdin
  *Return: the length of input
 */
ssize_t _getline(char **lineptr, size_t *n, int fd)
{
	char line[1024] = {0};
	char *ptr = NULL;
	unsigned int len = 0;
	unsigned int i = 1024;

	if (lineptr == NULL || n == NULL)
	{
		return (-1);
	}
	read(fd, line, i);
	len = _strlen(line);
	if ((len + 1) < i)
	{
		if (line[0] == 0)
		{
			return (-1);
		}
		ptr = malloc(sizeof(char) * len);
		if (ptr == NULL)
			return (-1);
		*lineptr = ptr;
		*n = i;
	}
	_strcpy(*lineptr, line);
	return (len);
}
/**
  *_strtok - extract tokens from strings
  *@ptr: the string
  *@delim: delimitador
  *Return: a pointer to the next token
 */
char *_strtok(char *ptr, const char *delim)
{
	static char    *t;
	char *r;
	int n;

	if (ptr)
		t = ptr;

	r = t + _strspn(t, delim, 1);
	n = _strspn(r, delim, 2);
	if (!n)
		return (0);
	t = r + n;
	if (*t)
		*t++ = 0;
	return (r);
}
/**
  *_strspn - find some char into a string
  *@p: the string to be scanned
  *@s: the characters to match in p
  *@opt: the option
  *Return: the number of characters in the initial segment of p
 */
int _strspn(const char *p, const char *s, int opt)
{
	int i, j;

	for (i = 0; p[i]; i++)
	{
		for (j = 0; s[j]; j++)
		{
			if (s[j] == p[i])
				break;
		}
		if (opt == 1)
		{
			if (!s[j])
				break;
		}
		if (opt == 2)
		{
			if (s[j])
				break;
		}
	}
	return (i);
}
/**
 *get_value_env - find the value of enviroment variable
 *@envp: enviroment variables
 *@variable: variable to search
 *Return: pointer start on value of variable
*/
char *get_value_env(char **envp, char *variable)
{
	unsigned int envp_i = 0, variable_i = 0;
	char flag;

	while (envp[envp_i])
	{
		flag = 1;
		while (variable[variable_i] && flag)
		{
			if (envp[envp_i][variable_i] != variable[variable_i])
				flag = 0;
			variable_i++;
		}
		if (flag)
		{
			return (&envp[envp_i][variable_i + 1]);
		}
		variable_i = 0;
		envp_i++;
	}
	return (NULL);
}
/**
 *myexec - Execute program
 *@line_ptr: current line
 *@exec_path: path to execute program
 *@args: arguments to execute
 *@env_args: enviroment variables
 *Return: retu if was successful or not
*/
int myexec(char *line_ptr, char *exec_path, char *args[], char *env_args[])
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
			if (exec_path[0])
				perror(args[0]);
			free(args);
			free(exec_path);
			free(line_ptr);
			exit(-1);
		}
	}
	else
	{
		waitpid(pid, &wstatus, 0);
	}
	printf("el status es: %d\n", wstatus);
	return (wstatus);
}
