#include "holberton.h"
/**
 * exit_handler - function exit correctly
 * @argvs: arguments with exit
 * @env: environment variables
 * @line: actual line intrduced by user
 * @status: status previus command
 */
void exit_handler(char **argvs, char **env, char *line, int status)
{
	(void)env;

	if (argvs[1] == NULL)
	{
		free(argvs);
		free(line);
		exit(status);
	}
	else
	{
		status = _atoi(argvs[1]);
		if (status > 0)
			exit(status);
		else
		{
			write(STDERR_FILENO, argvs[0], _strlen(argvs[0]));
			write(STDERR_FILENO, ": 1: exit: Illegal number: ", 27);
			write(STDERR_FILENO, argvs[1], _strlen(argvs[1]));
			write(STDERR_FILENO, "\n", 1);
		}
	}
}
/**
 * env_handler - function print env correctly
 * @argvs: arguments with exit
 * @env: environment variables
 * @line: actual line intrduced by user
 * @status: status previus command
 */
void env_handler(char **argvs, char **env, char *line, int status)
{
	int iterator = 0;
	(void)argvs;
	(void)line;
	(void)status;

	while (env[iterator])
	{
		write(STDOUT_FILENO, env[iterator], _strlen(env[iterator]));
		write(STDOUT_FILENO, "\n", 1);
		iterator++;
	}
}
/**
 * help_handler - function print hep builds correctly
 * @argvs: arguments with exit
 * @env: environment variables
 * @line: actual line intrduced by user
 * @status: status previus command
 */

void help_handler(char **argvs, char **env, char *line, int status)
{
	char *p = NULL, *path = NULL, *full_path =  NULL;
	int index = 0;
	struct stat st;
	(void) line;
	(void) status;

	p = get_value_env(env, "_");
	index = get_index_last_char(p, '/');
	p = str_copy_index(p, index - 1);
	path  = str_concat(p, "/help/");
	free(p);
	if (argvs[1])
		full_path = str_concat(path, argvs[1]);
	else
	{
		full_path = str_concat(path, argvs[0]);
	}
	if (stat(full_path, &st) == 0)
	{
		read_file(full_path);
	}
	else
	{
		free(full_path);
		full_path = str_concat(path, argvs[0]);
		read_file(full_path);
	}
	free(path);
	free(full_path);
}
