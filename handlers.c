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

	while(env[iterator])
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
	/* modify build path*/
	/*
	 - ok get the var _
	 - ok find the last /
	  ok copy all the path until the last /
	  ok pass copy to read
	  ok concat /help
	  ok concat name free
	   mised buscar con stat
	   missed manejar errores si no esta el help
	 ok  free new malloc
	 */
	char *p = NULL, *path = NULL, *full_path =  NULL;

		p =get_value_env(env, "_");
	int index = get_index_last_char(p, '/');
	printf("%s\n", p);
	printf("%d\n", index);
	p = str_copy_index(p, index - 1);
	path  = str_concat(p, "help/");
	printf("%s\n", p);
	free(p);
	if (argvs[1])
		full_path = str_concat(path, argvs[1]);
	else
		full_path = str_concat(path, argvs[0]);
	printf("%s\n", path);
	free(path);
	printf("%s\n", full_path);
	read_file(full_path);
	free(full_path);
}
