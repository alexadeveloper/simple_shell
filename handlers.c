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
		free(argvs);
		free(line);
		exit(status);
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
