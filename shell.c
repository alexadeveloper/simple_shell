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
	char *lineptr = NULL, *full_path = NULL, interactive;
	size_t n = 0;
	ssize_t bytes;
	char *prompt = "$jessiFer> ", **myargv;
	int bytes_path;


	interactive = isatty(STDIN_FILENO);
	if(interactive)
	{
		write(1, prompt, 12);
		signal(SIGINT, sighandler);
		signal(EOF, sighandler);
	}
	while ((bytes = _getline(&lineptr, &n, 0)))
	{
		if (bytes > 0)
		{
			myargv = build_argv(lineptr);
			if(myargv && myargv[0] != NULL)
			{
				bytes_path = build_path(&full_path,myargv[0], envp);
				myexec(full_path, myargv, envp);
				if (bytes_path > 0)
				{
					free(full_path);
					free(myargv);
				}
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
		if(interactive)
			write(1, prompt, 12);
	       	free(lineptr);
		lineptr = NULL;
		myargv = NULL;
		full_path = NULL;

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
//			free(exec_path);
			free(args);
			write(STDOUT_FILENO, "Error execv\n", 12);
			exit (-1);
		}
	}
	else
	{
		waitpid(pid, &wstatus, 0);
	}
	return (0);
}
/**
 * get_value_env - find the value of enviroment variable
 * @envp: enviroment variables
 * @variable: variable to search
 * Return: pointer start on value of variable
 *
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
 * build_path - fin path to execute
 * @path: comand to execute
 * Return: Pointer with the value of full path
 */
int build_path(char **full_path, char *argv_0, char *envp[])
{
	char *token = NULL, *s = ":", *path = NULL, *aux;
	struct stat st;

	if (argv_0[0] == '/')
	{
		if (stat(argv_0, &st) == 0)
		{
			*full_path = argv_0;
			return (0);
		}
		else
		{
			return (-1);
		}
	}
	else
	{
		aux = str_concat(get_value_env(envp, "PATH"), "");
		token = strtok(aux, s);
		while (token != NULL)
		{
			path = str_concat(token, "/");
			if (path == NULL)
			{
				free(aux);
				printf("ERRRORR en concat\n");
				return (-1);
			}
			*full_path = str_concat(path, argv_0);
			free(path);
			if (*full_path == NULL)
			{
				free(aux);
				printf("ERRRORR en concat\n");
				return (-1);
			}
			if (stat(*full_path, &st) == 0)
			{
				free(aux);
				return (1);
			}
			free(*full_path);
			token = strtok(NULL, s);
		}
		free(aux);
		return(-1);
	}
}
/**
 * sighandler - Function handle the signals
 * @signum: signal num
 */
void sighandler(int signum)
{
        printf("signal caputed: %d\n", signum);
}
